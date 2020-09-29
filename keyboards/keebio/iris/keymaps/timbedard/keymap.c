#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, \
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, \
    LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, \
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_GRV, KC_DEL, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_QUOT), \
    KC_LALT, KC_LGUI, LT(_LOWER, KC_SPC), LT(_RAISE, KC_SPC), C(KC_LALT), KC_ENT \
  ),

  [_LOWER] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP, \
    _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_PGDN, \
    _______, _______, KC_LEFT, KC_RGHT, KC_UP, KC_LBRC, KC_RBRC, KC_P4, KC_P5, KC_P6, KC_PLUS, KC_HOME, \
    _______, _______, _______, _______, KC_DOWN, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_P1, KC_P2, KC_P3, KC_MINS, KC_END, \
    _______, _______, KC_NO, _______, _______, KC_P0 \
  ),

  [_RAISE] = LAYOUT(
    KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, \
    _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    _______, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, RGB_SAD, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, LALT(KC_SPC), _______, \
    _______, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_LPRN, KC_END, _______, KC_RPRN, KC_PLUS, KC_MINS, KC_EQL, KC_UNDS, _______, \
    _______, _______, _______, KC_NO, _______, _______ \
  ),

  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, BL_TOGG, BL_STEP, BL_BRTG, BL_ON, BL_INC, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, \
    _______, _______, _______, _______, BL_OFF, BL_DEC, _______, _______, _______, RGB_RMOD, RGB_HUD, RGB_SAD, \
    RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______ \
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
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
