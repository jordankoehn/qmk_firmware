#include QMK_KEYBOARD_H
// #include "features/layer_lock.h"

enum kaly_layers { _BASE, _NUM, _NAV, _SYM, _MOUSE };

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

#define NAV_LLCK LT(2, KC_0)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NAV_LLCK:                       // NAV layer on hold, KC_LLCK on tap.
            if (record->tap.count) {         // On tap.
                if (record->event.pressed) { // On press.
                    tap_code16(QK_LLCK);
                }
                return false; // Skip default handling.
            }
            break;

            // Other macros...
    }
    return true; // Continue default handling.
}

// Left-hand home row mods
#define HOME_C LCTL_T(KC_C)
#define HOME_I LALT_T(KC_I)
#define HOME_A LGUI_T(KC_A)
#define HOME_E LSFT_T(KC_E)

// #define HOME_1 LCTL_T(KC_1)
// #define HOME_2 LALT_T(KC_2)
// #define HOME_3 LGUI_T(KC_3)
// #define HOME_4 LSFT_T(KC_4)

// Right-hand home row mods
#define HOME_H LSFT_T(KC_H)
#define HOME_T LGUI_T(KC_T)
#define HOME_N LALT_T(KC_N)
#define HOME_S LCTL_T(KC_S)

// #define HOME_7 RSFT_T(KC_7)
// #define HOME_8 RGUI_T(KC_8)
// #define HOME_9 RALT_T(KC_9)
// #define HOME_0 RCTL_T(KC_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ Z │ Y │ O │ U │ = │       │ Q │ L │ D │ P │ X │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ W │ C │ I │ A │ E │ ; │       │ K │ H │ T │ N │ S │ F │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ ' │ - │ , │ . │ / │       │ J │ M │ G │ B │ V │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │SYM├───┐           ┌───┤SYM│
      *               └───┤NUM├───┐   ┌───┤NAV├───┘
      *                   └───┤NAV│   │NUM├───┘
      *                       └───┘   └───┘
      */
    [_BASE] = LAYOUT_split_3x6_3(
        KC_NO,   KC_Z,     KC_Y,     KC_O,             KC_U,             KC_EQL,       KC_Q,     KC_L,           KC_D,    KC_P,   KC_X,   TO(_MOUSE),
        KC_W,    HOME_C,   HOME_I,   HOME_A,           HOME_E,           KC_SEMICOLON, KC_K,     HOME_H,         HOME_T,  HOME_N, HOME_S, KC_F,
        QK_LLCK, KC_QUOTE, KC_MINUS, KC_COMMA,         KC_DOT,           KC_SLASH,     KC_J,     KC_M,           KC_G,    KC_B,   KC_V,   QK_LLCK,
                                     LT(_SYM, KC_ESC), LT(_NUM, KC_SPC), MO(_NAV),     MO(_NUM), LT(_NAV, KC_R), MO(_SYM)
    ),

     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │ 3 │ 2 │ 1 │ ! │       │   │ { │ } │ ` │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ \ │ 0 │ 6 │ 5 │ 4 │   │       │   │ ( │ ) │ : │ # │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │ 9 │ 8 │ 7 │   │       │   │ [ │ ] │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │SYM├───┐           ┌───┤SYM│
      *               └───┤   ├───┐   ┌───┤NAV├───┘
      *                   └───┤NAV│   │   ├───┘
      *                       └───┘   └───┘
      */
    [_NUM] = LAYOUT_split_3x6_3(
        KC_NO,          KC_NO, KC_3, KC_2,      KC_1,           KC_EXLM, KC_NO,          KC_LCBR,        KC_RCBR,       KC_GRV,  KC_NO,   KC_NO,
        KC_BSLS,        KC_0,  KC_6, KC_5,      KC_4,           KC_NO,   KC_NO,          KC_LPRN,        KC_RPRN,       KC_COLN, KC_HASH, KC_NO,
        KC_TRANSPARENT, KC_NO, KC_9, KC_8,      KC_7,           KC_NO,   KC_NO,          KC_LBRC,        KC_RBRC,       KC_NO,   KC_NO,   KC_TRANSPARENT,
                                     TO(_BASE), KC_TRANSPARENT, QK_LLCK, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │ ~ │ = │ | │ ! │       │   │ { │ } │ ` │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ \ │ * │ @ │ $ │ + │   │       │   │ ( │ ) │ : │ # │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │ % │ & │ ^ │   │       │   │ [ │ ] │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤NUM├───┐   ┌───┤NAV├───┘
      *                   └───┤NAV│   │NUM├───┘
      *                       └───┘   └───┘
      */
    [_SYM] = LAYOUT_split_3x6_3(
        KC_NO,          KC_NO,   KC_TILD, KC_EQL,    KC_PIPE,        KC_EXLM, KC_NO,          KC_LCBR,        KC_RCBR, KC_GRV,  KC_NO,   KC_NO,
        KC_BSLS,        KC_ASTR, KC_AT,   KC_DLR,    KC_PLUS,        KC_NO,   KC_NO,          KC_LPRN,        KC_RPRN, KC_COLN, KC_HASH, KC_NO,
        KC_TRANSPARENT, KC_NO,   KC_PERC, KC_AMPR,   KC_CIRC,        KC_NO,   KC_NO,          KC_LBRC,        KC_RBRC, KC_NO,   KC_NO,   KC_TRANSPARENT,
                                          TO(_BASE), KC_TRANSPARENT, QK_LLCK, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO
    ),

     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │AUP│HME│ ↑ │END│PUP│       │   │ALT│ALT│ALT│ALT│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ADN│ ← │ ↓ │ → │PDN│       │   │ENT│TAB│DEL│BSP│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │SWB│SLN│SWD│   │       │   │SFT│SFT│SFT│SFT│   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │SYM├───┐           ┌───┤SYM│
      *               └───┤NUM├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │NUM├───┘
      *                       └───┘   └───┘
      */
    [_NAV] = LAYOUT_split_3x6_3(
        KC_NO,          LALT(KC_UP),   KC_HOME, KC_UP,     KC_END,         KC_PGUP, KC_NO,          RALT(KC_ENT), RALT(KC_TAB),  RALT(KC_DEL), RALT(KC_BSPC), KC_NO,
        KC_NO,          LALT(KC_DOWN), KC_LEFT, KC_DOWN,   KC_RGHT,        KC_PGDN, KC_NO,          KC_ENT,       KC_TAB,        KC_DEL,       KC_BSPC,       KC_NO,
        KC_TRANSPARENT, KC_NO,         SELWBAK, SELLINE,   SELWORD,        KC_NO,   KC_NO,          RSFT(KC_ENT), RSFT(KC_TAB),  RSFT(KC_DEL), RSFT(KC_BSPC), KC_TRANSPARENT,
                                                TO(_BASE), KC_TRANSPARENT, QK_LLCK, KC_TRANSPARENT, KC_NO,        KC_TRANSPARENT
    ),

    [_MOUSE] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,   KC_NO, MS_WHLU, MS_BTN1, MS_UP,   MS_BTN2, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, MS_BTN1,   MS_BTN2, KC_NO, MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
                             TO(_BASE), KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO
    )

     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */

};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

