#ifndef TYPES_WLR_COLOR_MANAGEMENT_V1_H
#define TYPES_WLR_COLOR_MANAGEMENT_V1_H

#include <wlr/types/wlr_color_management_v1.h>

uint32_t named_primaries_try_to_wlr(enum wp_color_manager_v1_primaries primaries);
enum wp_color_manager_v1_primaries named_primaries_from_wlr(
	enum wlr_color_named_primaries primaries);
uint32_t transfer_function_try_to_wlr(enum wp_color_manager_v1_transfer_function tf);
enum wp_color_manager_v1_transfer_function transfer_function_from_wlr(
	enum wlr_color_transfer_function tf);

#endif
