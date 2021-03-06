#include "drawing.h"
#include "xdrawinghelpers.h"
#include "xcairoenumhelpers.h"

using namespace std;
using namespace std::experimental::drawing;

rgba_color _Rgba_color_from_byte_values(unsigned char r, unsigned char g, unsigned char b, unsigned char a = static_cast<unsigned char>(255)) {
	return{ static_cast<double>(r) / 255.0, static_cast<double>(g) / 255.0, static_cast<double>(b) / 255.0, static_cast<double>(a) / 255.0 };
}

const rgba_color rgba_color::alice_blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(240), static_cast<unsigned char>(248), static_cast<unsigned char>(255));
const rgba_color rgba_color::antique_white = _Rgba_color_from_byte_values(static_cast<unsigned char>(250), static_cast<unsigned char>(235), static_cast<unsigned char>(215));
const rgba_color rgba_color::aqua = _Rgba_color_from_byte_values(static_cast<unsigned char>(0), static_cast<unsigned char>(255), static_cast<unsigned char>(255));
const rgba_color rgba_color::aquamarine = _Rgba_color_from_byte_values(static_cast<unsigned char>(127), static_cast<unsigned char>(255), static_cast<unsigned char>(212));
const rgba_color rgba_color::azure = _Rgba_color_from_byte_values(static_cast<unsigned char>(240), static_cast<unsigned char>(255), static_cast<unsigned char>(255));
const rgba_color rgba_color::beige = _Rgba_color_from_byte_values(static_cast<unsigned char>(245), static_cast<unsigned char>(245), static_cast<unsigned char>(220));
const rgba_color rgba_color::bisque = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(228), static_cast<unsigned char>(196));
const rgba_color rgba_color::black = _Rgba_color_from_byte_values(static_cast<unsigned char>(0), static_cast<unsigned char>(0), static_cast<unsigned char>(0));
const rgba_color rgba_color::blanched_almond = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(235), static_cast<unsigned char>(205));
const rgba_color rgba_color::blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(0), static_cast<unsigned char>(0), static_cast<unsigned char>(255));
const rgba_color rgba_color::blue_violet = _Rgba_color_from_byte_values(static_cast<unsigned char>(138), static_cast<unsigned char>(43), static_cast<unsigned char>(226));
const rgba_color rgba_color::brown = _Rgba_color_from_byte_values(static_cast<unsigned char>(165), static_cast<unsigned char>(42), static_cast<unsigned char>(42));
const rgba_color rgba_color::burly_wood = _Rgba_color_from_byte_values(static_cast<unsigned char>(222), static_cast<unsigned char>(184), static_cast<unsigned char>(135));
const rgba_color rgba_color::cadet_blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(95), static_cast<unsigned char>(158), static_cast<unsigned char>(160));
const rgba_color rgba_color::chartreuse = _Rgba_color_from_byte_values(static_cast<unsigned char>(127), static_cast<unsigned char>(255), static_cast<unsigned char>(0));
const rgba_color rgba_color::chocolate = _Rgba_color_from_byte_values(static_cast<unsigned char>(210), static_cast<unsigned char>(105), static_cast<unsigned char>(30));
const rgba_color rgba_color::coral = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(127), static_cast<unsigned char>(80));
const rgba_color rgba_color::cornflower_blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(100), static_cast<unsigned char>(149), static_cast<unsigned char>(237));
const rgba_color rgba_color::cornsilk = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(248), static_cast<unsigned char>(220));
const rgba_color rgba_color::crimson = _Rgba_color_from_byte_values(static_cast<unsigned char>(220), static_cast<unsigned char>(20), static_cast<unsigned char>(60));
const rgba_color rgba_color::cyan = _Rgba_color_from_byte_values(static_cast<unsigned char>(0), static_cast<unsigned char>(255), static_cast<unsigned char>(255));
const rgba_color rgba_color::dark_blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(0), static_cast<unsigned char>(0), static_cast<unsigned char>(139));
const rgba_color rgba_color::dark_cyan = _Rgba_color_from_byte_values(static_cast<unsigned char>(0), static_cast<unsigned char>(139), static_cast<unsigned char>(139));
const rgba_color rgba_color::dark_goldenrod = _Rgba_color_from_byte_values(static_cast<unsigned char>(184), static_cast<unsigned char>(134), static_cast<unsigned char>(11));
const rgba_color rgba_color::dark_gray = _Rgba_color_from_byte_values(static_cast<unsigned char>(169), static_cast<unsigned char>(169), static_cast<unsigned char>(169));
const rgba_color rgba_color::dark_green = _Rgba_color_from_byte_values(static_cast<unsigned char>(0), static_cast<unsigned char>(100), static_cast<unsigned char>(0));
const rgba_color rgba_color::dark_grey = _Rgba_color_from_byte_values(static_cast<unsigned char>(169), static_cast<unsigned char>(169), static_cast<unsigned char>(169));
const rgba_color rgba_color::dark_khaki = _Rgba_color_from_byte_values(static_cast<unsigned char>(189), static_cast<unsigned char>(183), static_cast<unsigned char>(107));
const rgba_color rgba_color::dark_magenta = _Rgba_color_from_byte_values(static_cast<unsigned char>(139), static_cast<unsigned char>(0), static_cast<unsigned char>(139));
const rgba_color rgba_color::dark_olive_green = _Rgba_color_from_byte_values(static_cast<unsigned char>(85), static_cast<unsigned char>(107), static_cast<unsigned char>(47));
const rgba_color rgba_color::dark_orange = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(140), static_cast<unsigned char>(0));
const rgba_color rgba_color::dark_orchid = _Rgba_color_from_byte_values(static_cast<unsigned char>(153), static_cast<unsigned char>(50), static_cast<unsigned char>(204));
const rgba_color rgba_color::dark_red = _Rgba_color_from_byte_values(static_cast<unsigned char>(139), static_cast<unsigned char>(0), static_cast<unsigned char>(0));
const rgba_color rgba_color::dark_salmon = _Rgba_color_from_byte_values(static_cast<unsigned char>(233), static_cast<unsigned char>(150), static_cast<unsigned char>(122));
const rgba_color rgba_color::dark_sea_green = _Rgba_color_from_byte_values(static_cast<unsigned char>(143), static_cast<unsigned char>(188), static_cast<unsigned char>(143));
const rgba_color rgba_color::dark_slate_blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(72), static_cast<unsigned char>(61), static_cast<unsigned char>(139));
const rgba_color rgba_color::dark_slate_gray = _Rgba_color_from_byte_values(static_cast<unsigned char>(47), static_cast<unsigned char>(79), static_cast<unsigned char>(79));
const rgba_color rgba_color::dark_slate_grey = _Rgba_color_from_byte_values(static_cast<unsigned char>(47), static_cast<unsigned char>(79), static_cast<unsigned char>(79));
const rgba_color rgba_color::dark_turquoise = _Rgba_color_from_byte_values(static_cast<unsigned char>(0), static_cast<unsigned char>(206), static_cast<unsigned char>(209));
const rgba_color rgba_color::dark_violet = _Rgba_color_from_byte_values(static_cast<unsigned char>(148), static_cast<unsigned char>(0), static_cast<unsigned char>(211));
const rgba_color rgba_color::deep_pink = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(20), static_cast<unsigned char>(147));
const rgba_color rgba_color::deep_sky_blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(0), static_cast<unsigned char>(191), static_cast<unsigned char>(255));
const rgba_color rgba_color::dim_gray = _Rgba_color_from_byte_values(static_cast<unsigned char>(105), static_cast<unsigned char>(105), static_cast<unsigned char>(105));
const rgba_color rgba_color::dim_grey = _Rgba_color_from_byte_values(static_cast<unsigned char>(105), static_cast<unsigned char>(105), static_cast<unsigned char>(105));
const rgba_color rgba_color::dodger_blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(30), static_cast<unsigned char>(144), static_cast<unsigned char>(255));
const rgba_color rgba_color::firebrick = _Rgba_color_from_byte_values(static_cast<unsigned char>(178), static_cast<unsigned char>(34), static_cast<unsigned char>(34));
const rgba_color rgba_color::floral_white = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(250), static_cast<unsigned char>(240));
const rgba_color rgba_color::forest_green = _Rgba_color_from_byte_values(static_cast<unsigned char>(34), static_cast<unsigned char>(139), static_cast<unsigned char>(34));
const rgba_color rgba_color::fuchsia = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(0), static_cast<unsigned char>(255));
const rgba_color rgba_color::gainsboro = _Rgba_color_from_byte_values(static_cast<unsigned char>(220), static_cast<unsigned char>(220), static_cast<unsigned char>(220));
const rgba_color rgba_color::ghost_white = _Rgba_color_from_byte_values(static_cast<unsigned char>(248), static_cast<unsigned char>(248), static_cast<unsigned char>(255));
const rgba_color rgba_color::gold = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(215), static_cast<unsigned char>(0));
const rgba_color rgba_color::goldenrod = _Rgba_color_from_byte_values(static_cast<unsigned char>(218), static_cast<unsigned char>(165), static_cast<unsigned char>(32));
const rgba_color rgba_color::gray = _Rgba_color_from_byte_values(static_cast<unsigned char>(128), static_cast<unsigned char>(128), static_cast<unsigned char>(128));
const rgba_color rgba_color::green = _Rgba_color_from_byte_values(static_cast<unsigned char>(0), static_cast<unsigned char>(128), static_cast<unsigned char>(0));
const rgba_color rgba_color::green_yellow = _Rgba_color_from_byte_values(static_cast<unsigned char>(173), static_cast<unsigned char>(255), static_cast<unsigned char>(47));
const rgba_color rgba_color::grey = _Rgba_color_from_byte_values(static_cast<unsigned char>(128), static_cast<unsigned char>(128), static_cast<unsigned char>(128));
const rgba_color rgba_color::honeydew = _Rgba_color_from_byte_values(static_cast<unsigned char>(240), static_cast<unsigned char>(255), static_cast<unsigned char>(240));
const rgba_color rgba_color::hot_pink = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(105), static_cast<unsigned char>(180));
const rgba_color rgba_color::indian_red = _Rgba_color_from_byte_values(static_cast<unsigned char>(205), static_cast<unsigned char>(92), static_cast<unsigned char>(92));
const rgba_color rgba_color::indigo = _Rgba_color_from_byte_values(static_cast<unsigned char>(75), static_cast<unsigned char>(0), static_cast<unsigned char>(130));
const rgba_color rgba_color::ivory = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(255), static_cast<unsigned char>(240));
const rgba_color rgba_color::khaki = _Rgba_color_from_byte_values(static_cast<unsigned char>(240), static_cast<unsigned char>(230), static_cast<unsigned char>(140));
const rgba_color rgba_color::lavender = _Rgba_color_from_byte_values(static_cast<unsigned char>(230), static_cast<unsigned char>(230), static_cast<unsigned char>(250));
const rgba_color rgba_color::lavender_blush = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(240), static_cast<unsigned char>(245));
const rgba_color rgba_color::lawn_green = _Rgba_color_from_byte_values(static_cast<unsigned char>(124), static_cast<unsigned char>(252), static_cast<unsigned char>(0));
const rgba_color rgba_color::lemon_chiffon = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(250), static_cast<unsigned char>(205));
const rgba_color rgba_color::light_blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(173), static_cast<unsigned char>(216), static_cast<unsigned char>(230));
const rgba_color rgba_color::light_coral = _Rgba_color_from_byte_values(static_cast<unsigned char>(240), static_cast<unsigned char>(128), static_cast<unsigned char>(128));
const rgba_color rgba_color::light_cyan = _Rgba_color_from_byte_values(static_cast<unsigned char>(224), static_cast<unsigned char>(255), static_cast<unsigned char>(255));
const rgba_color rgba_color::light_goldenrod_yellow = _Rgba_color_from_byte_values(static_cast<unsigned char>(250), static_cast<unsigned char>(250), static_cast<unsigned char>(210));
const rgba_color rgba_color::light_gray = _Rgba_color_from_byte_values(static_cast<unsigned char>(211), static_cast<unsigned char>(211), static_cast<unsigned char>(211));
const rgba_color rgba_color::light_green = _Rgba_color_from_byte_values(static_cast<unsigned char>(144), static_cast<unsigned char>(238), static_cast<unsigned char>(144));
const rgba_color rgba_color::light_grey = _Rgba_color_from_byte_values(static_cast<unsigned char>(211), static_cast<unsigned char>(211), static_cast<unsigned char>(211));
const rgba_color rgba_color::light_pink = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(182), static_cast<unsigned char>(193));
const rgba_color rgba_color::light_salmon = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(160), static_cast<unsigned char>(122));
const rgba_color rgba_color::light_sea_green = _Rgba_color_from_byte_values(static_cast<unsigned char>(32), static_cast<unsigned char>(178), static_cast<unsigned char>(170));
const rgba_color rgba_color::light_sky_blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(135), static_cast<unsigned char>(206), static_cast<unsigned char>(250));
const rgba_color rgba_color::light_slate_gray = _Rgba_color_from_byte_values(static_cast<unsigned char>(119), static_cast<unsigned char>(136), static_cast<unsigned char>(153));
const rgba_color rgba_color::light_slate_grey = _Rgba_color_from_byte_values(static_cast<unsigned char>(119), static_cast<unsigned char>(136), static_cast<unsigned char>(153));
const rgba_color rgba_color::light_steel_blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(176), static_cast<unsigned char>(196), static_cast<unsigned char>(222));
const rgba_color rgba_color::light_yellow = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(255), static_cast<unsigned char>(224));
const rgba_color rgba_color::lime = _Rgba_color_from_byte_values(static_cast<unsigned char>(0), static_cast<unsigned char>(255), static_cast<unsigned char>(0));
const rgba_color rgba_color::lime_green = _Rgba_color_from_byte_values(static_cast<unsigned char>(50), static_cast<unsigned char>(205), static_cast<unsigned char>(50));
const rgba_color rgba_color::linen = _Rgba_color_from_byte_values(static_cast<unsigned char>(250), static_cast<unsigned char>(240), static_cast<unsigned char>(230));
const rgba_color rgba_color::magenta = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(0), static_cast<unsigned char>(255));
const rgba_color rgba_color::maroon = _Rgba_color_from_byte_values(static_cast<unsigned char>(128), static_cast<unsigned char>(0), static_cast<unsigned char>(0));
const rgba_color rgba_color::medium_aquamarine = _Rgba_color_from_byte_values(static_cast<unsigned char>(102), static_cast<unsigned char>(205), static_cast<unsigned char>(170));
const rgba_color rgba_color::medium_blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(0), static_cast<unsigned char>(0), static_cast<unsigned char>(205));
const rgba_color rgba_color::medium_orchid = _Rgba_color_from_byte_values(static_cast<unsigned char>(186), static_cast<unsigned char>(85), static_cast<unsigned char>(211));
const rgba_color rgba_color::medium_purple = _Rgba_color_from_byte_values(static_cast<unsigned char>(147), static_cast<unsigned char>(112), static_cast<unsigned char>(219));
const rgba_color rgba_color::medium_sea_green = _Rgba_color_from_byte_values(static_cast<unsigned char>(60), static_cast<unsigned char>(179), static_cast<unsigned char>(113));
const rgba_color rgba_color::medium_slate_blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(123), static_cast<unsigned char>(104), static_cast<unsigned char>(238));
const rgba_color rgba_color::medium_spring_green = _Rgba_color_from_byte_values(static_cast<unsigned char>(0), static_cast<unsigned char>(250), static_cast<unsigned char>(154));
const rgba_color rgba_color::medium_turquoise = _Rgba_color_from_byte_values(static_cast<unsigned char>(72), static_cast<unsigned char>(209), static_cast<unsigned char>(204));
const rgba_color rgba_color::medium_violet_red = _Rgba_color_from_byte_values(static_cast<unsigned char>(199), static_cast<unsigned char>(21), static_cast<unsigned char>(133));
const rgba_color rgba_color::midnight_blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(25), static_cast<unsigned char>(25), static_cast<unsigned char>(112));
const rgba_color rgba_color::mint_cream = _Rgba_color_from_byte_values(static_cast<unsigned char>(245), static_cast<unsigned char>(255), static_cast<unsigned char>(250));
const rgba_color rgba_color::misty_rose = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(228), static_cast<unsigned char>(225));
const rgba_color rgba_color::moccasin = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(228), static_cast<unsigned char>(181));
const rgba_color rgba_color::navajo_white = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(222), static_cast<unsigned char>(173));
const rgba_color rgba_color::navy = _Rgba_color_from_byte_values(static_cast<unsigned char>(0), static_cast<unsigned char>(0), static_cast<unsigned char>(128));
const rgba_color rgba_color::old_lace = _Rgba_color_from_byte_values(static_cast<unsigned char>(253), static_cast<unsigned char>(245), static_cast<unsigned char>(230));
const rgba_color rgba_color::olive = _Rgba_color_from_byte_values(static_cast<unsigned char>(128), static_cast<unsigned char>(128), static_cast<unsigned char>(0));
const rgba_color rgba_color::olive_drab = _Rgba_color_from_byte_values(static_cast<unsigned char>(107), static_cast<unsigned char>(142), static_cast<unsigned char>(35));
const rgba_color rgba_color::orange = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(165), static_cast<unsigned char>(0));
const rgba_color rgba_color::orange_red = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(69), static_cast<unsigned char>(0));
const rgba_color rgba_color::orchid = _Rgba_color_from_byte_values(static_cast<unsigned char>(218), static_cast<unsigned char>(112), static_cast<unsigned char>(214));
const rgba_color rgba_color::pale_goldenrod = _Rgba_color_from_byte_values(static_cast<unsigned char>(238), static_cast<unsigned char>(232), static_cast<unsigned char>(170));
const rgba_color rgba_color::pale_green = _Rgba_color_from_byte_values(static_cast<unsigned char>(152), static_cast<unsigned char>(251), static_cast<unsigned char>(152));
const rgba_color rgba_color::pale_turquoise = _Rgba_color_from_byte_values(static_cast<unsigned char>(175), static_cast<unsigned char>(238), static_cast<unsigned char>(238));
const rgba_color rgba_color::pale_violet_red = _Rgba_color_from_byte_values(static_cast<unsigned char>(219), static_cast<unsigned char>(112), static_cast<unsigned char>(147));
const rgba_color rgba_color::papaya_whip = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(239), static_cast<unsigned char>(213));
const rgba_color rgba_color::peach_puff = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(218), static_cast<unsigned char>(185));
const rgba_color rgba_color::peru = _Rgba_color_from_byte_values(static_cast<unsigned char>(205), static_cast<unsigned char>(133), static_cast<unsigned char>(63));
const rgba_color rgba_color::pink = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(192), static_cast<unsigned char>(203));
const rgba_color rgba_color::plum = _Rgba_color_from_byte_values(static_cast<unsigned char>(221), static_cast<unsigned char>(160), static_cast<unsigned char>(221));
const rgba_color rgba_color::powder_blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(176), static_cast<unsigned char>(224), static_cast<unsigned char>(230));
const rgba_color rgba_color::purple = _Rgba_color_from_byte_values(static_cast<unsigned char>(128), static_cast<unsigned char>(0), static_cast<unsigned char>(128));
const rgba_color rgba_color::red = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(0), static_cast<unsigned char>(0));
const rgba_color rgba_color::rosy_brown = _Rgba_color_from_byte_values(static_cast<unsigned char>(188), static_cast<unsigned char>(143), static_cast<unsigned char>(143));
const rgba_color rgba_color::royal_blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(65), static_cast<unsigned char>(105), static_cast<unsigned char>(225));
const rgba_color rgba_color::saddle_brown = _Rgba_color_from_byte_values(static_cast<unsigned char>(139), static_cast<unsigned char>(69), static_cast<unsigned char>(19));
const rgba_color rgba_color::salmon = _Rgba_color_from_byte_values(static_cast<unsigned char>(250), static_cast<unsigned char>(128), static_cast<unsigned char>(114));
const rgba_color rgba_color::sandy_brown = _Rgba_color_from_byte_values(static_cast<unsigned char>(244), static_cast<unsigned char>(164), static_cast<unsigned char>(96));
const rgba_color rgba_color::sea_green = _Rgba_color_from_byte_values(static_cast<unsigned char>(46), static_cast<unsigned char>(139), static_cast<unsigned char>(87));
const rgba_color rgba_color::sea_shell = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(245), static_cast<unsigned char>(238));
const rgba_color rgba_color::sienna = _Rgba_color_from_byte_values(static_cast<unsigned char>(160), static_cast<unsigned char>(82), static_cast<unsigned char>(45));
const rgba_color rgba_color::silver = _Rgba_color_from_byte_values(static_cast<unsigned char>(192), static_cast<unsigned char>(192), static_cast<unsigned char>(192));
const rgba_color rgba_color::sky_blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(135), static_cast<unsigned char>(206), static_cast<unsigned char>(235));
const rgba_color rgba_color::slate_blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(106), static_cast<unsigned char>(90), static_cast<unsigned char>(205));
const rgba_color rgba_color::slate_gray = _Rgba_color_from_byte_values(static_cast<unsigned char>(112), static_cast<unsigned char>(128), static_cast<unsigned char>(144));
const rgba_color rgba_color::slate_grey = _Rgba_color_from_byte_values(static_cast<unsigned char>(112), static_cast<unsigned char>(128), static_cast<unsigned char>(144));
const rgba_color rgba_color::snow = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(250), static_cast<unsigned char>(250));
const rgba_color rgba_color::spring_green = _Rgba_color_from_byte_values(static_cast<unsigned char>(0), static_cast<unsigned char>(255), static_cast<unsigned char>(127));
const rgba_color rgba_color::steel_blue = _Rgba_color_from_byte_values(static_cast<unsigned char>(70), static_cast<unsigned char>(130), static_cast<unsigned char>(180));
const rgba_color rgba_color::tan = _Rgba_color_from_byte_values(static_cast<unsigned char>(210), static_cast<unsigned char>(180), static_cast<unsigned char>(140));
const rgba_color rgba_color::teal = _Rgba_color_from_byte_values(static_cast<unsigned char>(0), static_cast<unsigned char>(128), static_cast<unsigned char>(128));
const rgba_color rgba_color::thistle = _Rgba_color_from_byte_values(static_cast<unsigned char>(216), static_cast<unsigned char>(191), static_cast<unsigned char>(216));
const rgba_color rgba_color::tomato = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(99), static_cast<unsigned char>(71));
const rgba_color rgba_color::turquoise = _Rgba_color_from_byte_values(static_cast<unsigned char>(64), static_cast<unsigned char>(244), static_cast<unsigned char>(208));
const rgba_color rgba_color::violet = _Rgba_color_from_byte_values(static_cast<unsigned char>(238), static_cast<unsigned char>(130), static_cast<unsigned char>(238));
const rgba_color rgba_color::wheat = _Rgba_color_from_byte_values(static_cast<unsigned char>(245), static_cast<unsigned char>(222), static_cast<unsigned char>(179));
const rgba_color rgba_color::white = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(255), static_cast<unsigned char>(255));
const rgba_color rgba_color::white_smoke = _Rgba_color_from_byte_values(static_cast<unsigned char>(245), static_cast<unsigned char>(245), static_cast<unsigned char>(245));
const rgba_color rgba_color::yellow = _Rgba_color_from_byte_values(static_cast<unsigned char>(255), static_cast<unsigned char>(255), static_cast<unsigned char>(0));
const rgba_color rgba_color::yellow_green = _Rgba_color_from_byte_values(static_cast<unsigned char>(154), static_cast<unsigned char>(205), static_cast<unsigned char>(50));
