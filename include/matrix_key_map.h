//
// Created by jerry on 1/09/2026.
//

#ifndef USB_DRIVER_MATRIX_KEY_MAP_H
#define USB_DRIVER_MATRIX_KEY_MAP_H

#pragma once
#include <unordered_map>
#include <utility>
#include <string>
#include <usb_hid_keys.h>

// Define a clean alias for the coordinate key
using index = std::pair<int, int>;

// Inline allows definition directly in the header file (C++17)
inline const std::unordered_map<index, std::string> matrix_key_map = {
{{0, 0}, KEY_ESC},
{{1, 0}, KEY_NONE},
{{2, 0}, KEY_F1},
{{3, 0}, KEY_F2},
{{4, 0}, KEY_F3},
{{5, 0}, KEY_F4},
{{6, 0}, KEY_NONE},
{{7, 0}, KEY_F5},
{{8, 0}, KEY_F6},
{{9, 0}, KEY_F7},
{{10, 0}, KEY_F8},
{{11, 0}, KEY_F9},
{{12, 0}, KEY_F10},
{{13, 0}, KEY_F11},
{{14, 0}, KEY_F12},
{{15, 0}, KEY_SYSRQ},
{{16, 0}, KEY_SCROLLLOCK},
{{17, 0}, KEY_PAUSE},

{{0, 1}, KEY_GRAVE},
{{1, 1}, KEY_1},
{{2, 1}, KEY_2},
{{3, 1}, KEY_3},
{{4, 1}, KEY_4},
{{5, 1}, KEY_5},
{{6, 1}, KEY_6},
{{7, 1}, KEY_7},
{{8, 1}, KEY_8},
{{9, 1}, KEY_9},
{{10, 1}, KEY_0},
{{11, 1}, KEY_MINUS},
{{12, 1}, KEY_EQUAL},
{{13, 1}, KEY_NONE},
{{14, 1}, KEY_BACKSPACE},
{{15, 1}, KEY_INSERT},
{{16, 0}, KEY_HOME},
{{17, 0}, KEY_PAGEUP},

{{0, 2}, KEY_TAB},
{{1, 2}, KEY_NONE},
{{2, 2}, KEY_Q},
{{3, 2}, KEY_W},
{{4, 2}, KEY_E},
{{5, 2}, KEY_R},
{{6, 2}, KEY_T},
{{7, 2}, KEY_Y},
{{8, 2}, KEY_U},
{{9, 2}, KEY_I},
{{10, 2}, KEY_O},
{{11, 2}, KEY_P},
{{12, 2}, KEY_LEFTBRACE},
{{13, 2}, KEY_RIGHTBRACE},
{{14, 2}, KEY_BACKSLASH},
{{15, 2}, KEY_DELETE},
{{16, 0}, KEY_END},
{{17, 0}, KEY_PAGEDOWN},

{{0, 3}, KEY_CAPSLOCK},
{{1, 3}, KEY_NONE},
{{2, 3}, KEY_A},
{{3, 3}, KEY_S},
{{4, 3}, KEY_D},
{{5, 3}, KEY_F},
{{6, 3}, KEY_G},
{{7, 3}, KEY_H},
{{8, 3}, KEY_J},
{{9, 3}, KEY_K},
{{10, 3}, KEY_L},
{{11, 3}, KEY_SEMICOLON},
{{12, 3}, KEY_APOSTROPHE},
{{13, 3}, KEY_ENTER},
{{14, 3}, KEY_NONE},
{{15, 3}, KEY_NONE},
{{16, 0}, KEY_NONE},
{{17, 0}, KEY_NONE},

{{0, 4}, KEY_NONE},
{{1, 4}, KEY_LEFTSHIFT},
{{2, 4}, KEY_Z},
{{3, 4}, KEY_X},
{{4, 4}, KEY_C},
{{5, 4}, KEY_V},
{{6, 4}, KEY_B},
{{7, 4}, KEY_N},
{{8, 4}, KEY_M},
{{9, 4}, KEY_COMMA},
{{10, 4}, KEY_DOT},
{{11, 4}, KEY_SLASH},
{{12, 4}, KEY_NONE},
{{13, 4}, KEY_RIGHTSHIFT},
{{14, 4}, KEY_NONE},
{{15, 4}, KEY_NONE},
{{16, 0}, KEY_UP},
{{17, 0}, KEY_NONE},

{{0, 5}, KEY_LEFTCTRL},
{{1, 5}, KEY_LEFTMETA},
{{2, 5}, KEY_NONE},
{{3, 5}, KEY_LEFTALT},
{{4, 5}, KEY_NONE},
{{5, 5}, KEY_NONE},
{{6, 5}, KEY_SPACE},
{{7, 5}, KEY_NONE},
{{8, 5}, KEY_NONE},
{{9, 5}, KEY_NONE},
{{10, 5}, KEY_RIGHTALT},
{{11, 5}, KEY_RIGHTMETA},
{{12, 5}, KEY_NONE},
{{13, 5}, KEY_NONE}, // FN key
{{14, 5}, KEY_RIGHTCTRL},
{{15, 5}, KEY_LEFT},
{{16, 0}, KEY_DOWN},
{{17, 0}, KEY_RIGHT},
};

#endif //USB_DRIVER_MATRIX_KEY_MAP_H
