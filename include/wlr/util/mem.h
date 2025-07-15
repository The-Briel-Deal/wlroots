/*
 * This an unstable interface of wlroots. No guarantees are made regarding the
 * future consistency of this API.
 */
#ifndef WLR_USE_UNSTABLE
#error "Add -DWLR_USE_UNSTABLE to enable unstable wlroots features"
#endif

#ifndef WLR_UTIL_MEM_H
#define WLR_UTIL_MEM_H

#include <stddef.h>

bool memdup(void *out, const void *src, size_t size);

#endif // WLR_UTIL_MEM_H
