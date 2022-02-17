#include QMK_KEYBOARD_H

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum layer_names {
  _BASE,
  _RAISE,
  _LOWER,
  _ADJUST
};

#define KC_____ KC_TRNS
#define KC_SPRS LT(_RAISE, KC_SPC)
#define KC_BSLW LT(_LOWER, KC_BSPC)
#define KC_CESC CTL_T(KC_ESC)
#define KC_SQUO SFT_T(KC_QUOT)
#define KC_ASPC A(KC_SPC)
/* #define KC_TACA TD(TD_ALT_CALT) */
/* #define KC_TGCA TD(TD_GUI_CALT) */
#define KC_XXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_CESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SQUO,
                          KC_LBRC, KC_RBRC,                                        KC_PLUS, KC_EQL,
                                   KC_LGUI, KC_BSLW, KC_XXXX,    KC_XXXX, KC_SPRS, KC_LALT,
                                            KC_XXXX, KC_XXXX,    KC_XXXX, KC_XXXX
    ),

    [_LOWER] = LAYOUT(
        KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_ASPC, _______,
        _______, _______, _______, _______, _______, _______,    KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______, KC_DQUO,
                          KC_LCBR, KC_RCBR,                                        _______, _______,
                                   _______, _______, _______,    _______, _______, _______,
                                            _______, _______,    _______, _______
    ),

    [_RAISE] = LAYOUT(
        KC_GRV,    KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        _______, KC_DQUO, KC_LCBR, KC_RCBR, KC_MINS,  KC_EQL,    _______, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, _______,
        _______, KC_SQUO, KC_LBRC, KC_RBRC, KC_UNDS, KC_PLUS,    _______, _______, _______, _______, _______, _______,
                          _______, _______,                                        _______, _______,
                                   _______, _______, _______,    _______, _______, _______,
                                            _______, _______,    _______, _______
    ),

    [_ADJUST] = LAYOUT(
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
        RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, XXXXXXX, RGB_TOG,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F12,
        RGB_VAD, RGB_SAD, RGB_HUD,RGB_RMOD, XXXXXXX, XXXXXXX,      RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          _______, _______,                                        _______, _______,
                                   _______, _______, _______,    _______, _______, _______,
                                            _______, _______,    _______, _______
    )
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
