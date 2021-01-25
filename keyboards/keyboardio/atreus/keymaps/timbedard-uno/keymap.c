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
#define _FUN 1
#define _UPPER 2
#define _RAISE 3
#define _LOWER 4
#define _ADJUST 5

#define KC_FUN MO(_FUN)
#define KC_TGUP TG(_UPPER)
#define KC_TQWY TO(_QWERTY)
#define KC_RSET RESET
#define KC_XXXX KC_NO
#define KC_____ KC_TRNS

#define KC_SPRS LT(_RAISE, KC_SPC)
#define KC_BSLW LT(_LOWER, KC_BSPC)
#define KC_CESC LCTL_T(KC_ESC)
#define KC_AENT LALT_T(KC_ENT)
#define KC_ASPC A(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc(
       Q,    W,    E,    R,    T,                Y,    U,    I,    O,    P,
       A,    S,    D,    F,    G,                H,    J,    K,    L, SCLN,
       Z,    X,    C,    V,    B,  GRV, BSLS,    N,    M, COMM,  DOT, SLSH,
     ESC,  TAB, LGUI, LSFT, BSLW, CESC, AENT, SPRS,  FUN, MINS, QUOT,  ENT
  ),

  // Keyboardio Atreus Layers
  [_FUN] = LAYOUT_kc(
    EXLM,   AT,   UP,  DLR, PERC,             PGUP,   P7,   P8,   P9, BSPC,
    LPRN, LEFT, DOWN, RGHT, RPRN,             PGDN,   P4,   P5,   P6, ____,
    LBRC, RBRC, HASH, LCBR, RCBR, CIRC, AMPR, ASTR,   P1,   P2,   P3, PLUS,
    TGUP,  INS, ____, ____, ____, ____, ____, ____, XXXX,  DOT,   P0,  EQL
  ),

  [_UPPER] = LAYOUT_kc(
     INS, HOME,   UP, END,  PGUP,             UP,     F7,   F8,   F9,  F10,
     DEL, LEFT, DOWN, RGHT, PGDN,             DOWN,   F4,   F5,   F6,  F11,
    ____, VOLU, ____, ____, ____, ____, ____, ____,   F1,   F2,   F3,  F12,
    ____, VOLD, ____, ____, BSPC, ____, ____,  SPC, TQWY, PSCR, SLCK, PAUS
  ),

  // Planck-ish Layers
  [_LOWER] = LAYOUT_kc(
    EXLM,   AT, HASH,  DLR, PERC,             CIRC, AMPR, ASTR, LPRN, RPRN,
    ____, ____, ____, ____, ____,             DOWN, MINS, PLUS, LBRC, RBRC,
    ____, ____, ____, ____, ____, TILD, PIPE, ____, UNDS,  EQL, LCBR, RCBR,
    ____, ____, ____, ____, XXXX, ____, ____,  SPC, ____, ____, ____, ____
  ),

  [_RAISE] = LAYOUT_kc(
       1,    2,    3,    4,    5,                6,    7,    8,    9,    0,
    ____, ____, ____, ____, ____,             LEFT, DOWN,   UP, RGHT, ASPC,
    ____, ____, ____, ____, ____, ____, ____, HOME, PGDN, PGUP,  END, ____,
    ____, ____, ____, ____, ____, ____, ____, XXXX, ____, ____, ____, ____
  ),

  [_ADJUST] = LAYOUT_kc(
      F1,   F2,   F3,   F4,   F5,               F6,   F7,   F8,   F9,  F10,
    ____, ____, ____, ____, ____,             ____,   F4,   F5,   F6,  F11,
    ____, ____, ____, ____, RSET, ____, ____, ____,   F1,   F2,   F3,  F12,
    ____, ____, ____, ____, XXXX, ____, ____, XXXX, ____, ____, ____, ____
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* case KC_BSLW: */
        /*     return true; */
        case KC_SPRS:
            return true;
        default:
            return false;
    }
}
