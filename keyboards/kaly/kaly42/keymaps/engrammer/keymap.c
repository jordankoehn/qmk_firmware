#include QMK_KEYBOARD_H
// #include "features/layer_lock.h"

// enum custom_keycodes {
//     QK_LLCK = SAFE_RANGE,
//     // Other custom keys...
// };
//
// bool process_record_user(uint16_t keycode, keyrecord_t* record) {
//   if (!process_layer_lock(keycode, record, QK_LLCK)) { return false; }
//   // Your macros ...
//
//   return true;
// }

#define NAV_LLCK    LT(2, KC_0)

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case NAV_LLCK:  // NAV layer on hold, KC_QUES on tap.
      if (record->tap.count) {  // On tap.
        if (record->event.pressed) {  // On press.
          tap_code16(QK_LLCK);
        }
        return false;  // Skip default handling.
      }
      break;

    // Other macros...
  }
  return true;  // Continue default handling.
}

// Left-hand home row mods
#define HOME_C LCTL_T(KC_C)
#define HOME_I LALT_T(KC_I)
#define HOME_E LGUI_T(KC_E)
#define HOME_A LSFT_T(KC_A)

#define HOME_1 LCTL_T(KC_1)
#define HOME_2 LALT_T(KC_2)
#define HOME_3 LGUI_T(KC_3)
#define HOME_4 LSFT_T(KC_4)

// Right-hand home row mods
#define HOME_H RSFT_T(KC_H)
#define HOME_T RGUI_T(KC_T)
#define HOME_S RALT_T(KC_S)
#define HOME_N RCTL_T(KC_N)

#define HOME_7 RSFT_T(KC_7)
#define HOME_8 RGUI_T(KC_8)
#define HOME_9 RALT_T(KC_9)
#define HOME_0 RCTL_T(KC_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x6_3(KC_NO, KC_B, KC_Y, KC_O, KC_U, KC_NO,        KC_SCLN, KC_L, KC_D, KC_W, KC_V, TO(5),
                          KC_NO, HOME_C, HOME_I, HOME_E, HOME_A, KC_Z,        KC_Q, HOME_H, HOME_T, HOME_S, HOME_N, MOD_MEH,
                             QK_LLCK, KC_G, KC_X, KC_J, KC_K, KC_NO,        KC_SLSH, KC_R, KC_M, KC_F, KC_P, QK_LLCK,
                         LT(3, KC_ESC), LT(1, KC_SPC), MO(2),               MO(1), MO(2), MO(3)),

    [1] = LAYOUT_split_3x6_3(KC_NO, KC_LBRC, KC_MINS, KC_QUOT, KC_COMM, KC_NO,     KC_NO, KC_DOT, KC_DQT, KC_QUES, KC_RBRC, KC_NO,
                           KC_NO, HOME_1, HOME_2, HOME_3, HOME_4, KC_NO,           KC_NO, HOME_7, HOME_8, HOME_9, HOME_0, KC_NO,
                       KC_TRANSPARENT, KC_NO, KC_NO, KC_AT, KC_5, KC_NO,           KC_NO, KC_6, KC_HASH, KC_NO, KC_SLSH, KC_TRANSPARENT,
                             TO(0), KC_TRANSPARENT, QK_LLCK,                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),

    [2] = LAYOUT_split_3x6_3(KC_NO, LALT(KC_UP), KC_HOME, KC_UP, KC_END, KC_PGUP,      KC_NO, RALT(KC_ENT), RALT(KC_TAB), RALT(KC_DEL), RALT(KC_BSPC), KC_NO,
                          KC_NO, LALT(KC_DOWN), KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,    KC_NO, KC_ENT, KC_TAB, KC_DEL, KC_BSPC, KC_NO,
                               KC_TRANSPARENT, KC_NO, SELWBAK, SELLINE, SELWORD, KC_NO,      KC_NO, RSFT(KC_ENT), RSFT(KC_TAB), RSFT(KC_DEL), RSFT(KC_BSPC), KC_TRANSPARENT,
                                      TO(0), KC_TRANSPARENT, QK_LLCK,                    KC_TRANSPARENT, KC_NO, KC_TRANSPARENT),

    [3] = LAYOUT_split_3x6_3(KC_NO, KC_LCBR, KC_UNDS, KC_LPRN, KC_SCLN, KC_NO,         KC_NO, KC_COLN, KC_RPRN, KC_EXLM, KC_RCBR, KC_NO,
                             KC_NO, KC_PIPE, KC_EQL, KC_TILD, KC_PLUS, KC_NO,          KC_NO, KC_CIRC, KC_AMPR, KC_PERC, KC_ASTR, KC_NO,
                             KC_TRANSPARENT, KC_NO, KC_NO, KC_GRV, KC_LT, KC_NO,       KC_NO, KC_GT, KC_DLR, KC_NO, KC_BSLS, KC_TRANSPARENT,
                             TO(0), KC_TRANSPARENT, QK_LLCK,                             KC_TRANSPARENT, KC_TRANSPARENT, KC_NO),

    [4] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          OM_W_U, OM_BTNS, OM_U, OM_DBLS, KC_NO, KC_NO,
                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          OM_W_D, OM_L, OM_D, OM_R, OM_SLOW, KC_NO,
                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          OM_RELS, OM_HLDS, OM_SEL1, OM_SEL2, OM_SEL3, KC_NO,
                             TO(0), KC_NO, KC_NO,                               KC_NO, KC_NO, KC_NO),

    [5] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          OM_W_U, OM_BTNS, MS_UP, OM_DBLS, KC_NO, KC_NO,
                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          OM_W_D, MS_LEFT, MS_DOWN, MS_RGHT, OM_SLOW, KC_NO,
                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          OM_RELS, OM_HLDS, OM_SEL1, OM_SEL2, OM_SEL3, KC_NO,
                             TO(0), KC_NO, KC_NO,                               KC_NO, KC_NO, KC_NO)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

