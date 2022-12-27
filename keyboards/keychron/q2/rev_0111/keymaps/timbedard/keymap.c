#include QMK_KEYBOARD_H

enum layers{
    MAC_BASE,
    WIN_BASE,
    _FN1,
    _FN2,
    _FN3,
    _RAISE
};

#define KC_WAVE S(KC_GRV)
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define KC_____ KC_TRNS
#define KC_SPRS LT(_RAISE, KC_SPC)
#define KC_CESC CTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_67(  // switch to Mac
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,          KC_____,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,           KC_HOME,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LOPT, KC_LCMD,                            KC_SPRS,                            KC_RCMD, MO(_FN1), MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_67(  // switch to Win
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,    KC_BSPC,          KC_____,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,   KC_BSLS,          KC_DEL,
        KC_CESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,             KC_ENT,           KC_HOME,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPRS,                            KC_RALT, MO(_FN2), MO(_FN3),  KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN1] = LAYOUT_ansi_67(  // Mac + fn1
        KC_GRV,  KC_BRID, KC_BRIU, KC_____, KC_____, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU,   KC_____,          KC_____,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,  KC_____,   KC_____,          KC_____,
        KC_____, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,             KC_____,          KC_____,
        KC_____,          KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,             KC_____, KC_____,
        KC_____, KC_____, KC_____,                            KC_____,                            KC_____, KC_____,  KC_____,   KC_____, KC_____, KC_____),

    [_FN2] = LAYOUT_ansi_67(  // Win + fn1
        KC_GRV,  KC_BRID, KC_BRIU, KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU,   KC_____,          KC_____,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,  KC_____,   KC_____,          KC_____,
        KC_____, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,             KC_____,          KC_____,
        KC_____,          KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,             KC_____, KC_____,
        KC_____, KC_____, KC_____,                            KC_____,                            KC_____, KC_____,  KC_____,   KC_____, KC_____, KC_____),

    [_FN3] = LAYOUT_ansi_67(  // fn2
        KC_WAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,    KC_____,          KC_____,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,  KC_____,   KC_____,          KC_____,
        KC_____, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,             KC_____,          KC_____,
        KC_____,          KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,             KC_____, LSG(KC_UP),
        KC_____, KC_____, KC_____,                            KC_____,                            KC_____, KC_____,  KC_____, S(KC_TAB), LSG(KC_DOWN), KC_TAB),

    [_RAISE] = LAYOUT_ansi_67(  // Hold Space
        KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,    KC_____,          KC_____,
        KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,  KC_____,   KC_____,          KC_____,
        KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_____, KC_____,             KC_____,          KC_____,
        KC_____,          KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____, KC_____,             KC_____, LSG(KC_UP),
        KC_____, KC_____, KC_____,                            KC_____,                            KC_____, KC_____,  KC_____, S(KC_TAB), LSG(KC_DOWN), KC_TAB)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_UP, KC_DOWN) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_UP, KC_DOWN) },
    [_FN1]     = { ENCODER_CCW_CW(KC_____, KC_____) },
    [_FN2]     = { ENCODER_CCW_CW(KC_____, KC_____) },
    [_FN3]     = { ENCODER_CCW_CW(KC_____, KC_____) },
    [_RAISE]   = { ENCODER_CCW_CW(KC_____, KC_____) },
};
#endif

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SPRS:
            return true;
        default:
            return false;
    }
}
