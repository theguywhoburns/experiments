#pragma once

#include <util.h>

PP_TSTRUCT(window_handle);
struct window_handle {
    window_handle* parent;
    window_handle* children;
    // This includes the window handle
    void* platform_specific_data;
    // The folowing functions are set automatically
    void (*set_title)(window_handle* window, const char* title);
    void (*set_size) (window_handle* window, int width, int height);
    void (*get_size) (window_handle* window, int* width, int* height);
    // end set automatically

    // These are nullable and specified by the user
    // This is called each time the window is updated
    void (*on_update)(window_handle* window);
    // This is called each time the window is resized
    void (*on_resize)(window_handle* window, int width, int height);
    // This is called each time the window is closed
    void (*on_close)(window_handle* window);
    // end set by the user
};

window_handle create_new_window(const char* title, int width, int height, window_handle* parent);
void destroy_window(window_handle* window);