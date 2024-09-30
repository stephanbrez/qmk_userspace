#pragma once

#include "quantum.h"

// Shortcut Keys

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
  bool is_press_action;
  td_state_t state;
} td_tap_t;

//Tap Dance declarations
enum
{
  TD_LBRC_BACK,
  TD_RBRC_FWD,
  TD_REFRESH,
  TD_ESC_UNDO,
  TD_Q_ESC,
  TD_ENDHOME,
  TD_TAB,
  TD_BSPC,
  TD_UP,
  TD_DOWN,
  TD_RIGHT,
  TD_LEFT,
  TD_LSFT
};

// Keycodes for Tap Dances
#define T_LBRC      TD(TD_LBRC_BACK)
#define T_RBRC      TD(TD_RBRC_FWD)
#define T_REFRESH   TD(TD_REFRESH)
#define T_ESCUNDO   TD(TD_ESC_UNDO)
#define T_QESC      TD(TD_Q_ESC)
#define T_ENDHOME   TD(TD_ENDHOME)
#define T_TAB       TD(TD_TAB)
#define T_BSPC      TD(TD_BSPC)
#define T_UP        TD(TD_UP)
#define T_DOWN      TD(TD_DOWN)
#define T_RIGHT     TD(TD_RIGHT)
#define T_LEFT      TD(TD_LEFT)
#define T_LSFT      TD(TD_LSFT)
