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
  //|----------------------------------------------------------------------------------------|                 |-----------------------------------------------------------------------------------------------|
       XXXXX,      TD(TD_Q_1),    TD(TD_W_2),     TD(TD_F_3),     TD(TD_P_4),     TD(TD_G_5),                        TD(TD_J_6),      TD(TD_L_7),      TD(TD_U_8),      TD(TD_Y_9),    TD(TD_SCR_0),     XXXXX,
  //|--------+---------------+---------------+---------------+---------------+---------------|                 |----------------+----------------+----------------+----------------+----------------+----------|
       XXXXX,    SFT_T(KC_A),    CTL_T(KC_R),    ALT_T(KC_S),    GUI_T(KC_T),   TD(TD_D_TAB),                      TD(TD_H_ESC),     GUI_T(KC_N),     ALT_T(KC_E),     CTL_T(KC_I),     SFT_T(KC_O),     XXXXX,
  //|--------+---------------+---------------+---------------+---------------+---------------|                 |----------------+----------------+----------------+----------------+----------------+----------|
       XXXXX,           KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                              KC_K,            KC_M,      TD(TD_CLN), TD(TD_DOT_COMM),     TD(TD_QUOT),     XXXXX,
  //|--------+---------------+---------------+---------------+---------------+---------------+--------+--------+----------------+----------------+----------------+----------------+----------------+----------|
                       XXXXX,          XXXXX,        KC_LCPO, SFT_T(KC_BSPC),   LT(1,KC_ESC),   XXXXX,   XXXXX,    LT(1,KC_ENT),   SFT_T(KC_SPC),         KC_RAPC,           XXXXX,           XXXXX
          //|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
  ),


  [_LOWER] = LAYOUT(
  //|----------------------------------------------------------------------------------------|                 |-----------------------------------------------------------------------------------------------|
       XXXXX,           KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                              KC_6,            KC_7,            KC_8,            KC_9,            KC_0,     XXXXX,
  //|--------+---------------+---------------+---------------+---------------+---------------|                 |----------------+----------------+----------------+----------------+----------------+----------|
       XXXXX,    SFT_T(KC_A),    CTL_T(KC_R),    ALT_T(KC_S),    GUI_T(KC_T),           KC_D,                              KC_H,         KC_LEFT,           KC_UP,         KC_DOWN,        KC_RIGHT,     XXXXX,
  //|--------+---------------+---------------+---------------+---------------+---------------|                 |----------------+----------------+----------------+----------------+----------------+----------|
       XXXXX,           KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                              KC_K,            KC_M,         KC_COMM,          KC_DOT,         KC_QUOT,     XXXXX,
  //|--------+---------------+---------------+---------------+---------------+---------------+--------+--------+----------------+----------------+----------------+----------------+----------------+----------|
                       XXXXX,          XXXXX,        KC_LCPO, SFT_T(KC_BSPC),   LT(1,KC_ESC),   XXXXX,   XXXXX,    LT(1,KC_ENT),   SFT_T(KC_SPC),         KC_RAPC,           XXXXX,           XXXXX
          //|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
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

#pragma region TAP_DANCE

//Tap Dance Declarations
enum {
  TD_DOT_COMM = 0,
  TD_Q_1,
  TD_W_2,
  TD_F_3,
  TD_P_4,
  TD_G_5,
  TD_J_6,
  TD_L_7,
  TD_U_8,
  TD_Y_9,
  TD_SCR_0,
  TD_D_TAB,
  TD_H_ESC,
  TD_1,
  TD_2,
  TD_3,
  TD_4,
  TD_5,
  TD_6,
  TD_7,
  TD_8,
  TD_9,
  TD_0,
  TD_CLN,
  TD_QUOT
};

typedef void (*dance)(*qk_tap_dance_state_t, *void);

void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_SCLN);
  } else {
    register_code (KC_RSFT);
    register_code (KC_SCLN);
  }
}

void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_SCLN);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_SCLN);
  }
}

dance dance_typedef(uint16_t keycode)
{
    return
}

void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_SCLN);
  } else {
    register_code (KC_RSFT);
    register_code (KC_SCLN);
  }
}

void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_SCLN);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_SCLN);
  }
}

void dance_quot_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_QUOT);
  } else {
    register_code (KC_RSFT);
    register_code (KC_QUOT);
  }
}

void dance_quot_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_QUOT);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_QUOT);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_DOT_COMM]  = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMM),
  [TD_Q_1]  = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_1),
  [TD_W_2]  = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_2),
  [TD_F_3]  = ACTION_TAP_DANCE_DOUBLE(KC_F, KC_3),
  [TD_P_4]  = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_4),
  [TD_G_5]  = ACTION_TAP_DANCE_DOUBLE(KC_G, KC_5),
  [TD_J_6]  = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_6),
  [TD_L_7]  = ACTION_TAP_DANCE_DOUBLE(KC_L, KC_7),
  [TD_U_8]  = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_8),
  [TD_Y_9]  = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_9),
  [TD_SCR_0]  = ACTION_TAP_DANCE_DOUBLE(KC_PSCR, KC_0),
  [TD_D_TAB]  = ACTION_TAP_DANCE_DOUBLE(KC_D, KC_TAB),
  [TD_H_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_ESC),

  [TD_1]  = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_!),
  [TD_2]  = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_@),
  [TD_3]  = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_!),
  [TD_4]  = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_!),
  [TD_5]  = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_!),
  [TD_6]  = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_!),
  [TD_7]  = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_!),
  [TD_8]  = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_!),
  [TD_9]  = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_!),
  [TD_0]  = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_!),


  [TD_CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset),
  [TD_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_quot_finished, dance_quot_reset)

};



#pragma endregion

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// 	[0] = LAYOUT(KC_NO, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_NO, KC_NO, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_NO, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_QUOT, KC_NO, KC_NO, KC_NO, KC_LCPO, LCTL_T(KC_SPC), LT(2,KC_ENT), KC_NO, KC_NO, LT(1,KC_ESC), LSFT_T(KC_BSPC), KC_RAPC, KC_NO, KC_NO),
// 	[1] = LAYOUT(KC_NO, KC_TAB, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_MINS, KC_UP, KC_EQL, KC_PSCR, KC_NO, KC_NO, KC_LSFT, KC_4, KC_5, KC_6, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_LALT, KC_NO, KC_NO, KC_LGUI, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_BSLS, KC_GRV, KC_SLSH, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_0, KC_SPC, KC_ENT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
// 	[2] = LAYOUT(KC_NO, LSFT(KC_TAB), KC_EXLM, KC_AT, KC_HASH, KC_LBRC, KC_RBRC, KC_UNDS, LSFT(KC_UP), KC_PLUS, KC_COLN, KC_NO, KC_NO, KC_LSFT, KC_DLR, KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RGHT), KC_LALT, KC_NO, KC_NO, KC_LGUI, KC_AMPR, KC_ASTR, KC_DQUO, KC_LT, KC_GT, KC_PIPE, KC_TILD, KC_QUES, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, KC_BSPC, KC_NO, KC_NO, KC_NO)
// };
