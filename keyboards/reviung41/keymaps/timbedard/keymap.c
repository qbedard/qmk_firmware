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
  [_BASE] = LAYOUT_kc(
     TAB,    Q,    W,    E,    R,    T,          Y,    U,    I,    O,    P, BSPC,
    CESC,    A,    S,    D,    F,    G,          H,    J,    K,    L, SCLN,  ENT,
    LSFT,    Z,    X,    C,    V,    B,          N,    M, COMM,  DOT, SLSH, SQUO,
                            LGUI, BSLW,  SPC, SPRS, LALT
  ),

  [_LOWER] = LAYOUT_kc(
    TILD, EXLM,   AT, HASH,  DLR, PERC,       CIRC, AMPR, ASTR, LPRN, RPRN, PIPE,
    ____, UNDS, PLUS, LCBR, RCBR, PIPE,       LEFT, DOWN,   UP, RGHT, ASPC, ____,
    ____,  ESC, LGUI, LALT, CAPS, DQUO,       RPRN, PLUS, MINS,  EQL, UNDS, DQUO,
                            ____, XXXX,  ENT, ____, ____
  ),

  [_RAISE] = LAYOUT_kc(
     GRV,    1,    2,    3,    4,    5,          6,    7,    8,    9,    0, BSLS,
    ____, MINS,  EQL, LBRC, RBRC, BSLS,       LEFT, DOWN,   UP, RGHT, ASPC, ____,
    ____,  ESC, RGUI, RALT, CAPS, QUOT,       HOME, PGDN, PGUP,  END, ____, ____,
                            ____, ____,  ESC, XXXX, ____
  ),

  [_ADJUST] = LAYOUT_reviung41(
     KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, XXXXXXX, RGB_TOG,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_VAD, RGB_SAD, RGB_HUD,RGB_RMOD, XXXXXXX, XXXXXXX,            RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, XXXXXXX, XXXXXXX, XXXXXXX, _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
