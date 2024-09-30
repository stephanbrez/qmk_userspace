/* Copyright 2022 @stephanbrez
 *
 * All the tapdances and custom keycodes
 */
#include "stephanbrez.h"

//// BEGIN: Advanced Tap Dances
/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.


 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 *
 * For the third point, there does exist the 'TD_DOUBLE_TD_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

/**************** QUAD FUNCTION FOR TAB ****************/
// TAB, TAB TAB, CMD + SHIFT, ALT + SHIFT,
static td_tap_t tab_state = {
  .is_press_action = true,
  .state = TD_NONE
};

void tab_finished (tap_dance_state_t *state, void *user_data) {
  tab_state.state = cur_dance(state);
  switch (tab_state.state) {
    case TD_SINGLE_TAP: register_code(KC_TAB); break;  //send tab on single press
    case TD_SINGLE_HOLD: register_code16(LGUI(KC_LSFT)); break; //cmd shift on single hold
    case TD_DOUBLE_TAP: register_code(KC_TAB); unregister_code(KC_TAB); register_code(KC_TAB); break; //tab tab
    case TD_DOUBLE_HOLD: register_code16(LALT(KC_LSFT)); break; //alt shift on double hold
    case TD_TRIPLE_TAP: register_code(KC_LSFT) ;register_code(KC_ESC); break;
    default: break;
  }
}

void tab_reset (tap_dance_state_t *state, void *user_data) {
  switch (tab_state.state) {
    case TD_SINGLE_TAP: unregister_code(KC_TAB); break; //unregister tab
    case TD_SINGLE_HOLD: unregister_code16(LGUI(KC_LSFT)); break;
    case TD_DOUBLE_TAP: unregister_code(KC_TAB); break;
    case TD_DOUBLE_HOLD: unregister_code16(LALT(KC_LSFT)); break; //let go of alt shift
    case TD_TRIPLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_ESC); break;
    default: break;
  }
  tab_state.state = TD_NONE;
}
/**************** QUAD FUNCTION FOR TAB ****************/

/**************** QUAD FUNCTION FOR BACKSPACE ****************/
// BACKSPACE, BACKSPACE + ALT, BACKSPACE BACKSPACE, BACKSPACE + CMD, CTRL + K
static td_tap_t bspc_state = {
  .is_press_action = true,
  .state = TD_NONE
};

void bspc_finished (tap_dance_state_t *state, void *user_data) {
  bspc_state.state = cur_dance(state);
  switch (bspc_state.state) {
    case TD_SINGLE_TAP: register_code(KC_BSPC); break;  //send backspace on single press
    case TD_SINGLE_HOLD: register_code16(LALT(KC_BSPC)); break; // alt backspace on single hold
	case TD_DOUBLE_TAP: tap_code(KC_BSPC); register_code(KC_BSPC); break; //backspace backspace
    case TD_DOUBLE_HOLD: register_code16(LGUI(KC_BSPC)); break; //cmd backspace on double tap hold
    case TD_TRIPLE_TAP: tap_code16(LGUI(KC_K)); break; // cmd + k
    default: break;
  }
}

void bspc_reset (tap_dance_state_t *state, void *user_data) {
  switch (bspc_state.state) {
    case TD_SINGLE_TAP: unregister_code(KC_BSPC); break; //unregister backspace
	case TD_SINGLE_HOLD: unregister_code16(LALT(KC_BSPC)); break;
	case TD_DOUBLE_TAP: unregister_code(KC_BSPC); break;
    case TD_DOUBLE_HOLD: unregister_code16(LGUI(KC_BSPC)); break; //let go of cmd backspace
    default: break;
  }
  bspc_state.state = TD_NONE;
}
/**************** QUAD FUNCTION FOR BACKSPACE ****************/

/**************** QUAD FUNCTION FOR UP ****************/
// UP, UP + SHIFT, UP + CMD, UP + CMD + SHIFT
static td_tap_t up_state = {
  .is_press_action = true,
  .state = TD_NONE
};

