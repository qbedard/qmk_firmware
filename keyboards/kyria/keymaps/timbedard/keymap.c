#include QMK_KEYBOARD_H

#define LAYOUT_kc( \
  k00, k01, k02, k03, k04, k05,                     k06, k07, k08, k09, k0a, k0b, \
  k10, k11, k12, k13, k14, k15,                     k16, k17, k18, k19, k1a, k1b, \
  k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d, k2e, k2f, \
                 k30, k31, k32, k33, k34, k35, k36, k37, k38, k39 \
) \
  LAYOUT( \
    KC_##k00, KC_##k01, KC_##k02, KC_##k03, KC_##k04, KC_##k05,                                         KC_##k06, KC_##k07, KC_##k08, KC_##k09, KC_##k0a, KC_##k0b, \
    KC_##k10, KC_##k11, KC_##k12, KC_##k13, KC_##k14, KC_##k15,                                         KC_##k16, KC_##k17, KC_##k18, KC_##k19, KC_##k1a, KC_##k1b, \
    KC_##k20, KC_##k21, KC_##k22, KC_##k23, KC_##k24, KC_##k25, KC_##k26, KC_##k27, KC_##k28, KC_##k29, KC_##k2a, KC_##k2b, KC_##k28, KC_##k29, KC_##k2a, KC_##k2b, \
                                  KC_##k30, KC_##k31, KC_##k32, KC_##k33, KC_##k34, KC_##k35, KC_##k36, KC_##k37, KC_##k38, KC_##k39 \
  )

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define KC_____ KC_TRNS
#define KC_LOWR MO(_LOWER)
#define KC_RAIS MO(_RAISE)
#define KC_SPLW LT(_LOWER, KC_SPC)
#define KC_SPRS LT(_RAISE, KC_SPC)
#define KC_BSLW LT(_LOWER, KC_BSPC)
#define KC_CESC CTL_T(KC_ESC)
#define KC_AENT ALT_T(KC_ENT)
#define KC_SQUO SFT_T(KC_QUOT)
#define KC_CALT C(KC_LALT)
#define KC_ASPC A(KC_SPC)
#define KC_XXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
     TAB,    Q,    W,    E,    R,    T,                            Y,    U,    I,    O,    P, BSPC,
    CESC,    A,    S,    D,    F,    G,                            H,    J,    K,    L, SCLN,  ENT,
    LSFT,    Z,    X,    C,    V,    B, ____, ____, ____, ____,    N,    M, COMM,  DOT, SLSH, SQUO,
                      ____, ____, LGUI, BSLW, CESC, AENT, SPRS, CALT, ____, ____
  ),

  [_LOWER] = LAYOUT_kc(
    TILD, EXLM,   AT, HASH,  DLR, PERC,                         CIRC, AMPR, ASTR, LPRN, RPRN, PIPE,
    ____, ____, LEFT, RGHT,   UP, LBRC,                         RBRC, MINS, PLUS, LBRC, RBRC, ____,
    ____, ____, ____, ____, DOWN, LCBR, ____, ____, ____, ____, RCBR, UNDS, EQL,  LCBR, RCBR, ____,
                      ____, ____, ____, XXXX, ____, ____, ____,   P0, ____, ____
  ),

  [_RAISE] = LAYOUT_kc(
     GRV,    1,    2,    3,    4,    5,                            6,    7,    8,    9,    0, BSLS,
    ____, MPRV, MNXT, VOLU, PGUP, ____,                         LEFT, DOWN,   UP, RGHT, ASPC, ____,
    ____, MSTP, MPLY, VOLD, PGDN, LPRN, ____, ____, ____, ____, RPRN, PLUS, MINS,  EQL, UNDS, ____,
                      ____, ____, ____, ____, ____, ____, XXXX, ____, ____, ____
  ),

  [_ADJUST] = LAYOUT(
     KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,    KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    _______, BL_TOGG, BL_STEP, BL_BRTG,   BL_ON,  BL_INC,                                     RGB_TOG,  RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
    _______, _______, _______, _______,  BL_OFF,  BL_DEC, _______, _______, _______, _______, _______, RGB_RMOD, RGB_HUD, RGB_SAD, _______, _______,
                               RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______, _______, _______
  ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SPLW:
            return true;
        case KC_SPRS:
            return true;
        case KC_SQUO:
            return true;
        default:
            return false;
    }
}
