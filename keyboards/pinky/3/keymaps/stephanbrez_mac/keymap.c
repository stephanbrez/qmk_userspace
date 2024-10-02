/* Copyright 2018 'Masayuki Sunahara'
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x7_4(
      T_ESCUNDO, T_QESC, KC_W, KC_F, KC_P, KC_B, KC_LPRN,                           KC_RPRN, KC_J, KC_L, KC_U, KC_Y, KC_QUOTE, KC_BSPC,
      T_TAB, KC_A, LT(5,KC_R), LT(1,KC_S), LT(3,KC_T), KC_G, T_LBRC,                T_RBRC, KC_M, LT(4,KC_N), LT(2,KC_E), LT(6,KC_I), HOME_O, KC_QUOT,
      T_LSFT, KC_Z, KC_X, HOME_C, HOME_D, KC_V, KC_SPACE,                           KC_TRNS, HOME_K, HOME_H, HOME_COM, KC_DOT, KC_SLSH, KC_ENT,
      KC_LCTL, KC_LALT, HOME_TAB, HOME_SPC,                                         KC_ENT, T_BSPC, KC_RGUI, KC_RALT
    ),
    [1] = LAYOUT_split_3x7_4(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_PSLS, KC_7, KC_8, KC_9, KC_PPLS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_PAST, KC_4, KC_5, KC_6, KC_PMNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_GRAVE, KC_1, KC_2, KC_3, KC_PEQL, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                           KC_TRNS, KC_0, KC_TRNS, KC_TRNS
    ),
    [2] = LAYOUT_split_3x7_4(
      KC_TRNS, KC_HOME, KC_PGUP, T_UP, KC_PGDN, KC_END, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_LCAP, T_LEFT, T_DOWN, T_RIGHT, KC_INS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_RALT, LCA(KC_LSFT), KC_TRNS,
      KC_TRNS, LSG(KC_Z), KC_CUT, KC_COPY, KC_PASTE, KC_UNDO, KC_TRNS,              KC_TRNS, KC_TRNS, KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                           KC_TILD, T_ESCUNDO, KC_TRNS, KC_TRNS
    ),
    [3] = LAYOUT_split_3x7_4(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_AMPR, KC_ASTR, KC_PIPE, KC_DQUO, KC_QUOTE, KC_TRNS,
      KC_TRNS, KC_CIRC, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS,                  KC_TRNS, KC_CIRC, KC_MINS, KC_UNDS, KC_DQUO, KC_DLR, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_PERC, KC_TILD,  KC_GRV, KC_BSLS, KC_SLSH, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                           KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS
    ),
    [4] = LAYOUT_split_3x7_4(
      KC_TRNS, KC_LT,   KC_GT, KC_COLN, KC_SCLN, KC_HASH, KC_TRNS,                  KC_TRNS, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_LCBR, KC_LPRN, KC_RPRN, KC_AT, KC_TRNS,                  KC_TRNS, KC_VOLD, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_RCBR, KC_LBRC, KC_RBRC, KC_EXLM, KC_TRNS,                KC_TRNS, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                           KC_TRNS, KC_ENT,  KC_TRNS, KC_TRNS
    ),
    [5] = LAYOUT_split_3x7_4(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F12, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_F4, KC_F5, KC_F6, KC_F11, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F10, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [6] = LAYOUT_split_3x7_4(
      KC_TRNS, KC_TRNS, KC_WH_D, KC_MS_U, KC_WH_U, KC_BTN3, KC_TRNS,                KC_TRNS, KC_TRNS, LGUI(KC_LBRC), LGUI(KC_RBRC),KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_TRNS,                KC_TRNS, KC_TRNS, KC_BTN2, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_WH_L, KC_BTN2, KC_WH_R, KC_BTN2, KC_TRNS,                KC_TRNS, KC_TRNS, KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [7] = LAYOUT_split_3x7_4(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_COLN, KC_ESC, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_PERC, KC_SLSH, KC_ENT, KC_TRNS, KC_TRNS,                 KC_TRNS, DF(1), KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EXLM, KC_TRNS, KC_TRNS,                KC_TRNS, DF(0), KC_TRNS, RALT_T(KC_COMM), RCTL_T(KC_DOT), KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TAB, KC_TRNS, KC_TRNS,                                            KC_NO, KC_TRNS, KC_TRNS, KC_TRNS
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
