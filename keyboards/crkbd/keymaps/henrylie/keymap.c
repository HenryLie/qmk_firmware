/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x5_3(
  //,------------------------------------------------------------------.                             ,-----------------------------------------------------------------.
              KC_Q,        KC_W,        KC_F,        KC_P,         KC_G,                                       KC_J,        KC_L,        KC_U,        KC_Y,     KC_SCLN,
  //|+------------+------------+------------+------------+-------------|                             |-------------+------------+------------+------------+------------|
       SFT_T(KC_A), GUI_T(KC_R), ALT_T(KC_S), CTL_T(KC_T),         KC_D,                                       KC_H, CTL_T(KC_N), ALT_T(KC_E), GUI_T(KC_I), SFT_T(KC_O),
  //|+------------+------------+------------+------------+-------------|                             |-------------+------------+------------+------------+------------|
              KC_Z,        KC_X,        KC_C,        KC_V,         KC_B,                                       KC_K,        KC_M,     KC_COMM,      KC_DOT,     KC_QUOT,
  //|+------------+------------+------------+------------+--------------+------------|  |------------+-------------+------------+------------+------------+------------|
                                            GUI_T(KC_DEL),CTL_T(KC_BSPC),LT(1,KC_ESC),   LT(2,KC_ENT),SFT_T(KC_SPC),ALT_T(KC_TAB)
                                          //`----------------------------------------'  `---------------------------------------'
  ),

  [1] = LAYOUT_split_3x5_3(
  //,------------------------------------------------------------------.                             ,-----------------------------------------------------------------.
              KC_1,        KC_2,        KC_3,        KC_4,         KC_5,                                       KC_6,        KC_7,        KC_8,        KC_9,        KC_0,
  //|+------------+------------+------------+------------+-------------|                             |-------------+------------+------------+------------+------------|
           XXXXXXX,     XXXXXXX,      KC_GRV,      KC_TAB,      KC_MINS,                                     KC_EQL,     KC_LEFT,       KC_UP,     KC_DOWN,     KC_RGHT,
  //|+------------+------------+------------+------------+-------------|                             |-------------+------------+------------+------------+------------|
           KC_LBRC,       KC_LT,     KC_LCBR,     KC_LPRN,      KC_BSLS,                                    KC_SLSH,     KC_RPRN,     KC_RCBR,       KC_GT,     KC_RBRC,
  //|+------------+------------+------------+------------+--------------+------------|  |------------+-------------+------------+------------+------------+------------|
                                            GUI_T(KC_DEL),CTL_T(KC_BSPC),     _______,   LT(3,KC_ENT),SFT_T(KC_SPC),ALT_T(KC_TAB)
                                          //`----------------------------------------'  `---------------------------------------'
  ),

  [2] = LAYOUT_split_3x5_3(
  //,------------------------------------------------------------------.                             ,-----------------------------------------------------------------.
           KC_EXLM,       KC_AT,     KC_HASH,      KC_DLR,      KC_PERC,                                    KC_CIRC,     KC_AMPR,     KC_ASTR,      KC_GRV,     KC_TILD,
  //|+------------+------------+------------+------------+-------------|                             |-------------+------------+------------+------------+------------|
           XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,      KC_UNDS,                                    KC_PLUS,     KC_LEFT,       KC_UP,     KC_DOWN,     KC_RGHT,
  //|+------------+------------+------------+------------+-------------|                             |-------------+------------+------------+------------+------------|
           XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,      KC_PIPE,                                    KC_QUES,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,
  //|+------------+------------+------------+------------+--------------+------------|  |------------+-------------+------------+------------+------------+------------|
                                            GUI_T(KC_DEL),CTL_T(KC_BSPC),LT(3,KC_ESC),        _______,SFT_T(KC_SPC),ALT_T(KC_TAB)
                                          //`----------------------------------------'  `---------------------------------------'
  ),

  [3] = LAYOUT_split_3x5_3(
  //,------------------------------------------------------------------.                             ,-----------------------------------------------------------------.
             KC_F1,       KC_F2,       KC_F3,       KC_F4,        KC_F5,                                      KC_F6,       KC_F7,       KC_F8,       KC_F9,      KC_F10,
  //|+------------+------------+------------+------------+-------------|                             |-------------+------------+------------+------------+------------|
           KC_BTN4,     KC_BTN2,     KC_BTN3,     KC_BTN1,      KC_VOLU,                                    KC_BRIU,     KC_MS_L,     KC_MS_U,     KC_MS_D,     KC_MS_R,
  //|+------------+------------+------------+------------+-------------|                             |-------------+------------+------------+------------+------------|
           XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,      KC_VOLD,                                    KC_BRID,     KC_WH_L,     KC_WH_U,     KC_WH_D,     KC_WH_R,
  //|+------------+------------+------------+------------+--------------+------------|  |------------+-------------+------------+------------+------------+------------|
                                            GUI_T(KC_DEL),CTL_T(KC_BSPC),     _______,        _______,SFT_T(KC_SPC),ALT_T(KC_TAB)
                                          //`----------------------------------------'  `---------------------------------------'
  )
};

#ifdef OLED_ENABLE
#include <stdio.h>
#include "bongocat.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

// void oled_render_logo(void) {
//     oled_set_cursor(0, 1); // If drawn on the left side, needs to start drawing from the second line
//     static const char PROGMEM logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     };
//     oled_write_P(logo, false);
// }

