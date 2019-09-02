#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _BASE = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  RGBRST
};

// Layer Mode aliases
#define _____ KC_TRNS
#define XXXXX KC_NO

#define KC_SNUBS S(KC_NUBS)
#define KC_SNUHS S(KC_NUHS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
       KC_NO,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
       KC_NO,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
       KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_K,    KC_M, KC_COMM,  KC_DOT, KC_QUOT,  KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
              KC_NO,KC_NO,KC_LCPO,LGUI_T(KC_SPC),LT(2,KC_ENT),KC_NO,KC_NO,LT(1,KC_ESC),LSFT_T(KC_BSPC),KC_RAPC,KC_NO,KC_NO
          //`------------------------------------------------------------------------------------------------------------'
  ),


  [_LOWER] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
      KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR,  KC_ASTR,KC_LPRN, KC_RPRN,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
       KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
        _____,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,                    KC_F12,KC_SNUHS,KC_SNUBS,   _____,   _____,   _____,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
          //`------------------------------------------------------------------------------------------------------------'
  ),


  [_RAISE] = LAYOUT(
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
      KC_TILD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
       KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
        _____,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,                    KC_F12, KC_NUHS, KC_NUBS,   _____,   _____,   _____,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____ 
          //`------------------------------------------------------------------------------------------------------------'
  ),


  [_ADJUST] = LAYOUT( /* Base */
  //,-----------------------------------------------------|                 |-----------------------------------------------------.
        _____,   RESET,   XXXXX,   XXXXX,   XXXXX,   XXXXX,                     XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   _____,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
        _____,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,                   RGB_TOG, RGB_MOD,   XXXXX,LCA(KC_DEL),LALT(KC_PSCR),KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
        _____,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,                   RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
                 _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____
          //`------------------------------------------------------------------------------------------------------------'
  )
};

static inline void update_change_layer(bool pressed, uint8_t layer1, uint8_t layer2, uint8_t layer3) {

  pressed ? layer_on(layer1) : layer_off(layer1);
  IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2) ? layer_on(layer3) : layer_off(layer3);
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
    case LOWER:
      update_change_layer(record->event.pressed, _LOWER, _RAISE, _ADJUST);
      break;
    case RAISE:
      update_change_layer(record->event.pressed, _RAISE, _LOWER, _ADJUST);
        break;
    #ifdef RGBLIGHT_ENABLE
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGBRST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    default:
      result = true;
      break;
  }

  return result;
}

void matrix_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
  #endif
}

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// 	[0] = LAYOUT(KC_NO, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_NO, KC_NO, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_NO, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_QUOT, KC_NO, KC_NO, KC_NO, KC_LCPO, LCTL_T(KC_SPC), LT(2,KC_ENT), KC_NO, KC_NO, LT(1,KC_ESC), LSFT_T(KC_BSPC), KC_RAPC, KC_NO, KC_NO),
// 	[1] = LAYOUT(KC_NO, KC_TAB, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_MINS, KC_UP, KC_EQL, KC_PSCR, KC_NO, KC_NO, KC_LSFT, KC_4, KC_5, KC_6, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_LALT, KC_NO, KC_NO, KC_LGUI, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_BSLS, KC_GRV, KC_SLSH, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_0, KC_SPC, KC_ENT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
// 	[2] = LAYOUT(KC_NO, LSFT(KC_TAB), KC_EXLM, KC_AT, KC_HASH, KC_LBRC, KC_RBRC, KC_UNDS, LSFT(KC_UP), KC_PLUS, KC_COLN, KC_NO, KC_NO, KC_LSFT, KC_DLR, KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RGHT), KC_LALT, KC_NO, KC_NO, KC_LGUI, KC_AMPR, KC_ASTR, KC_DQUO, KC_LT, KC_GT, KC_PIPE, KC_TILD, KC_QUES, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, KC_BSPC, KC_NO, KC_NO, KC_NO)
// };