void up_finished (tap_dance_state_t *state, void *user_data) {
  up_state.state = cur_dance(state);
  switch (up_state.state) {
    case TD_SINGLE_TAP: register_code(KC_UP); break;  //send up on single press
    case TD_SINGLE_HOLD: register_code16(LSFT(KC_UP)); break; // up shift on single hold
	case TD_DOUBLE_TAP: tap_code16(LGUI(KC_UP)); break; //up cmd
    case TD_DOUBLE_HOLD: register_code(KC_LSFT); register_code16(LGUI(KC_UP)); break; //up cmd shift on double tap hold
    default: break;
  }
}

void up_reset (tap_dance_state_t *state, void *user_data) {
  switch (up_state.state) {
    case TD_SINGLE_TAP: unregister_code(KC_UP); break; //unregister up
	case TD_SINGLE_HOLD: unregister_code16(LSFT(KC_UP)); break;
    case TD_DOUBLE_HOLD: unregister_code(KC_LSFT); unregister_code16(LGUI(KC_UP)); break; //let go of cmd shift up
    default: break;
  }
  up_state.state = TD_NONE;
}
/**************** QUAD FUNCTION FOR UP ****************/

/**************** QUAD FUNCTION FOR DOWN ****************/
// DOWN, DOWN + SHIFT, DOWN + CMD, DOWN + CMD + SHIFT
static td_tap_t down_state = {
  .is_press_action = true,
  .state = TD_NONE
};

void down_finished (tap_dance_state_t *state, void *user_data) {
  down_state.state = cur_dance(state);
  switch (down_state.state) {
    case TD_SINGLE_TAP: register_code(KC_DOWN); break;  //send up on single press
    case TD_SINGLE_HOLD: register_code16(LSFT(KC_DOWN)); break; // up shift on single hold
	case TD_DOUBLE_TAP: tap_code16(LGUI(KC_DOWN)); break; //up cmd
    case TD_DOUBLE_HOLD: register_code(KC_LSFT); register_code16(LGUI(KC_DOWN)); break; //up cmd shift on double tap hold
    default: break;
  }
}

void down_reset (tap_dance_state_t *state, void *user_data) {
  switch (down_state.state) {
    case TD_SINGLE_TAP: unregister_code(KC_DOWN); break; //unregister up
	case TD_SINGLE_HOLD: unregister_code16(LSFT(KC_DOWN)); break;
    case TD_DOUBLE_HOLD: unregister_code(KC_LSFT); unregister_code16(LGUI(KC_DOWN)); break; //let go of cmd shift up
    default: break;
  }
  down_state.state = TD_NONE;
}
/**************** QUAD FUNCTION FOR DOWN ****************/

/**************** QUAD FUNCTION FOR RIGHT ****************/
// RIGHT, RIGHT + SHIFT, RIGHT + CMD, RIGHT + CMD + SHIFT, CTRL + E
static td_tap_t right_state = {
  .is_press_action = true,
  .state = TD_NONE
};

void right_finished (tap_dance_state_t *state, void *user_data) {
  right_state.state = cur_dance(state);
  switch (right_state.state) {
    case TD_SINGLE_TAP: register_code(KC_RIGHT); break;  //send right on single press
    case TD_SINGLE_HOLD: register_code16(LSFT(KC_RIGHT)); break; // right shift on single hold
	case TD_DOUBLE_TAP: tap_code16(LGUI(KC_RIGHT)); break; //right cmd
    case TD_DOUBLE_HOLD: register_code(KC_LSFT); register_code16(LGUI(KC_RIGHT)); break; //right cmd shift on double tap hold
	case TD_TRIPLE_TAP: tap_code16(LCTL(KC_E)); break; // ctrl + e
    default: break;
  }
}

void right_reset (tap_dance_state_t *state, void *user_data) {
  switch (right_state.state) {
    case TD_SINGLE_TAP: unregister_code(KC_RIGHT); break; //unregister up
	case TD_SINGLE_HOLD: unregister_code16(LSFT(KC_RIGHT)); break;
    case TD_DOUBLE_HOLD: unregister_code(KC_LSFT); unregister_code16(LGUI(KC_RIGHT)); break; //let go of cmd shift up
    default: break;
  }
  right_state.state = TD_NONE;
}
/**************** QUAD FUNCTION FOR RIGHT ****************/

