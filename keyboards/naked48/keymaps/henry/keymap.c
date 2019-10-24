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
};

enum custom_keycodes {
  LOWER_ESC = SAFE_RANGE,
  LOWER_ENT,
  RAISE,
  RGBRST
};

// Layer Mode aliases
#define _____ KC_TRNS
#define XXXXX KC_NO


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

  [TD_CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset),
  [TD_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_quot_finished, dance_quot_reset)

};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //|----------------------------------------------------------------------------------------|                 |-----------------------------------------------------------------------------------------------|
     KC_VOLU,           KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,                              KC_J,            KC_L,            KC_U,            KC_Y,         KC_SCLN,   KC_MFFD,
  //|--------+---------------+---------------+---------------+---------------+---------------|                 |----------------+----------------+----------------+----------------+----------------+----------|
     KC_MUTE,    SFT_T(KC_A),    CTL_T(KC_R),    ALT_T(KC_S),    GUI_T(KC_T),           KC_D,                              KC_H,     GUI_T(KC_N),     ALT_T(KC_E),     CTL_T(KC_I),     SFT_T(KC_O),   KC_MPLY,
  //|--------+---------------+---------------+---------------+---------------+---------------|                 |----------------+----------------+----------------+----------------+----------------+----------|
     KC_VOLD,           KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                              KC_K,            KC_M,         KC_COMM,          KC_DOT,         KC_QUOT,   KC_MRWD,
  //|--------+---------------+---------------+---------------+---------------+---------------+--------+--------+----------------+----------------+----------------+----------------+----------------+----------|
                 KC__VOLDOWN,      KC__VOLUP,     C(KC_JYEN), GUI_T(KC_BSPC),      LOWER_ESC, KC_BRID, KC_BRIU,       LOWER_ENT,   SFT_T(KC_SPC),   ALGR(KC_KANA),         KC_HENK,         KC_MHEN
          //|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
  ),


  [_LOWER] = LAYOUT(
  //|----------------------------------------------------------------------------------------|                 |-----------------------------------------------------------------------------------------------|
       XXXXX,           KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                              KC_6,            KC_7,            KC_8,            KC_9,            KC_0,     XXXXX,
  //|--------+---------------+---------------+---------------+---------------+---------------|                 |----------------+----------------+----------------+----------------+----------------+----------|
       XXXXX, SFT_T(KC_TILD), CTL_T(KC_QUOT),  ALT_T(KC_GRV),  GUI_T(KC_TAB),        KC_MINS,                            KC_EQL,         KC_LEFT,           KC_UP,         KC_DOWN,        KC_RIGHT,     XXXXX,
  //|--------+---------------+---------------+---------------+---------------+---------------|                 |----------------+----------------+----------------+----------------+----------------+----------|
       XXXXX,        KC_LBRC,          KC_LT,        KC_LCBR,        KC_LPRN,        KC_BSLS,                           KC_SLSH,         KC_RPRN,         KC_RCBR,           KC_GT,         KC_RBRC,     XXXXX,
  //|--------+---------------+---------------+---------------+---------------+---------------+--------+--------+----------------+----------------+----------------+----------------+----------------+----------|
                       XXXXX,          XXXXX,     C(KC_JYEN), GUI_T(KC_BSPC),          _____,   XXXXX,   XXXXX,           _____,   SFT_T(KC_SPC),   ALGR(KC_KANA),           XXXXX,           XXXXX
          //|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
  ),


  [_RAISE] = LAYOUT(
  //|----------------------------------------------------------------------------------------|                 |-----------------------------------------------------------------------------------------------|
       XXXXX,        KC_EXLM,          KC_AT,        KC_HASH,         KC_DLR,        KC_PERC,                           KC_CIRC,         KC_AMPR,         KC_ASTR,          KC_GRV,         KC_TILD,     XXXXX,
  //|--------+---------------+---------------+---------------+---------------+---------------|                 |----------------+----------------+----------------+----------------+----------------+----------|
       XXXXX, SFT_T(KC_TILD), CTL_T(KC_QUOT),  ALT_T(KC_GRV),  GUI_T(KC_TAB),        KC_UNDS,                           KC_PLUS,      A(KC_LEFT),         KC_PGUP,         KC_PGDN,     A(KC_RIGHT),     XXXXX,
  //|--------+---------------+---------------+---------------+---------------+---------------|                 |----------------+----------------+----------------+----------------+----------------+----------|
       XXXXX,        KC_MPLY,        KC_BTN2,        KC_BTN3,        KC_BTN1,        KC_PIPE,                           KC_QUES,         KC_MS_L,         KC_MS_U,         KC_MS_D,         KC_MS_R,     XXXXX,
  //|--------+---------------+---------------+---------------+---------------+---------------+--------+--------+----------------+----------------+----------------+----------------+----------------+----------|
                       XXXXX,          XXXXX,     C(KC_JYEN), GUI_T(KC_BSPC),          _____,   XXXXX,   XXXXX,           _____,   SFT_T(KC_SPC),   ALGR(KC_KANA),           XXXXX,           XXXXX
          //|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
  )
};

