/* Copyright 2022 @birchbeast
 *
 * Ferris Sweep Keymap
 */

#include QMK_KEYBOARD_H
#include "birchbeast.h"

/* Define home row mods for easy OS switching  */
// Left-hand home row mods
#define HOME_C LCTL_T(KC_C)       // or LGUI_T(KC_C)
#define HOME_D LALT_T(KC_D)
#define HOME_TAB LGUI_T(KC_TAB)   // or LCTL_T(KC_TAB)
#define HOME_SPC LSFT_T(KC_SPC)

// Right-hand home row mods
#define HOME_K RGUI_T(KC_K)       // or RCTL_T(KC_K)
#define HOME_H LALT_T(KC_H)
#define HOME_COM RCTL_T(KC_COMM)  // or RGUI_T(KC_COMM)
#define HOME_O RSFT_T(KC_O)

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
    _0,
    _NUM,
    _NAV,
    _L1,
    _R1,
    _FN,
    _MOUSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_0] = LAYOUT(
      T_QESC, KC_W, KC_F, KC_P, KC_B,                                   KC_J, KC_L, KC_U, KC_Y, KC_QUOTE,
      LSFT_T(KC_A), LT(5,KC_R), LT(1,KC_S), LT(3,KC_T), KC_G,           KC_M, LT(4,KC_N), LT(2,KC_E), LT(6,KC_I), LSFT_T(KC_O),
      KC_Z, KC_X, LCTL_T(KC_C), LALT_T(KC_D), KC_V,                     RGUI_T(KC_K), LALT_T(KC_H), LCTL_T(KC_COMM), KC_DOT, KC_SLSH,
      LGUI_T(KC_TAB), LSFT_T(KC_SPC),                                   KC_ENT, T_BSPC
    ),
    [_L1] = LAYOUT(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_AMPR, KC_ASTR, KC_PIPE, KC_DQUO, KC_QUOTE,
      KC_CIRC, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS,                        KC_CIRC, KC_MINS, KC_UNDS, KC_DQUO, KC_DLR,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_PERC, KC_TILD,  KC_GRV, KC_BSLS, KC_SLSH,
      KC_TRNS, KC_TRNS,                                                 KC_TRNS, KC_DEL
    ),
    [_NUM] = LAYOUT(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_PSLS, KC_7, KC_8, KC_9, KC_PPLS,
      KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS,                      KC_PAST, KC_4, KC_5, KC_6, KC_PMNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_GRAVE, KC_1, KC_2, KC_3, KC_PEQL,
      KC_TRNS, KC_TRNS,                                                 KC_TRNS, KC_0
    ),
    [_FN] = LAYOUT(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F12,
      KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_F4, KC_F5, KC_F6, KC_F11,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F10,
      KC_TRNS, KC_TRNS,                                                 KC_TRNS, KC_TRNS
    ),
    [_R1] = LAYOUT(
      KC_LT, KC_GT, KC_COLN, KC_SCLN, KC_HASH,                          KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_LCBR, KC_LPRN, KC_RPRN, KC_AT,                        KC_VOLD, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_RCBR, KC_LBRC, KC_RBRC, KC_EXLM,                      KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,                                                 KC_TRNS, KC_TRNS
    ),
    [_NAV] = LAYOUT(
      KC_HOME, KC_PGUP, T_UP, KC_PGDN, KC_END,                          KC_TRNS, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_LCAP, T_LEFT, T_DOWN, T_RIGHT, KC_INS,                         KC_TRNS, KC_TRNS, KC_NO,   KC_RALT, LCA(KC_LSFT),
      LSG(KC_Z), KC_CUT, KC_COPY, KC_PASTE, KC_UNDO,                    KC_TRNS, KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,                                                 KC_TILD, T_ESCUNDO
    ),
    [_MOUSE] = LAYOUT(
      KC_TRNS, KC_WH_D, KC_MS_U, KC_WH_U, KC_BTN3,                      KC_TRNS, LGUI(KC_LBRC), LGUI(KC_RBRC),KC_TRNS, KC_TRNS,
      KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,                      KC_TRNS, KC_BTN2, KC_BTN1, KC_NO,   KC_TRNS,
      KC_TRNS, KC_WH_L, KC_BTN2, KC_WH_R, KC_BTN2,                      KC_TRNS, KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,                                                 KC_TRNS, KC_TRNS
    )
};

// Customize retro tapping
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_SPC):
            return false;
        case LGUI_T(KC_TAB):
            return false;
        default:
            return false;
    }
}
// Set a short tapping term for all tap-dance keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return TAPPING_TERM - 50;         // Use relative value
        default:
            return TAPPING_TERM;
    }
}