/**************** QUAD FUNCTION FOR LEFT ****************/
// LEFT, LEFT + SHIFT, LEFT + CMD, LEFT + CMD + SHIFT, CTRL + E
static td_tap_t left_state = {
  .is_press_action = true,
  .state = TD_NONE
};

void left_finished (tap_dance_state_t *state, void *user_data) {
  left_state.state = cur_dance(state);
  switch (left_state.state) {
    case TD_SINGLE_TAP: register_code(KC_LEFT); break;  //send right on single press
    case TD_SINGLE_HOLD: register_code16(LSFT(KC_LEFT)); break; // right shift on single hold
	case TD_DOUBLE_TAP: tap_code16(LGUI(KC_LEFT)); break; //right cmd
    case TD_DOUBLE_HOLD: register_code(KC_LSFT); register_code16(LGUI(KC_LEFT)); break; //right cmd shift on double tap hold
	case TD_TRIPLE_TAP: tap_code16(LCTL(KC_A)); break; // ctrl + a
    default: break;
  }
}

void left_reset (tap_dance_state_t *state, void *user_data) {
  switch (left_state.state) {
    case TD_SINGLE_TAP: unregister_code(KC_LEFT); break; //unregister up
	case TD_SINGLE_HOLD: unregister_code16(LSFT(KC_LEFT)); break;
    case TD_DOUBLE_HOLD: unregister_code(KC_LSFT); unregister_code16(LGUI(KC_LEFT)); break; //let go of cmd shift up
    default: break;
  }
  left_state.state = TD_NONE;
}
/**************** QUAD FUNCTION FOR LEFT ****************/

/**************** QUAD FUNCTION FOR LSHIFT ****************/
// `, SHIFT, CAPS
static td_tap_t lshift_state = {
  .is_press_action = true,
  .state = TD_NONE
};

void lshift_finished (tap_dance_state_t *state, void *user_data) {
  lshift_state.state = cur_dance(state);
  switch (lshift_state.state) {
    case TD_SINGLE_TAP: register_code(KC_GRV); break;  //send `
    case TD_SINGLE_HOLD: register_code(KC_LSFT); break; //  shift on single hold
	case TD_DOUBLE_TAP: tap_code(KC_CAPS); break; //caps lock
    default: break;
  }
}

void lshift_reset (tap_dance_state_t *state, void *user_data) {
  switch (lshift_state.state) {
    case TD_SINGLE_TAP: unregister_code(KC_GRV); break; //unregister `
	case TD_SINGLE_HOLD: unregister_code(KC_LSFT); break;
    default: break;
  }
  lshift_state.state = TD_NONE;
}
/**************** QUAD FUNCTION FOR LSHIFT ****************/
//// END: Advanced Tap Dances

// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  // simple tap dances
    [TD_LBRC_BACK]  	= ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LGUI(KC_LBRC)),  // Tap for [, double tap for back browser
    [TD_RBRC_FWD] 		= ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LGUI(KC_RBRC)),  // Tap for ], double tap for forward browser
    [TD_REFRESH]  		= ACTION_TAP_DANCE_DOUBLE(KC_R,LCTL(KC_R)), // Tap for R, double tap for Cmd + R
    [TD_ESC_UNDO]   	= ACTION_TAP_DANCE_DOUBLE(KC_ESC, LGUI(KC_Z)),  // Tap for ESC, double tap for Cmd + Z
    [TD_Q_ESC]    = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),  // Tap for Q, double tap for ESC
    [TD_ENDHOME]  = ACTION_TAP_DANCE_DOUBLE(KC_END, KC_HOME), // Tap for END, double tap for HOME

	// Advanced Tap Dances
    [TD_TAB] 		= ACTION_TAP_DANCE_FN_ADVANCED(NULL, tab_finished, tab_reset),
    [TD_BSPC]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bspc_finished, bspc_reset),
    [TD_UP]    	= ACTION_TAP_DANCE_FN_ADVANCED(NULL, up_finished, up_reset), // Tap for up, hold to select up, double tap to jump to top, tap hold to push up
    [TD_DOWN]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, down_finished, down_reset),
	[TD_RIGHT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, right_finished, right_reset),
	[TD_LEFT]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, left_finished, left_reset),
	[TD_LSFT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lshift_finished, lshift_reset)
};
