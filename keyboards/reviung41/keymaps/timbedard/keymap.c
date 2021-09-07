#include QMK_KEYBOARD_H

#define LAYOUT_kc( \
    K00, K01, K02, K03, K04, K05,      K30, K31, K32, K33, K34, K35, \
    K10, K11, K12, K13, K14, K15,      K40, K41, K42, K43, K44, K45, \
    K20, K21, K22, K23, K24, K25,      K50, K51, K52, K53, K54, K55, \
                        K60, K61, K62, K63, K64 \
) \
  LAYOUT_reviung41( \
    KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05,      KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, \
    KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15,      KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, \
    KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25,      KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54, KC_##K55, \
                        KC_##K60, KC_##K61, KC_##K62, KC_##K63, KC_##K64 \
  )

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum {
  TD_ALT_CALT,
  TD_GUI_CALT,
};

#define KC_____ KC_TRNS
#define KC_SPRS LT(_RAISE, KC_SPC)
#define KC_BSLW LT(_LOWER, KC_BSPC)
#define KC_CESC CTL_T(KC_ESC)
#define KC_SQUO SFT_T(KC_QUOT)
#define KC_ASPC A(KC_SPC)
#define KC_TACA TD(TD_ALT_CALT)
#define KC_TGCA TD(TD_GUI_CALT)
#define KC_XXXX KC_NO

void dance_calt_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_RALT);
    } else {
        register_code(KC_LCTL);
        register_code(KC_RALT);
    }
}

void dance_calt_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_RALT);
    } else {
        unregister_code(KC_LCTL);
        unregister_code(KC_RALT);
    }
}

void dance_galt_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_LGUI);
    } else {
        register_code(KC_LCTL);
        register_code(KC_RALT);
    }
}

void dance_galt_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_LGUI);
    } else {
        unregister_code(KC_LCTL);
        unregister_code(KC_RALT);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ALT_CALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_calt_finished, dance_calt_reset),
  [TD_GUI_CALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_galt_finished, dance_galt_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc(
     TAB,    Q,    W,    E,    R,    T,          Y,    U,    I,    O,    P, BSPC,
    CESC,    A,    S,    D,    F,    G,          H,    J,    K,    L, SCLN,  ENT,
    LSFT,    Z,    X,    C,    V,    B,          N,    M, COMM,  DOT, SLSH, SQUO,
                            TGCA, BSLW,  SPC, SPRS, TACA
  ),

  [_LOWER] = LAYOUT_kc(
    TILD, EXLM,   AT, HASH,  DLR, PERC,       CIRC, AMPR, ASTR, LPRN, RPRN, PIPE,
    ____, UNDS, PLUS, LCBR, RCBR, PIPE,       LEFT, DOWN,   UP, RGHT, ASPC, ____,
    ____,  ESC, LGUI, LALT, CAPS, DQUO,       RPRN, PLUS, MINS,  EQL, UNDS, DQUO,
                            ____, XXXX,  ENT, ____, ____
  ),

  [_LOWER] = LAYOUT_kc(
    TILD, EXLM,   AT, HASH,  DLR, PERC,       CIRC, AMPR, ASTR, LPRN, RPRN, PIPE,
    ____, LCTL, LALT, LGUI, LSFT, ____,       LEFT, DOWN,   UP, RGHT, ASPC, ____,
    ____, ____, ____, ____, ____, ____,       HOME, PGDN, PGUP,  END, ____, DQUO,
                            ____, XXXX,  ENT, ____, ____
  ),

  [_RAISE] = LAYOUT_kc(
     GRV,    1,    2,    3,    4,    5,          6,    7,    8,    9,    0, BSLS,
    ____, DQUO, LCBR, RCBR, MINS,  EQL,       ____, LSFT, LGUI, LALT, LCTL, ____,
    ____, SQUO, LBRC, RBRC, UNDS, PLUS,       ____, ____, ____, ____, ____, ____,
                            ____, ____,  ESC, XXXX, ____
  ),

  [_ADJUST] = LAYOUT_reviung41(
     KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, XXXXXXX, RGB_TOG,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F12,
    RGB_VAD, RGB_SAD, RGB_HUD,RGB_RMOD, XXXXXXX, XXXXXXX,            RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, XXXXXXX, XXXXXXX, XXXXXXX, _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SPRS:
            return true;
        case KC_SQUO:
            return true;
        default:
            return false;
    }
}
