#include QMK_KEYBOARD_H

#define SM_LWER LT(_LOWER, KC_BSPC)
#define SM_RAIS LT(_RAISE, KC_ENTER)

enum layers {
    _QWERTY,
    _WORKMAN,
    _LOWER,
    _RAISE,
    _FN
};

enum keycodes {
    QWERTY = SAFE_RANGE,
    WORKMAN,
    LOWER,
    RAISE,
    FN
};

/* ********************************
 *  _                         _
 * | | __ _ _   _  ___  _   _| |_
 * | |/ _` | | | |/ _ \| | | | __|
 * | | (_| | |_| | (_) | |_| | |_
 * |_|\__,_|\__, |\___/ \__,_|\__|
 *          |___/
 * ********************************
 */

/* Layer X
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |             |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
/*
    [X] = LAYOUT_planck_mit(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
    )
*/

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 3, HSV_CYAN}
);

const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, 3, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM my_fn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {13, 1, HSV_WHITE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_lower_layer,
    my_raise_layer,
    my_fn_layer
);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |Layer3| Alt  |Super |Layer1|    Space    |Layer2| Left |Right | Down |  Up  |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_planck_mit(
        KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T    , KC_Y    , KC_U   ,  KC_I   , KC_O   , KC_P   , KC_BSPC,
        KC_LCTL , KC_A   , KC_S   , KC_D   , KC_F   , KC_G    , KC_H    , KC_J   ,  KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LSFT , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B    , KC_N    , KC_M   ,  KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
        KC_ESC  , MO(_FN), KC_LALT, KC_LGUI, MO(_LOWER),  KC_SPC        , SM_RAIS,  KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
    ),

    /* Workman
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Shift |   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  |Shift |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |  FN  | Alt  |Super |Lower |    Space    |Raise | Left |Right | Down |  Up  |
     * `-----------------------------------------------------------------------------------'
     */
    [_WORKMAN] = LAYOUT_planck_mit(
        KC_TAB  , KC_Q   , KC_D   , KC_R   , KC_W   , KC_B    , KC_J    , KC_F   ,  KC_U   , KC_P   , KC_SCLN, KC_BSPC,
        KC_LCTL , KC_A   , KC_S   , KC_H   , KC_T   , KC_G    , KC_Y    , KC_N   ,  KC_E   , KC_I   , KC_O   , KC_QUOT,
        KC_LSFT , KC_Z   , KC_X   , KC_M   , KC_C   , KC_V    , KC_K    , KC_L   ,  KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
        KC_ESC  , MO(_FN), KC_LALT, KC_LGUI, MO(_LOWER),  KC_SPC        , SM_RAIS,  KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
    ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_mit(
        KC_TILD, KC_F1  , KC_F2  , KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10 , _______,
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
    ),

    /* Layer 2 - Raise Layer
     * ,-----------------------------------------------------------------------------------.
     * |      |      |   {  |   [  |   (  |   <  |   >  |   )  |   ]  |   }  |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |   -  |   =  |   \  |      | Left | Down |  Up  |Right |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |   _  |   +  |   |  |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_mit(
        KC_CAPS, _______, KC_LCBR, KC_LBRC, KC_LPRN, KC_LT  , KC_GT  , KC_RPRN, KC_RBRC, KC_RCBR, _______, _______,
        _______, _______, KC_MINS, KC_EQL , KC_BSLS, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
        _______, _______, KC_UNDS, KC_PLUS, KC_PIPE, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
    ),
    /* Layer 3 (r_ Indicates RGB Controls) - FN Layer
     * ,-----------------------------------------------------------------------------------.
     * |QWERTY|      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |WRKMAN|r_TOG |r_Mode|r_Hue-|r_Hue+|      |      | Prev | Play | Next |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |r_Bri-|r_Bri+|r_Sat-|r_Sat+|      |      | Mute | Vol- | Vol+ |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |RESET |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT_planck_mit(
        QWERTY , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        WORKMAN, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
        _______, RGB_VAD, RGB_VAI, RGB_SAD, RGB_SAI, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
        RESET  , _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
    )
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                print("Mode just switched to qwerty");
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case WORKMAN:
            if (record->event.pressed) {
                print("Mode just switched to workman");
                set_single_persistent_default_layer(_WORKMAN);
            }
            return false;
            break;
    }
    return true;
}

void led_set_user(uint8_t usb_led) {

    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_COMPOSE)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_KANA)) {

    } else {

    }

}

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _FN));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}