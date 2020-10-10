#include QMK_KEYBOARD_H

#define LAYOUT_kc( \
  k00, k01, k02, k03, k04,           k05, k06, k07, k08, k09, \
  k10, k11, k12, k13, k14,           k15, k16, k17, k18, k19, \
  k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
  k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b \
) \
  LAYOUT( \
    KC_##k00, KC_##k01, KC_##k02, KC_##k03, KC_##k04,                     KC_##k05, KC_##k06, KC_##k07, KC_##k08, KC_##k09, \
    KC_##k10, KC_##k11, KC_##k12, KC_##k13, KC_##k14,                     KC_##k15, KC_##k16, KC_##k17, KC_##k18, KC_##k19, \
    KC_##k20, KC_##k21, KC_##k22, KC_##k23, KC_##k24, KC_##k25, KC_##k26, KC_##k27, KC_##k28, KC_##k29, KC_##k2a, KC_##k2b, \
    KC_##k30, KC_##k31, KC_##k32, KC_##k33, KC_##k34, KC_##k35, KC_##k36, KC_##k37, KC_##k38, KC_##k39, KC_##k3a, KC_##k3b \
  )

#define _QWERTY 0
#define _RAISE 1
#define _LOWER 2
#define _ADJUST 3

#define KC_MRAS MO(_RAISE)
#define KC_TLWR TG(_LOWER)
#define KC_TQWY TO(_QWERTY)
#define KC_RSET RESET
#define KC_XXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc(
       Q,    W,    E,    R,    T,                Y,    U,    I,    O,    P,
       A,    S,    D,    F,    G,                H,    J,    K,    L, SCLN,
       Z,    X,    C,    V,    B,  GRV,  DEL,    N,    M, COMM,  DOT, SLSH,
     ESC,  TAB, LGUI, LSFT, BSPC, LCTL, RALT,  SPC, MRAS, MINS, QUOT,  ENT
  ),

  [_RAISE] = LAYOUT_kc(
    EXLM, AT,   UP,   LCBR, RCBR,             PGUP,   P7,   P8,   P9, ASTR,
    HASH, LEFT, DOWN, RGHT, DLR,              PGDN,   P4,   P5,   P6, PLUS,
    LBRC, RBRC, LPRN, RPRN, AMPR, TILD,  DEL,  GRV,   P1,   P2,   P3, BSLS,
    TLWR,  INS, LGUI, LSFT, BSPC, LCTL, LALT,  SPC, TRNS,  DOT,   P0,  EQL
  ),

  [_LOWER] = LAYOUT_kc(
     INS,  HOME,   UP, END,  PGUP,             UP,     F7,   F8,   F9,  F10,
     DEL,  LEFT, DOWN, RGHT, PGDN,             DOWN,   F4,   F5,   F6,  F11,
    XXXX,  VOLU, XXXX, XXXX, RSET, XXXX, XXXX, XXXX,   F1,   F2,   F3,  F12,
    XXXX,  VOLD, LGUI, LSFT, BSPC, LCTL, LALT,  SPC, TQWY, PSCR, SLCK, PAUS
  )
};
