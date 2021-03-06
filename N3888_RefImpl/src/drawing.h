#pragma once

#ifndef _DRAWING_
#define _DRAWING_

#include "xdrawing.h"

#include <memory>
#include <functional>
#include <exception>
#include <vector>
#include <string>
#include <algorithm>

#if defined(_MSC_VER) && (_MSC_VER <= 1800)
#define noexcept
#endif

namespace std {
	namespace experimental {
		namespace drawing {
#if (__cplusplus >= 201103L) || (_MSC_FULL_VER >= 190021510)
			inline namespace v1 {
#endif
				enum class status {
					success,
					no_memory,
					invalid_restore,
					invalid_pop_group,
					no_current_point,
					invalid_matrix,
					invalid_status,
					null_pointer,
					invalid_string,
					invalid_path_data,
					read_error,
					write_error,
					surface_finished,
					surface_type_mismatch,
					pattern_type_mismatch,
					invalid_content,
					invalid_format,
					invalid_visual,
					file_not_found,
					invalid_dash,
					invalid_dsc_comment,
					invalid_index,
					clip_not_representable,
					temp_file_error,
					invalid_stride,
					font_type_mismatch,
					user_font_immutable,
					user_font_error,
					negative_count,
					invalid_clusters,
					invalid_slant,
					invalid_weight,
					invalid_size,
					user_font_not_implemented,
					device_type_mismatch,
					device_error,
					invalid_mesh_construction,
					device_finished,
					last_status
				};

				enum class antialias {
					default_antialias,
					none,
					gray,
					subpixel,
					fast,
					good,
					best
				};

				enum class content {
					color,
					alpha,
					color_alpha
				};

				enum class fill_rule {
					winding,
					even_odd
				};

				enum class line_cap {
					butt,
					round,
					square
				};

				enum class line_join {
					miter,
					round,
					bevel
				};

				enum class compositing_operator {
					clear,
					source,
					over,
					in,
					out,
					atop,
					dest,
					dest_over,
					dest_in,
					dest_out,
					dest_atop,
					xor_compositing_operator,
					add,
					saturate,
					multiply,
					screen,
					overlay,
					darken,
					lighten,
					color_dodge,
					color_burn,
					hard_light,
					soft_light,
					difference,
					exclusion,
					hsl_hue,
					hsl_saturation,
					hsl_color,
					hsl_luminosity
				};

				enum class format {
					invalid,
					argb32,
					rgb24,
					a8,
					a1,
					rgb16_565,
					rgb30
				};

				enum class path_data_type {
					move_to,
					line_to,
					curve_to,
					new_sub_path,
					close_path
				};

				enum class extend {
					none,
					repeat,
					reflect,
					pad,
					default_extend = none
				};

				enum class filter {
					fast,
					good,
					best,
					nearest,
					bilinear,
					gaussian,
					default_filter = good
				};

				enum class pattern_type {
					solid_color,
					surface,
					linear,
					radial,
					mesh,
					raster_source
				};

				enum class font_slant {
					normal,
					italic,
					oblique
				};

				enum class font_weight {
					normal,
					bold
				};

				enum class subpixel_order {
					default_subpixel_order,
					rgb,
					bgr,
					vrgb,
					vbgr
				};

				enum class hint_style {
					default_hint_style,
					none,
					slight,
					medium,
					full
				};

				enum class hint_metrics {
					default_hint_metrics,
					off,
					on
				};

				namespace text_cluster_flags {
					enum text_cluster_flags : int {
						none = 0x0,
						backward = 0x1
					};
				};

				struct rectangle {
					double x;
					double y;
					double width;
					double height;
				};

				struct rgba_color {
					double r;
					double g;
					double b;
					double a;

					const static rgba_color alice_blue;
					const static rgba_color antique_white;
					const static rgba_color aqua;
					const static rgba_color aquamarine;
					const static rgba_color azure;
					const static rgba_color beige;
					const static rgba_color bisque;
					const static rgba_color black;
					const static rgba_color blanched_almond;
					const static rgba_color blue;
					const static rgba_color blue_violet;
					const static rgba_color brown;
					const static rgba_color burly_wood;
					const static rgba_color cadet_blue;
					const static rgba_color chartreuse;
					const static rgba_color chocolate;
					const static rgba_color coral;
					const static rgba_color cornflower_blue;
					const static rgba_color cornsilk;
					const static rgba_color crimson;
					const static rgba_color cyan;
					const static rgba_color dark_blue;
					const static rgba_color dark_cyan;
					const static rgba_color dark_goldenrod;
					const static rgba_color dark_gray;
					const static rgba_color dark_green;
					const static rgba_color dark_grey;
					const static rgba_color dark_khaki;
					const static rgba_color dark_magenta;
					const static rgba_color dark_olive_green;
					const static rgba_color dark_orange;
					const static rgba_color dark_orchid;
					const static rgba_color dark_red;
					const static rgba_color dark_salmon;
					const static rgba_color dark_sea_green;
					const static rgba_color dark_slate_blue;
					const static rgba_color dark_slate_gray;
					const static rgba_color dark_slate_grey;
					const static rgba_color dark_turquoise;
					const static rgba_color dark_violet;
					const static rgba_color deep_pink;
					const static rgba_color deep_sky_blue;
					const static rgba_color dim_gray;
					const static rgba_color dim_grey;
					const static rgba_color dodger_blue;
					const static rgba_color firebrick;
					const static rgba_color floral_white;
					const static rgba_color forest_green;
					const static rgba_color fuchsia;
					const static rgba_color gainsboro;
					const static rgba_color ghost_white;
					const static rgba_color gold;
					const static rgba_color goldenrod;
					const static rgba_color gray;
					const static rgba_color green;
					const static rgba_color green_yellow;
					const static rgba_color grey;
					const static rgba_color honeydew;
					const static rgba_color hot_pink;
					const static rgba_color indian_red;
					const static rgba_color indigo;
					const static rgba_color ivory;
					const static rgba_color khaki;
					const static rgba_color lavender;
					const static rgba_color lavender_blush;
					const static rgba_color lawn_green;
					const static rgba_color lemon_chiffon;
					const static rgba_color light_blue;
					const static rgba_color light_coral;
					const static rgba_color light_cyan;
					const static rgba_color light_goldenrod_yellow;
					const static rgba_color light_gray;
					const static rgba_color light_green;
					const static rgba_color light_grey;
					const static rgba_color light_pink;
					const static rgba_color light_salmon;
					const static rgba_color light_sea_green;
					const static rgba_color light_sky_blue;
					const static rgba_color light_slate_gray;
					const static rgba_color light_slate_grey;
					const static rgba_color light_steel_blue;
					const static rgba_color light_yellow;
					const static rgba_color lime;
					const static rgba_color lime_green;
					const static rgba_color linen;
					const static rgba_color magenta;
					const static rgba_color maroon;
					const static rgba_color medium_aquamarine;
					const static rgba_color medium_blue;
					const static rgba_color medium_orchid;
					const static rgba_color medium_purple;
					const static rgba_color medium_sea_green;
					const static rgba_color medium_slate_blue;
					const static rgba_color medium_spring_green;
					const static rgba_color medium_turquoise;
					const static rgba_color medium_violet_red;
					const static rgba_color midnight_blue;
					const static rgba_color mint_cream;
					const static rgba_color misty_rose;
					const static rgba_color moccasin;
					const static rgba_color navajo_white;
					const static rgba_color navy;
					const static rgba_color old_lace;
					const static rgba_color olive;
					const static rgba_color olive_drab;
					const static rgba_color orange;
					const static rgba_color orange_red;
					const static rgba_color orchid;
					const static rgba_color pale_goldenrod;
					const static rgba_color pale_green;
					const static rgba_color pale_turquoise;
					const static rgba_color pale_violet_red;
					const static rgba_color papaya_whip;
					const static rgba_color peach_puff;
					const static rgba_color peru;
					const static rgba_color pink;
					const static rgba_color plum;
					const static rgba_color powder_blue;
					const static rgba_color purple;
					const static rgba_color red;
					const static rgba_color rosy_brown;
					const static rgba_color royal_blue;
					const static rgba_color saddle_brown;
					const static rgba_color salmon;
					const static rgba_color sandy_brown;
					const static rgba_color sea_green;
					const static rgba_color sea_shell;
					const static rgba_color sienna;
					const static rgba_color silver;
					const static rgba_color sky_blue;
					const static rgba_color slate_blue;
					const static rgba_color slate_gray;
					const static rgba_color slate_grey;
					const static rgba_color snow;
					const static rgba_color spring_green;
					const static rgba_color steel_blue;
					const static rgba_color tan;
					const static rgba_color teal;
					const static rgba_color thistle;
					const static rgba_color tomato;
					const static rgba_color turquoise;
					const static rgba_color violet;
					const static rgba_color wheat;
					const static rgba_color white;
					const static rgba_color white_smoke;
					const static rgba_color yellow;
					const static rgba_color yellow_green;
				};

#if (__cplusplus >= 201103L) || (_MSC_FULL_VER >= 190021510)
				inline namespace literals {
					inline double operator""_ubyte(unsigned long long value) {
						return ::std::max(0.0, ::std::min(1.0, static_cast<double>(value) / 255.0));
					}

					inline double operator "" _unorm(long double value) {
						auto result = ::std::max(0.0, ::std::min(1.0, static_cast<double>(value)));
						result = ::std::nearbyint(result * 255.0); // We need to ensure it is one of the discrete values between 0 and 255.
						return result / 255.0;
					}
				}
#endif
				struct point {
					double x;
					double y;

					point operator+=(const point& rhs);
					point operator+=(double rhs);
					point operator-=(const point& rhs);
					point operator-=(double rhs);
					point operator*=(const point& rhs);
					point operator*=(double rhs);
					point operator/=(const point& rhs);
					point operator/=(double rhs);
				};

				point operator+(const point& lhs);
				point operator+(const point& lhs, const point& rhs);
				point operator+(const point& lhs, double rhs);
				point operator-(const point& lhs);
				point operator-(const point& lhs, const point& rhs);
				point operator-(const point& lhs, double rhs);
				point operator*(const point& lhs, const point& rhs);
				point operator*(const point& lhs, double rhs);
				point operator/(const point& lhs, const point& rhs);
				point operator/(const point& lhs, double rhs);

				struct glyph {
					unsigned long index;
					double x;
					double y;
				};

				struct text_cluster {
					int num_bytes;
					int num_glyphs;
				};

				struct font_extents {
					double ascent;
					double descent;
					double height;
					double max_x_advance;
					double max_y_advance;
				};

				struct text_extents {
					double x_bearing;
					double y_bearing;
					double width;
					double height;
					double x_advance;
					double y_advance;
				};

				struct matrix_2d {
					double xx;
					double yx;
					double xy;
					double yy;
					double x0;
					double y0;

					static matrix_2d init_identity();
					static matrix_2d init_translate(const point& value);
					static matrix_2d init_scale(const point& value);
					static matrix_2d init_rotate(double radians);
					static matrix_2d init_shear_x(double factor);
					static matrix_2d init_shear_y(double factor);

					matrix_2d& translate(const point& value);
					matrix_2d& scale(const point& value);
					matrix_2d& rotate(double radians);
					matrix_2d& shear_x(double factor);
					matrix_2d& shear_y(double factor);
					double determinant() const;
					void invert();
					point transform_distance(const point& dist) const;
					point transform_point(const point& pt) const;

					matrix_2d operator*=(const matrix_2d& rhs);
				};

				matrix_2d operator*(const matrix_2d& lhs, const matrix_2d& rhs);

				union path_data
				{
					struct {
						path_data_type type;
						int length;
					} header;
					point pt;
				};

				// Forward declaration.
				class path_builder;

				class path {
					friend class path_builder;
					::std::vector<path_data> _Data;
					bool _Has_current_point;
					point _Current_point;
					rectangle _Extents;
				public:
					typedef cairo_path_t* native_handle_type;

					path() = delete;
					path(const path_builder& pb);
					path(const path& other) = default;
					path& operator=(const path& other) = default;
					path(path&& other);
					path& operator=(path&& other);

					::std::vector<path_data> get_data() const;
					const ::std::vector<path_data>& get_data_ref() const;
					rectangle get_path_extents() const;
				};

				class path_builder {
					friend class path;
					::std::vector<path_data> _Data;
					bool _Has_current_point;
					point _Current_point;
					point _Extents_pt0;
					point _Extents_pt1;
					matrix_2d _Transform_matrix;
					point _Origin;

				public:
					path_builder();
					path_builder(const path_builder& other) = default;
					path_builder& operator=(const path_builder& other) = default;
					path_builder(path_builder&& other);
					path_builder& operator=(path_builder&& other);

					path get_path() const;
					path get_path_flat() const;
					rectangle get_path_extents() const;

					void append_path(const path& p);
					void append_path(const path_builder& p);
					bool has_current_point();
					point get_current_point();
					void new_sub_path();
					void close_path();
					void arc(const point& center, double radius, double angle1, double angle2);
					void arc_negative(const point& center, double radius, double angle1, double angle2);
					void curve_to(const point& pt0, const point& pt1, const point& pt2);
					void line_to(const point& pt);
					void move_to(const point& pt);
					void rect(const rectangle& r);
					void rel_curve_to(const point& dpt0, const point& dpt1, const point& dpt2);
					void rel_line_to(const point& dpt);
					void rel_move_to(const point& dpt);

					void set_transform_matrix(const matrix_2d& m);
					matrix_2d get_transform_matrix() const;
					void set_origin(const point& pt);
					point get_origin() const;

					::std::vector<path_data> get_data() const;
					const ::std::vector<path_data>& get_data_ref() const;
					::std::vector<path_data>& get_data_ref();

					void reset();
				};

				class drawing_exception : public exception {
					status _Status = status::last_status;
				public:
					drawing_exception() noexcept;
					explicit drawing_exception(status s) noexcept;

					virtual ~drawing_exception() noexcept;

					drawing_exception(const drawing_exception& rhs) = default;
					drawing_exception& operator=(const drawing_exception& rhs) = default;

					virtual const char* what() const noexcept;
					status get_status() const noexcept;
				};

				class device {
				protected:
					::std::shared_ptr<cairo_device_t> _Device;
				public:
					typedef cairo_device_t* native_handle_type;
					native_handle_type native_handle() const;

					device() = delete;
					device(const device&) = delete;
					device& operator=(const device&) = delete;
					device(device&& other);
					device& operator=(device&& other);
					explicit device(native_handle_type nh);
					void flush();
					void acquire();
					void release();
				};

				// Forward declaration.
				class font_options;

				class font_options_builder {
					antialias _Antialias = antialias::default_antialias;
					subpixel_order _Subpixel_order = subpixel_order::default_subpixel_order;
					hint_style _Hint_style = hint_style::default_hint_style;
					hint_metrics _Hint_metrics = hint_metrics::default_hint_metrics;

				public:
					font_options_builder() = default;
					font_options_builder(const font_options_builder&) = default;
					font_options_builder& operator=(const font_options_builder&) = default;
					font_options_builder(font_options_builder&& other);
					font_options_builder& operator=(font_options_builder&& other);

					font_options get_font_options() const;
					void set_antialias(antialias a);
					antialias get_antialias() const;
					void set_subpixel_order(subpixel_order so);
					subpixel_order get_subpixel_order() const;
					void set_hint_style(hint_style hs);
					hint_style get_hint_style() const;
					void set_hint_metrics(hint_metrics hm);
					hint_metrics get_hint_metrics() const;
				};

				class font_options {
					::std::shared_ptr<cairo_font_options_t> _Font_options;
				public:
					typedef cairo_font_options_t* native_handle_type;
					native_handle_type native_handle() const;

					font_options() = delete;
					font_options(const font_options&) = default;
					font_options& operator=(const font_options&) = default;
					font_options(font_options&& other);
					font_options& operator=(font_options&& other);
					font_options(antialias a, subpixel_order so, hint_style hs, hint_metrics hm);
					explicit font_options(native_handle_type nh);

					antialias get_antialias() const;
					subpixel_order get_subpixel_order() const;
					hint_style get_hint_style() const;
					hint_metrics get_hint_metrics() const;
				};

				class font_face {
				protected:
					::std::shared_ptr<cairo_font_face_t> _Font_face;
				public:
					typedef cairo_font_face_t* native_handle_type;
					native_handle_type native_handle() const;

					font_face() = delete;
					font_face(const font_face&) = default;
					font_face& operator=(const font_face&) = default;
					font_face(font_face&& other);
					font_face& operator=(font_face&& other);

					explicit font_face(native_handle_type nh);

					virtual ~font_face();
				};

				class scaled_font {
					::std::shared_ptr<cairo_scaled_font_t> _Scaled_font;

				public:
					typedef cairo_scaled_font_t* native_handle_type;
					native_handle_type native_handle() const;

					scaled_font() = delete;
					scaled_font(const scaled_font&) = default;
					scaled_font& operator=(const scaled_font&) = default;
					scaled_font(scaled_font&& other);
					scaled_font& operator=(scaled_font&& other);

					explicit scaled_font(native_handle_type nh);
					scaled_font(const font_face& ff, const matrix_2d& fm, const matrix_2d& ctm, const font_options& fo);

					font_extents get_extents() const;
					text_extents get_text_extents(const ::std::string& utf8) const;
					text_extents get_glyph_extents(const ::std::vector<glyph>& glyphs) const;
					::std::vector<glyph> text_to_glyphs(double x, double y, const ::std::string& utf8) const;
					::std::vector<glyph> text_to_glyphs(double x, double y, const ::std::string& utf8, ::std::vector<text_cluster>& clusters, text_cluster_flags::text_cluster_flags& clFlags) const;
				};

				class toy_font_face : public font_face {
				public:
					toy_font_face() = delete;
					toy_font_face(const toy_font_face&) = default;
					toy_font_face& operator=(const toy_font_face&) = default;
					toy_font_face(const ::std::string& family, font_slant slant, font_weight weight);
					toy_font_face(toy_font_face&& other);
					toy_font_face& operator=(toy_font_face&& other);

					::std::string get_family() const;
					font_slant get_slant() const;
					font_weight get_weight() const;
				};

				// Forward declaration.
				class image_surface;

				// Forward declaration.
				class linear_pattern_builder;
				class mesh_pattern_builder;
				class radial_pattern_builder;
				class raster_source_pattern_builder;
				class solid_color_pattern_builder;
				class surface;

				class pattern {
				public:
					typedef cairo_pattern_t* native_handle_type;

				private:
					friend class linear_pattern_builder;
					friend class mesh_pattern_builder;
					friend class radial_pattern_builder;
					friend class raster_source_pattern_builder;
					friend class solid_color_pattern_builder;
					friend class surface;

					pattern(native_handle_type nh);

					cairo_pattern_t* _Pattern;
					pattern_type _Pattern_type;

				public:
					native_handle_type native_handle() const;

					pattern() = delete;
					pattern(const pattern&) = default;
					pattern& operator=(const pattern&) = default;
					pattern(pattern&& other);
					pattern& operator=(pattern&& other);

					~pattern();

					pattern_type get_type() const;
				};

				class solid_color_pattern_builder {
					pattern_type _Pattern_type;
					extend _Extend;
					filter _Filter;
					matrix_2d _Matrix;
					rgba_color _Color;

				public:
					solid_color_pattern_builder(const solid_color_pattern_builder&) = default;
					solid_color_pattern_builder& operator=(const solid_color_pattern_builder&) = default;
					solid_color_pattern_builder(solid_color_pattern_builder&& other);
					solid_color_pattern_builder& operator=(solid_color_pattern_builder&& other);
					solid_color_pattern_builder(const rgba_color& color);

					pattern get_pattern();
					void set_extend(extend e);
					extend get_extend();
					void set_filter(filter f);
					filter get_filter();
					void set_matrix(const matrix_2d& m);
					matrix_2d get_matrix();

					rgba_color get_rgba();
					void set_rgba(const rgba_color& color);
					double get_red();
					void set_red(double red);
					double get_green();
					void set_green(double green);
					double get_blue();
					void set_blue(double blue);
					double get_alpha();
					void set_alpha(double alpha);
				};

				class linear_pattern_builder {
					pattern_type _Pattern_type;
					extend _Extend;
					filter _Filter;
					matrix_2d _Matrix;

					point _Point0;
					point _Point1;
					::std::vector<::std::tuple<double, rgba_color>> _Color_stops;

				public:
					linear_pattern_builder() = delete;
					linear_pattern_builder(const linear_pattern_builder&) = default;
					linear_pattern_builder& operator=(const linear_pattern_builder&) = default;
					linear_pattern_builder(linear_pattern_builder&& other);
					linear_pattern_builder& operator=(linear_pattern_builder&& other);
					linear_pattern_builder(const point& pt0, const point& pt1);

					pattern get_pattern();
					void set_extend(extend extend);
					extend get_extend();
					void set_filter(filter filter);
					filter get_filter();
					void set_matrix(const matrix_2d& matrix);
					matrix_2d get_matrix();

					void add_color_stop_rgba(double offset, const rgba_color& color);
					int get_color_stop_count();

					void get_color_stop_rgba(unsigned int index, double& offset, rgba_color& color);
					void set_color_stop_rgba(unsigned int index, double offset, const rgba_color& color);
					void get_linear_points(point& pt0, point& pt1);
					void set_linear_points(const point& pt0, const point& pt1);
				};

				class radial_pattern_builder {
					pattern_type _Pattern_type;
					extend _Extend;
					filter _Filter;
					matrix_2d _Matrix;

					point _Center0;
					double _Radius0;
					point _Center1;
					double _Radius1;
					::std::vector<::std::tuple<double, rgba_color>> _Color_stops;

				public:
					radial_pattern_builder() = delete;
					radial_pattern_builder(const radial_pattern_builder&) = default;
					radial_pattern_builder& operator=(const radial_pattern_builder&) = default;
					radial_pattern_builder(radial_pattern_builder&& other);
					radial_pattern_builder& operator=(radial_pattern_builder&& other);
					radial_pattern_builder(const point& center0, double radius0, const point& center1, double radius1);

					pattern get_pattern();
					void set_extend(extend extend);
					extend get_extend();
					void set_filter(filter filter);
					filter get_filter();
					void set_matrix(const matrix_2d& matrix);
					matrix_2d get_matrix();

					void add_color_stop_rgba(double offset, const rgba_color& color);
					int get_color_stop_count();

					void get_color_stop_rgba(unsigned int index, double& offset, rgba_color& color);
					void set_color_stop_rgba(unsigned int index, double offset, const rgba_color& color);

					void get_radial_circles(point& center0, double& radius0, point& center1, double& radius1);
					void set_radial_circles(const point& center0, double radius0, const point& center1, double radius1);
				};

				class mesh_pattern_builder {
					pattern_type _Pattern_type;
					extend _Extend;
					filter _Filter;
					matrix_2d _Matrix;

					bool _Has_current_patch;
					unsigned int _Current_patch_index;
					int _Current_patch_side_count;
					point _Current_patch_initial_point;
					typedef ::std::map<unsigned int, point> _Control_points;
					typedef ::std::map<unsigned int, rgba_color> _Corner_colors;
					// <Patch data, control points, corner colors>
					typedef ::std::tuple<path_builder, _Control_points, _Corner_colors> _Patch;
					::std::vector<_Patch> _Patches;
				public:
					mesh_pattern_builder();
					mesh_pattern_builder(const mesh_pattern_builder&) = default;
					mesh_pattern_builder& operator=(const mesh_pattern_builder&) = default;
					mesh_pattern_builder(mesh_pattern_builder&& other);
					mesh_pattern_builder& operator=(mesh_pattern_builder&& other);

					pattern get_pattern();
					void set_extend(extend extend);
					extend get_extend();
					void set_filter(filter filter);
					filter get_filter();
					void set_matrix(const matrix_2d& matrix);
					matrix_2d get_matrix();

					void begin_patch();
					void begin_edit_patch(unsigned int patch_num);
					void end_patch();
					void move_to(const point& pt);
					void line_to(const point& pt);
					void curve_to(const point& pt0, const point& pt1, const point& pt2);
					void set_control_point(unsigned int point_num, const point& pt);
					void set_corner_color_rgba(unsigned int corner_num, const rgba_color& color);
					void get_patch_count(unsigned int& count);
					path get_path(unsigned int patch_num);
					path_builder get_path_builder(unsigned int patch_num);
					point get_control_point(unsigned int patch_num, unsigned int point_num);
					rgba_color get_corner_color_rgba(unsigned int patch_num, unsigned int corner_num);
				};

				class raster_source_pattern_builder {
					pattern_type _Pattern_type;
					extend _Extend;
					filter _Filter;
					matrix_2d _Matrix;

					void* _User_callback_data;
					int _Width;
					int _Height;
					content _Content;
					::std::shared_ptr<::std::function<surface(void* callback_data, surface& target, const rectangle& extents)>> _Acquire_fn;
					::std::shared_ptr<::std::function<void(void* callback_data, surface& surface)>> _Release_fn;

					static cairo_surface_t* _Cairo_acquire(cairo_pattern_t* pattern_builder, void* this_ptr, cairo_surface_t* target, const cairo_rectangle_int_t* extents);
					static void _Cairo_release(cairo_pattern_t* pattern_builder, void* this_ptr, cairo_surface_t* surface);

				public:
					raster_source_pattern_builder() = delete;
					raster_source_pattern_builder(const raster_source_pattern_builder&) = default;
					raster_source_pattern_builder& operator=(const raster_source_pattern_builder&) = default;
					raster_source_pattern_builder(raster_source_pattern_builder&& other);
					raster_source_pattern_builder& operator=(raster_source_pattern_builder&& other);
					raster_source_pattern_builder(void* user_data, content content, int width, int height);

					pattern get_pattern();
					void set_extend(extend extend);
					extend get_extend();
					void set_filter(filter filter);
					filter get_filter();
					void set_matrix(const matrix_2d& matrix);
					matrix_2d get_matrix();

					void set_callback_data(void* data);
					void* get_callback_data();
					void set_acquire(
						::std::function<surface(void* callback_data, surface& target, const rectangle& extents)> acquire_fn,
						::std::function<void(void* callback_data, surface& surface)> release_fn
						);
					void get_acquire(
						::std::function<surface(void* callback_data, surface& target, const rectangle& extents)>& acquire_fn,
						::std::function<void(void* callback_data, surface& surface)>& release_fn
						);
				};

				struct _Surface_native_handles {
					::cairo_surface_t* csfce;
					::cairo_t* cctxt;
				};

				class surface {
					::std::mutex _Lock_for_device;
					::std::weak_ptr<device> _Device;
				protected:
					::std::unique_ptr<cairo_surface_t, ::std::function<void(cairo_surface_t*)>> _Surface;
					::std::unique_ptr<cairo_t, ::std::function<void(cairo_t*)>> _Context;

				public:
					surface() = delete;

					typedef _Surface_native_handles native_handle_type;
					native_handle_type native_handle() const;

					surface(const surface&) = delete;
					surface& operator=(const surface&) = delete;

					surface(surface&& other);
					surface& operator=(surface&& other);

					explicit surface(native_handle_type nh);

					surface(format fmt, int width, int height);
					// create_similar
					surface(const surface& other, content content, int width, int height);
					// create_for_rectangle
					surface(const surface& target, const rectangle& rect);

					virtual ~surface();

					void finish();
					void flush();

					::std::shared_ptr<device> get_device();

					content get_content() const;
					void mark_dirty();
					void mark_dirty_rectangle(const rectangle& rect);

					void set_device_offset(const point& offset);
					point get_device_offset() const;
					void write_to_png(const ::std::string& filename);
					image_surface map_to_image(const rectangle& extents);
					void unmap_image(image_surface& image);
					bool has_surface_resource() const;

					void save();
					void restore();
					void push_group();
					void push_group_with_content(content c);
					surface pop_group();
					void pop_group_to_source();

					void set_pattern();
					void set_pattern(const pattern& source);
					pattern get_pattern() const;

					void set_antialias(antialias a);
					antialias get_antialias() const;

					// tuple<dashes, offset>
					typedef ::std::tuple<::std::vector<double>, double> dashes;

					void set_dashes();
					void set_dashes(const dashes& d);
					int get_dashes_count() const;
					dashes get_dashes() const;

					void set_fill_rule(fill_rule fr);
					fill_rule get_fill_rule() const;

					void set_line_cap(line_cap lc);
					line_cap get_line_cap() const;

					void set_line_join(line_join lj);
					line_join get_line_join() const;

					void set_line_width(double width);
					double get_line_width() const;

					void set_miter_limit(double limit);
					double get_miter_limit() const;

					void set_compositing_operator(compositing_operator co);
					compositing_operator get_compositing_operator() const;

					void set_tolerance(double tolerance);
					double get_tolerance() const;

					void clip();
					rectangle get_clip_extents() const;
					bool in_clip(const point& pt) const;
					void reset_clip();

					::std::vector<rectangle> copy_clip_rectangle_list() const;

					void fill();
					void fill(const surface& s);
					rectangle get_fill_extents() const;
					bool in_fill(const point& pt) const;

					void mask(const pattern& pttn);
					void mask(const surface& surface);
					void mask(const surface& surface, const point& origin);

					void paint();
					void paint(const surface& s);
					void paint_with_alpha(double alpha);
					void paint_with_alpha(const surface& s, double alpha);

					void stroke();
					void stroke(const surface& s);
					rectangle get_stroke_extents() const;
					bool in_stroke(const point& pt) const;

					void set_path();
					void set_path(const path& p);

					// Transformations
					void set_matrix(const matrix_2d& matrix);
					matrix_2d get_matrix() const;
					point user_to_device() const;
					point user_to_device_distance() const;
					point device_to_user() const;
					point device_to_user_distance() const;

					// Text
					void select_font_face(const ::std::string& family, font_slant slant, font_weight weight);
					void set_font_size(double size);
					void set_font_matrix(const matrix_2d& matrix);
					matrix_2d get_font_matrix() const;
					void set_font_options(const font_options& options);
					font_options get_font_options() const;
					void set_font_face(const font_face& font_face);
					font_face get_font_face() const;
					void set_scaled_font(const scaled_font& scaled_font);
					scaled_font get_scaled_font() const;
					void show_text(const ::std::string& utf8);
					void show_glyphs(const ::std::vector<glyph>& glyphs);
					void show_text_glyphs(const ::std::string& utf8, const ::std::vector<glyph>& glyphs, const ::std::vector<text_cluster>& clusters, text_cluster_flags::text_cluster_flags cluster_flags);
					font_extents get_font_extents() const;
					text_extents get_text_extents(const ::std::string& utf8) const;
					text_extents get_glyph_extents(const ::std::vector<glyph>& glyphs) const;
				};

				class image_surface : public surface {
					friend surface;
				protected:
					::std::shared_ptr<::std::vector<unsigned char>> _Data;
				public:
					image_surface() = delete;
					image_surface(const image_surface&) = delete;
					image_surface& operator=(const image_surface&) = delete;
					image_surface(image_surface&& other);
					image_surface& operator=(image_surface&& other);
					image_surface(surface::native_handle_type nh, surface::native_handle_type map_of);
					image_surface(format format, int width, int height);
					image_surface(vector<unsigned char>& data, format format, int width, int height, int stride);
					// create_similar_image
					image_surface(const surface& other, format format, int width, int height);
					// create_from_png
					image_surface(const ::std::string& filename);

					void set_data(::std::vector<unsigned char>& data);
					::std::vector<unsigned char> get_data() const;
					format get_format() const;
					int get_width() const;
					int get_height() const;
					int get_stride() const;
				};

				int format_stride_for_width(format format, int width);
				surface make_surface(surface::native_handle_type nh); // parameters are exposition only.
				surface make_surface(format format, int width, int height); // parameters are exposition only.
#if (__cplusplus >= 201103L) || (_MSC_FULL_VER >= 190021510) 
			}
#endif
		}
	}
}

#endif
