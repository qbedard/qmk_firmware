#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

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
#define KC_GTAB G(KC_TAB)
#define KC_XXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
     GRV,    1,    2,    3,    4,    5,                6,    7,    8,    9,    0, BSPC,
     TAB,    Q,    W,    E,    R,    T,                Y,    U,    I,    O,    P, BSLS,
    CESC,    A,    S,    D,    F,    G,                H,    J,    K,    L, SCLN,  ENT,
    LSFT,    Z,    X,    C,    V,    B, GTAB, ____,    N,    M, COMM,  DOT, SLSH, SQUO,
                            LGUI, BSLW, CESC, AENT, SPRS, CALT
  ),

  [_LOWER] = LAYOUT_kc(
    TILD, EXLM,   AT, HASH,  DLR, PERC,             CIRC, AMPR, ASTR, LPRN, RPRN, PGUP,
     GRV,    1,    2,    3,    4,    5,                6,    7,    8,    9,    0, PGDN,
    ____, ____, LEFT, RGHT,   UP, LBRC,             RBRC,   P4,   P5,   P6, PLUS, HOME,
    ____, ____, ____, ____, DOWN, LCBR, ____, ____, RCBR,   P1,   P2,   P3, MINS,  END,
                            ____, ____, XXXX, ____, ____,   P0
  ),

  [_RAISE] = LAYOUT_kc(
      F12,   F1,   F2,   F3,   F4,   F5,               F6,   F7,   F8,   F9,  F10,  F11,
     TILD, EXLM,   AT, HASH,  DLR, PERC,             CIRC, AMPR, ASTR, LPRN, RPRN, PIPE,
     ____, MPRV, MNXT, VOLU, PGUP, ____,             LEFT, DOWN,   UP, RGHT, ASPC, ____,
     ____, MSTP, MPLY, VOLD, PGDN, LPRN, ____, ____, RPRN, PLUS, MINS,  EQL, UNDS, ____,
                             ____, ____, ____, XXXX, ____, ____
  ),

  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______,  _______, _______, _______, _______, _______,
     KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,    KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    _______, BL_TOGG, BL_STEP, BL_BRTG,   BL_ON,  BL_INC,                   RGB_TOG,  RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
    _______, _______, _______, _______,  BL_OFF,  BL_DEC, _______, _______, _______, RGB_RMOD, RGB_HUD, RGB_SAD,
                               RGB_VAD, RGB_SPD, _______, _______, _______, _______,  _______, _______
  )
};

/* const rgblight_segment_t PROGMEM layer_lower[] = RGBLIGHT_LAYER_SEGMENTS( */
/*     {1, 6, HSV_BLUE} */
/* ); */
/* const rgblight_segment_t PROGMEM layer_raise[] = RGBLIGHT_LAYER_SEGMENTS( */
/*     {1, 6, HSV_YELLOW} */
/* ); */
/* const rgblight_segment_t PROGMEM layer_adjust[] = RGBLIGHT_LAYER_SEGMENTS( */
/*     {1, 6, HSV_GREEN} */
/* ); */
/* const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST( */
/*     layer_lower, */
/*     layer_raise, */
/*     layer_adjust */
/* ); */

/* void keyboard_post_init_user(void) { */
/*     rgblight_layers = rgb_layers; */
/* } */

layer_state_t layer_state_set_user(layer_state_t state) {
    /* rgblight_set_layer_state(1, layer_state_cmp(state, 1)); */
    /* rgblight_set_layer_state(2, layer_state_cmp(state, 2)); */
    /* rgblight_set_layer_state(3, layer_state_cmp(state, 3)); */
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code16(S(KC_TAB));
        } else {
            tap_code16(KC_TAB);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    }
}

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
