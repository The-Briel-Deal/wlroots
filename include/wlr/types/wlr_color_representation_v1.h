/*
 * This an unstable interface of wlroots. No guarantees are made regarding the
 * future consistency of this API.
 */
#ifndef WLR_USE_UNSTABLE
#error "Add -DWLR_USE_UNSTABLE to enable unstable wlroots features"
#endif

#ifndef WLR_TYPES_WLR_COLOR_REPRESENTATION_V1_H
#define WLR_TYPES_WLR_COLOR_REPRESENTATION_V1_H

#include <wayland-server-core.h>
#include <wlr/render/color.h>

#include "color-representation-v1-protocol.h"

struct wlr_surface;

struct wlr_color_representation_v1_coeffs_and_range {
	enum wp_color_representation_surface_v1_coefficients coeffs;
	enum wp_color_representation_surface_v1_range range;
};

struct wlr_color_representation_manager_v1 {
	struct wl_global *global;

	struct {
		// Manager is being destroyed
		struct wl_signal destroy;
	} events;

	struct {
		enum wp_color_representation_surface_v1_alpha_mode
			*supported_alpha_modes;
		size_t supported_alpha_modes_len;

		struct wlr_color_representation_v1_coeffs_and_range
			*supported_coeffs_and_ranges;
		size_t supported_coeffs_and_ranges_len;

		struct wl_listener display_destroy;
	} WLR_PRIVATE;
};



struct wlr_color_representation_v1_options {
	enum wp_color_representation_surface_v1_alpha_mode
		*supported_alpha_modes;
	size_t supported_alpha_modes_len;

	const struct wlr_color_representation_v1_coeffs_and_range
		*supported_coeffs_and_ranges;
	size_t supported_coeffs_and_ranges_len;
};

struct wlr_color_representation_manager_v1 *wlr_color_representation_manager_v1_create(
		struct wl_display *display, uint32_t version,
		const struct wlr_color_representation_v1_options *options);

const struct wlr_color_representation_v1_state *wlr_color_representation_v1_get_surface_state(
	struct wlr_surface *surface);

#endif // WLR_TYPES_WLR_COLOR_REPRESENTATION_V1_H
