#include QMK_KEYBOARD_H

enum layer_number {
  _DVO = 0,
  _QWE,
  _NUM,
  _SYM,
  _FUN,
};

// Mod tap left
#define LWINMOD   LGUI_T(KC_SLSH)  // GUI
#define LALTMOD   LALT_T(KC_Y)     // ALT
#define LSFTMOD   LSFT_T(KC_G)     // SHIFT
#define LCTRMOD   LCTL_T(KC_U)     // CTRL
#define LALTGRMOD RALT_T(KC_DOT)   // RALT


// Mod tap right
#define RALTGRMOD RALT_T(KC_COMM) // RALT
#define RCTRMOD   LCTL_T(KC_D)    // CTRL
#define RSFTMOD   LSFT_T(KC_M)    // SHIFT
#define RALTMOD   LALT_T(KC_V)    // ALT
#define RWINMOD   LGUI_T(KC_Z)    // GUI


// Custom keys macros
enum custom_keycodes {
    CUSTOM_0 = SAFE_RANGE,
    CUSTOM_1,
};

// macro for the macro keys
#define SHIFT_KEY(key) do {register_code(KC_RSFT); tap_code(key); unregister_code(KC_RSFT);} while(0)

#define MACRO_SHIFT(key1, key2) if (record->event.pressed) { \
    if (keyboard_report->mods & MOD_BIT(KC_LSFT)) { \
        SHIFT_KEY(key1); \
    } else { \
        SHIFT_KEY(key2); \
    } \
} else {}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
    case CUSTOM_0:
        if (record->event.pressed)
        {
            if (keyboard_report->mods & MOD_BIT(KC_LSFT))
            {
                SHIFT_KEY(KC_1);
            }
            else
            {
                SHIFT_KEY(KC_2);
            }
        }
        else {}
        break;
    case CUSTOM_1:
        MACRO_SHIFT(KC_3, KC_4);
        break;
    }

    return true;
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DVO] = LAYOUT(
  CUSTOM_0, CUSTOM_1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_TAB,    KC_Q,    KC_W,    KC_B,    KC_P,    KC_K,                   KC_X,    KC_L,    KC_C,    KC_H,    KC_F,  KC_ESC,
  KC_MINS,    KC_A,    KC_O,    KC_E,    KC_I, KC_SCLN,                  KC_J,    KC_R,    KC_T,    KC_N,    KC_S, KC_QUOT,
  KC_RBRC, LWINMOD, LALTMOD, LSFTMOD, LCTRMOD,LALTGRMOD, KC_LBRC,  KC_RBRC,  RALTGRMOD, RCTRMOD, RSFTMOD, RALTMOD, RWINMOD,KC_LBRC,
                        KC_LALT, C(KC_TAB),MO(_NUM), KC_SPC,        KC_BSPC,LT(_SYM, KC_ENT),A(KC_TAB), KC_RGUI
),

[_QWE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_ESC,
  KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                   KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_LGUI,
  KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______, _______, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
                             _______, KC_LALT,MO(_NUM),  KC_SPC, KC_BSPC,LT(_SYM, KC_ENT), KC_RALT, _______
),

[_NUM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
  KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_ESC,
  KC_LSFT, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS,                   KC_DEL, KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, KC_LGUI,
  KC_LCTL, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), _______, _______, XXXXXXX,KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,  XXXXXXX,
                             _______, KC_LALT, _______,  KC_SPC, KC_BSPC,LT(_FUN, KC_ENT), KC_RALT, _______
),

[_SYM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  KC_TAB, KC_EXLM,  KC_AT, RALT(KC_3), KC_DLR, KC_PERC,                     KC_AMPR, KC_ASTR, KC_LPRN, KC_CIRC, KC_RPRN, KC_ESC,
  KC_LSFT,RALT(KC_1),RALT(KC_4),KC_NUBS,S(KC_NUBS),KC_EQL,                XXXXXXX,RALT(KC_QUOT),RALT(KC_BSLS),RALT(KC_LBRC),RALT(KC_RBRC),KC_LGUI,
  KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   _______, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, KC_LALT,MO(_FUN),  KC_SPC,   KC_BSPC, _______, KC_RALT, _______
),

  [_FUN] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_ESC,
  KC_LSFT,  KC_F11, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F12, KC_LGUI,
  KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,DF(_QWE), XXXXXXX, XXXXXXX, DF(_DVO), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, KC_LALT, _______,  KC_SPC, KC_ENT, _______, KC_RALT, _______
  )
};