static inline void update_change_layer(bool pressed, uint8_t layer1, uint8_t layer2) {

  if(IS_LAYER_ON(layer2)) {
    if (!pressed) layer_off(layer2);
  }
  else if(IS_LAYER_ON(layer1)) {
    pressed ? layer_on(layer2) : layer_off(layer1);
  }
  else {
    if (pressed) layer_on(layer1);
  }
}


void tap_hold(bool pressed, uint16_t time, uint16_t keycodetap, uint16_t keycodehold) {
  static uint16_t time_on_pressed;

  if (pressed) {
    time_on_pressed = time;
  } else {
    if (TIMER_DIFF_16(time, time_on_pressed) > TAPPING_TERM) {
      tap_code(keycodehold);
    } else {
      tap_code(keycodetap);
    }
    time_on_pressed = 0;
  }
}

void tap_hold_lower_esc(bool pressed, uint16_t time) {
  static uint16_t time_on_pressed;

  if (pressed) {
    time_on_pressed = time;
    update_change_layer(pressed, _LOWER, _RAISE);
  } else {
    update_change_layer(pressed, _LOWER, _RAISE);
    if (TIMER_DIFF_16(time, time_on_pressed) < TAPPING_TERM) {
      tap_code(KC_ESC);
    }
    time_on_pressed = 0;
  }
}

void tap_hold_lower_ent(bool pressed, uint16_t time) {
  static uint16_t time_on_pressed;

  if (pressed) {
    time_on_pressed = time;
    update_change_layer(pressed, _LOWER, _RAISE);
  } else {
    update_change_layer(pressed, _LOWER, _RAISE);
    if (TIMER_DIFF_16(time, time_on_pressed) < TAPPING_TERM) {
      tap_code(KC_ENT);
    }
    time_on_pressed = 0;
  }
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
    // case KC_Q:
    //   tap_hold(record->event.pressed, record->event.time, KC_Q, KC_1);
    //   break;
    case LOWER_ESC:
      tap_hold_lower_esc(record->event.pressed, record->event.time);
      break;
    case LOWER_ENT:
      tap_hold_lower_ent(record->event.pressed, record->event.time);
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
// 	[0] = LAYOUT(KC_NO, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_NO, KC_NO, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_NO, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_QUOT, KC_NO, KC_NO, KC_NO, KC_LCPO, LCTL_T(KC_SPC), LT(2,KC_ENT), KC_NO, KC_NO, LT(1,KC_ESC), LSFT_T(K ALGR(KC_KANA), KC_NO, KC_NO),
// 	[1] = LAYOUT(KC_NO, KC_TAB, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_MINS, KC_UP, KC_EQL, KC_PSCR, KC_NO, KC_NO, KC_LSFT, KC_4, KC_5, KC_6, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_LALT, KC_NO, KC_NO, KC_LGUI, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_BSLS, KC_GRV, KC_SLSH, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_0, KC_SPC, KC_ENT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
// 	[2] = LAYOUT(KC_NO, LSFT(KC_TAB), KC_EXLM, KC_AT, KC_HASH, KC_LBRC, KC_RBRC, KC_UNDS, LSFT(KC_UP), KC_PLUS, KC_COLN, KC_NO, KC_NO, KC_LSFT, KC_DLR, KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RGHT), KC_LALT, KC_NO, KC_NO, KC_LGUI, KC_AMPR, KC_ASTR, KC_DQUO, KC_LT, KC_GT, KC_PIPE, KC_TILD, KC_QUES, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, KC_BSPC, KC_NO, KC_NO, KC_NO)
// };
