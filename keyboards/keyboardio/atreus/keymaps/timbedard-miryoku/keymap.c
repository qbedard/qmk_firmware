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
#define _NUMSY 1
#define _NAV 2
#define _SHNUMSY 3
#define _MOUSE 4
#define _FUNC 5
#define _ADJUST 6

#define KC_XXXX KC_NO
#define KC_____ KC_TRNS
#define KC_RSET RESET
#define KC_ASPC A(KC_SPC)

// Home Mods
#define KC_ACTL LCTL_T(KC_A)
/* #define KC_AGUI LGUI_T(KC_A) */
#define KC_SALT LALT_T(KC_S)
#define KC_DGUI LGUI_T(KC_D)
/* #define KC_DCTL LCTL_T(KC_D) */
#define KC_FSFT LSFT_T(KC_F)

#define KC_JSFT LSFT_T(KC_J)
#define KC_KGUI LGUI_T(KC_K)
/* #define KC_KCTL LCTL_T(KC_K) */
#define KC_LALT LALT_T(KC_L)
#define KC_SCCT LCTL_T(KC_SCLN)
/* #define KC_SCGU LGUI_T(KC_SCLN) */

#define KC_ZSFT LSFT_T(KC_Z)

// Thumbs
#define KC_BSNV LT(_NAV, KC_BSPC)
#define KC_TBMS LT(_MOUSE, KC_TAB)

#define KC_SPNS LT(_NUMSY, KC_SPC)
#define KC_ENSN LT(_SHNUMSY, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc(
       Q,    W,    E,    R,    T,                Y,    U,    I,    O,    P,
    ACTL, SALT, DGUI, FSFT,    G,                H, JSFT, KGUI, LALT, SCCT,
    ZSFT,    X,    C,    V,    B, ____, ____,    N,    M, COMM,  DOT, SLSH,
    ____, ____, ____,  ESC, BSNV, TBMS, ENSN, SPNS,  DEL, ____, ____, ____
  ),

  [_NAV] = LAYOUT_kc(
    ____, ____, ____, ____, ____,             ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____,             LEFT, DOWN,   UP, RGHT, ASPC,
    ____, ____, ____, ____, ____, ____, ____, HOME, PGDN, PGUP,  END, ____,
    ____, ____, ____, ____, XXXX, ____, ____, ____, ____, ____, ____, ____
  ),

  [_MOUSE] = LAYOUT_kc(
    ____, ____, ____, ____, ____,             ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____,             MS_L, MS_D, MS_U, MS_R, ____,
    ____, ____, ____, ____, ____, ____, ____, WH_L, WH_D, WH_U, WH_R, ____,
    ____, ____, ____, ____, ____, XXXX, BTN1, BTN2, BTN3, ____, ____, ____
  ),

  [_FUNC] = LAYOUT_kc(
    ____, ____, ____, ____, ____,             ____,   F7,   F8,   F9,  F10,
    ____, ____, ____, ____, ____,             ____,   F4,   F5,   F6,  F11,
    ____, ____, ____, ____, ____, ____, ____, ____,   F1,   F2,   F3,  F12,
    ____, ____, ____, XXXX, ____, ____, ____, ____, ____, ____, ____, ____
  ),

  [_NUMSY] = LAYOUT_kc(
    LBRC,    7,    8,    9, RBRC,             ____, ____, ____, ____, ____,
    QUOT,    4,    5,    6,  EQL,             ____, ____, ____, ____, ____,
     GRV,    1,    2,    3, BSLS, ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____,  DOT,    0, MINS, ____, XXXX, ____, ____, ____, ____
  ),

  [_SHNUMSY] = LAYOUT_kc(
    LCBR, AMPR, ASTR, LPRN, RCBR,             ____, ____, ____, ____, ____,
    DQUO,  DLR, PERC, CIRC, PLUS,             ____, ____, ____, ____, ____,
    TILD, EXLM,   AT, HASH, PIPE, ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____,  DOT, RPRN, UNDS, XXXX, ____, ____, ____, ____, ____
  ),

  [_ADJUST] = LAYOUT_kc(
      F1,   F2,   F3,   F4,   F5,               F6,   F7,   F8,   F9,  F10,
    ____, ____, ____, ____, ____,             ____,   F4,   F5,   F6,  F11,
    ____, ____, ____, ____, RSET, ____, ____, ____,   F1,   F2,   F3,  F12,
    ____, ____, ____, ____, XXXX, ____, ____, XXXX, ____, ____, ____, ____
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _NUMSY, _ADJUST);
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* case KC_BSNV: */
        /*     return true; */
        case KC_SPNS:
            return true;
        default:
            return false;
    }
}
