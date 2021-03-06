#include "drawing.h"
#include "xdrawinghelpers.h"
#include "xcairoenumhelpers.h"
#include <cstring>

using namespace std;
using namespace std::experimental::drawing;

image_surface::image_surface(image_surface&& other) : surface(move(other)) {
	_Data = move(other._Data);
	other._Data = nullptr;
}

image_surface& image_surface::operator=(image_surface&& other) {
	if (this != &other) {
		surface::operator=(move(other));
		_Data = move(other._Data);
		other._Data = nullptr;
	}
	return *this;
}

image_surface::image_surface(surface::native_handle_type nh, surface::native_handle_type map_of)
	: surface({ nullptr, nullptr })
	, _Data(nullptr) {
	_Surface = unique_ptr<cairo_surface_t, function<void(cairo_surface_t*)>>(nh.csfce, [map_of](cairo_surface_t *mapped_surface) { cairo_surface_unmap_image(map_of.csfce, mapped_surface); });
	_Context = unique_ptr<cairo_t, function<void(cairo_t*)>>(cairo_create(_Surface.get()), &cairo_destroy);
	_Throw_if_failed_status(_Cairo_status_t_to_status(cairo_surface_status(_Surface.get())));
	_Throw_if_failed_status(_Cairo_status_t_to_status(cairo_status(_Context.get())));
}

image_surface::image_surface(format format, int width, int height)
	: surface({ cairo_image_surface_create(_Format_to_cairo_format_t(format), width, height), nullptr })
	, _Data(nullptr) {
	_Throw_if_failed_status(_Cairo_status_t_to_status(cairo_surface_status(_Surface.get())));
	_Throw_if_failed_status(_Cairo_status_t_to_status(cairo_status(_Context.get())));
}

image_surface::image_surface(vector<unsigned char>& data, format format, int width, int height, int stride)
	: surface({ nullptr, nullptr })
	, _Data(new vector<unsigned char>) {
	assert(stride == format_stride_for_width(format, width));
	_Data->resize(height * stride);
	_Data->assign(begin(data), end(data));
	_Surface = unique_ptr<cairo_surface_t, function<void(cairo_surface_t*)>>(cairo_image_surface_create_for_data(_Data->data(), _Format_to_cairo_format_t(format), width, height, stride), &cairo_surface_destroy);
	_Throw_if_failed_status(_Cairo_status_t_to_status(cairo_surface_status(_Surface.get())));
	_Context = unique_ptr<cairo_t, function<void(cairo_t*)>>(cairo_create(_Surface.get()), &cairo_destroy);
	_Throw_if_failed_status(_Cairo_status_t_to_status(cairo_status(_Context.get())));
}

image_surface::image_surface(const surface& other, format format, int width, int height)
	: surface({ nullptr, nullptr })
	, _Data(nullptr) {
	_Surface = unique_ptr<cairo_surface_t, function<void(cairo_surface_t*)>>(cairo_surface_create_similar_image(other.native_handle().csfce, _Format_to_cairo_format_t(format), width, height), &cairo_surface_destroy);
	_Throw_if_failed_status(_Cairo_status_t_to_status(cairo_surface_status(_Surface.get())));
	_Context = unique_ptr<cairo_t, function<void(cairo_t*)>>(cairo_create(_Surface.get()), &cairo_destroy);
	_Throw_if_failed_status(_Cairo_status_t_to_status(cairo_status(_Context.get())));
}

image_surface::image_surface(const string& filename)
	: surface({ nullptr, nullptr })
	, _Data(nullptr) {
	_Surface = unique_ptr<cairo_surface_t, function<void(cairo_surface_t*)>>(cairo_image_surface_create_from_png(filename.c_str()), &cairo_surface_destroy);
	_Throw_if_failed_status(_Cairo_status_t_to_status(cairo_surface_status(_Surface.get())));
	_Context = unique_ptr<cairo_t, function<void(cairo_t*)>>(cairo_create(_Surface.get()), &cairo_destroy);
	_Throw_if_failed_status(_Cairo_status_t_to_status(cairo_status(_Context.get())));
}

void image_surface::set_data(vector<unsigned char>& data) {
	auto expected_size = static_cast<size_t>(get_stride() * get_height());
	if (data.size() != static_cast<uint64_t>(expected_size)) {
		throw drawing_exception(::std::experimental::drawing::status::invalid_stride);
	}
	if (_Surface.get() == nullptr) {
		throw drawing_exception(::std::experimental::drawing::status::null_pointer);
	}
	auto imageData = cairo_image_surface_get_data(_Surface.get());
	if (imageData == nullptr) {
		throw drawing_exception(::std::experimental::drawing::status::null_pointer);
	}
	::std::memcpy(imageData, data.data(), expected_size);
}

vector<unsigned char> image_surface::get_data() const {
	auto required_size = get_stride() * get_height();
	vector<unsigned char> data;
	auto imageData = cairo_image_surface_get_data(_Surface.get());
	if (imageData == nullptr) {
		data.clear();
	}
	else {
		data.assign(imageData, imageData + required_size);
	}
	return data;
}

format image_surface::get_format() const {
	return _Cairo_format_t_to_format(cairo_image_surface_get_format(_Surface.get()));
}

int image_surface::get_width() const {
	return cairo_image_surface_get_width(_Surface.get());
}

int image_surface::get_height() const {
	return cairo_image_surface_get_height(_Surface.get());
}

int image_surface::get_stride() const {
	return cairo_image_surface_get_stride(_Surface.get());
}
