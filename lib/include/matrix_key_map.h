//
// Created by jerry on 1/09/2026.
//

#pragma once
#include "usb_hid_keys.h"

inline constexpr int matrix_key_map[18][6] = {
    /* i=0  */ { KEY_ESC,        KEY_GRAVE,  KEY_TAB,       KEY_CAPSLOCK,   KEY_NONE,       KEY_LEFTCTRL  },
    /* i=1  */ { KEY_NONE,       KEY_1,      KEY_NONE,      KEY_NONE,       KEY_LEFTSHIFT,  KEY_LEFTMETA  },
    /* i=2  */ { KEY_F1,         KEY_2,      KEY_Q,         KEY_A,          KEY_Z,          KEY_NONE      },
    /* i=3  */ { KEY_F2,         KEY_3,      KEY_W,         KEY_S,          KEY_X,          KEY_LEFTALT   },
    /* i=4  */ { KEY_F3,         KEY_4,      KEY_E,         KEY_D,          KEY_C,          KEY_NONE      },
    /* i=5  */ { KEY_F4,         KEY_5,      KEY_R,         KEY_F,          KEY_V,          KEY_NONE      },
    /* i=6  */ { KEY_NONE,       KEY_6,      KEY_T,         KEY_G,          KEY_B,          KEY_SPACE     },
    /* i=7  */ { KEY_F5,         KEY_7,      KEY_Y,         KEY_H,          KEY_N,          KEY_NONE      },
    /* i=8  */ { KEY_F6,         KEY_8,      KEY_U,         KEY_J,          KEY_M,          KEY_NONE      },
    /* i=9  */ { KEY_F7,         KEY_9,      KEY_I,         KEY_K,          KEY_COMMA,      KEY_NONE      },
    /* i=10 */ { KEY_F8,         KEY_0,      KEY_O,         KEY_L,          KEY_DOT,        KEY_RIGHTALT  },
    /* i=11 */ { KEY_F9,         KEY_MINUS,  KEY_P,         KEY_SEMICOLON,  KEY_SLASH,      KEY_RIGHTMETA },
    /* i=12 */ { KEY_F10,        KEY_EQUAL,  KEY_LEFTBRACE, KEY_APOSTROPHE, KEY_NONE,       KEY_NONE      },
    /* i=13 */ { KEY_F11,        KEY_NONE,   KEY_RIGHTBRACE,KEY_ENTER,      KEY_RIGHTSHIFT, KEY_NONE      }, // j=5 is FN
    /* i=14 */ { KEY_F12,        KEY_BACKSPACE, KEY_BACKSLASH, KEY_NONE,    KEY_NONE,       KEY_RIGHTCTRL },
    /* i=15 */ { KEY_SYSRQ,      KEY_INSERT, KEY_DELETE,    KEY_NONE,       KEY_NONE,       KEY_LEFT      },
    /* i=16 */ { KEY_SCROLLLOCK, KEY_HOME,   KEY_END,       KEY_NONE,       KEY_UP,         KEY_DOWN      },
    /* i=17 */ { KEY_PAUSE,      KEY_PAGEUP, KEY_PAGEDOWN,  KEY_NONE,       KEY_NONE,       KEY_RIGHT     },
};