void oled_render_matrix(void) {
    static const char PROGMEM matrix[] = {
        0x00, 0x00, 0x20, 0xa0, 0x60, 0x30, 0x08, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00,
        0xc0, 0xa0, 0x90, 0x80, 0x80, 0x00, 0x00, 0xf0, 0x08, 0x08, 0xc8, 0xc0, 0x00, 0x00, 0x40, 0x20,
        0x28, 0x08, 0xf8, 0x00, 0x00, 0x40, 0x40, 0x48, 0xf8, 0x40, 0x00, 0x00, 0x70, 0x08, 0x08, 0x08,
        0xf8, 0x00, 0x00, 0xc0, 0x20, 0xf8, 0x20, 0xf8, 0x00, 0x00, 0x70, 0x08, 0xf8, 0x00, 0xf8, 0x00,
        0x00, 0x60, 0x10, 0x50, 0xf8, 0x50, 0x00, 0x00, 0xc0, 0x20, 0xf8, 0x00, 0xf8, 0x00, 0x00, 0x90,
        0x58, 0x50, 0x50, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x30, 0x08, 0x3e, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40,
        0xc0, 0x40, 0xc0, 0x00, 0x00, 0x40, 0x80, 0x80, 0x40, 0xc0, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0,
        0x80, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x00,
        0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c,
        0x02, 0x02, 0x2a, 0x2a, 0x00, 0x00, 0x0c, 0x10, 0x12, 0x3e, 0x10, 0x00, 0x00, 0x3e, 0x04, 0x04,
        0x04, 0x1c, 0x00, 0x00, 0x08, 0x28, 0x18, 0x0c, 0x02, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x1c,
        0x00, 0x00, 0x1c, 0x02, 0x2a, 0x12, 0x1e, 0x00, 0x00, 0x3c, 0x02, 0x02, 0x32, 0x30, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x80, 0x40, 0x00, 0x00, 0x00, 0x00, 0x40, 0x80, 0x40, 0x20, 0xe0, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
        0x07, 0x00, 0x07, 0x00, 0x00, 0x04, 0x03, 0x00, 0x00, 0x07, 0x00, 0x00, 0x03, 0x00, 0x00, 0x07,
        0x00, 0x00, 0x00, 0x06, 0x01, 0x07, 0x00, 0x07, 0x00, 0x00, 0x81, 0xe5, 0x83, 0xe1, 0x80, 0x00,
        0x00, 0x24, 0x44, 0x47, 0x44, 0x44, 0x00, 0x00, 0xc0, 0x20, 0xa0, 0x20, 0xe0, 0x00, 0x00, 0x60,
        0x80, 0xe0, 0x80, 0xe0, 0x00, 0x00, 0xc0, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0,
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xe0, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x80, 0x40, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xfb, 0x02, 0xfa, 0x02, 0xfa, 0x00, 0x00, 0x8b, 0x70, 0x11, 0x08, 0xfb, 0x00, 0x00,
        0x60, 0x10, 0x50, 0xf8, 0x50, 0x00, 0x00, 0x70, 0x08, 0x08, 0xa8, 0xa8, 0x00, 0x00, 0x70, 0x08,
        0x88, 0x88, 0x88, 0x00, 0x00, 0x10, 0x20, 0x50, 0x08, 0xf8, 0x00, 0x00, 0x70, 0x08, 0x08, 0xa8,
        0xa8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00,
        0x00, 0x02, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x03, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01, 0x03,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02,
        0x00, 0x00, 0xc0, 0x20, 0xf8, 0x20, 0xf8, 0x00, 0x00, 0x70, 0x08, 0xa8, 0x48, 0x78, 0x00, 0x00
    };
    oled_write_raw_P(matrix, 512);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_bongo_cat();
    } else {
        oled_render_matrix();
        oled_scroll_left();  // Turns on scrolling
    }
    return false;
}

// #region LAYER_STATE
// void oled_render_layer_state(void) {
//     oled_write_P(PSTR("Layer: "), false);
//     switch (layer_state) {
//         case L_BASE:
//             oled_write_ln_P(PSTR("Default"), false);
//             break;
//         case L_LOWER:
//             oled_write_ln_P(PSTR("Lower"), false);
//             break;
//         case L_RAISE:
//             oled_write_ln_P(PSTR("Raise"), false);
//             break;
//         case L_ADJUST:
//         case L_ADJUST|L_LOWER:
//         case L_ADJUST|L_RAISE:
//         case L_ADJUST|L_LOWER|L_RAISE:
//             oled_write_ln_P(PSTR("Adjust"), false);
//             break;
//     }
// }
// #endregion

// #region LOGGER
// char keylog_str[24] = {};

// const char code_to_name[60] = {
//     ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
//     'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
//     'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
//     '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
//     'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
//     '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

// void set_keylog(uint16_t keycode, keyrecord_t *record) {
//   char name = ' ';
//     if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
//         (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
//   if (keycode < 60) {
//     name = code_to_name[keycode];
//   }

//   // update keylog
//   snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
//            record->event.key.row, record->event.key.col,
//            keycode, name);
// }

// void oled_render_keylog(void) {
//     oled_write(keylog_str, false);
// }

// void render_bootmagic_status(bool status) {
//     /* Show Ctrl-Gui Swap options */
//     static const char PROGMEM logo[][2][3] = {
//         {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
//         {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
//     };
//     if (status) {
//         oled_write_ln_P(logo[0][0], false);
//         oled_write_ln_P(logo[0][1], false);
//     } else {
//         oled_write_ln_P(logo[1][0], false);
//         oled_write_ln_P(logo[1][1], false);
//     }
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
//     set_keylog(keycode, record);
//   }
//   return true;
// }
//#endregion

#endif // OLED_ENABLE
