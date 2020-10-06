#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _RAISE 1
#define _LOWER 2
#define _ADJUST 3

#define KC_MRAS MO(_RAISE)
#define KC_TLWR TG(_LOWER)
#define KC_TQWY TO(_QWERTY)
#define KC_RSET KC_RESET
#define KC_XXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc(
       Q,    W,    E,    R,    T,                Y,    U,    I,    O,    P,
       A,    S,    D,    F,    G,                H,    J,    K,    L, SCLN,
       Z,    X,    C,    V,    B,  GRV,  DEL,    N,    M, COMM,  DOT, SLSH,
     ESC,  TAB, LGUI, LSFT, BSPC, LCTL, RALT,  SPC, MRAS, MINS, QUOT,  ENT
  ),

  [_RAISE] = LAYOUT_kc(
    EXLM, AT,   UP,   LCBR, RCBR,             PGUP,   7,    8,   9, ASTR,
    HASH, LEFT, DOWN, RGHT, DLR,              PGDN,   4,    5,   6, PLUS,
    LBRC, RBRC, LPRN, RPRN, AMPR,              GRV,   1,    2,   3, BSLS,
    TLWR,  INS, LGUI, LSFT, BSPC, LCTL, LALT,  SPC, TRNS, DOT,   0,  EQL
  ),

  [_LOWER] = LAYOUT(
     INS,  HOME,   UP, END,  PGUP,             UP,     F7,   F8,   F9,  F10,
     DEL,  LEFT, DOWN, RGHT, PGDN,             DOWN,   F4,   F5,   F6,  F11,
    XXXX,  VOLU, XXXX, XXXX, RSET,             XXXX,   F1,   F2,   F3,  F12,
    XXXX,  VOLD, LGUI, LSFT, BSPC, LCTL, LALT,  SPC, TQWY, PSCR, SLCK, PAUS
  )
};
