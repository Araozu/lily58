#include QMK_KEYBOARD_H

enum layer_number {
  _DVO = 0,
  _QWE,
  _NUM,
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




// Mod tap 2nd layer
#define RCTLMOD2  LCTL_T(KC_MEDIA_PREV_TRACK) // CTRL
#define RSFTMOD2  LSFT_T(KC_AUDIO_VOL_DOWN)   // SHIFT



// Custom keys macros
enum custom_keycodes {
    CUSTOM_0 = SAFE_RANGE,
    CUSTOM_1,
    CUSTOM_2,
    CUSTOM_3,
    CUSTOM_4,
    CUSTOM_5,
    CUSTOM_6,
    CUSTOM_7,
    CUSTOM_8,
    CUSTOM_9,
    CUSTOM_10,
};

// macros for the macro keys
#define SHIFT_KEY(key) do { \
    register_code(KC_RSFT); \
    tap_code(key); \
    unregister_code(KC_RSFT); \
} while(0)

#define ALTGR_KEY(key) do { \
    register_code(KC_RALT); \
    tap_code(key); \
    unregister_code(KC_RALT); \
} while(0)

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
    case CUSTOM_1:
        if (record->event.pressed)
        {
            if (keyboard_report->mods & MOD_BIT(KC_LSFT))
            {
                // disable the left shift key
                unregister_code(KC_LSFT);
                tap_code(KC_GRAVE); // |
                // reenable the left shift key
                register_code(KC_LSFT);
            }
            else
            {
                SHIFT_KEY(KC_1); // !
            }
        }
        else {}
        break;
    case CUSTOM_2:
        if (record->event.pressed)
        {
            if (keyboard_report->mods & MOD_BIT(KC_LSFT))
            {
                // empty
            }
            else
            {
                SHIFT_KEY(KC_2); // "
            }
        }
        else {}
        break;
    case CUSTOM_3:
        if (record->event.pressed)
        {
            if (keyboard_report->mods & MOD_BIT(KC_LSFT))
            {
                SHIFT_KEY(KC_3); // #
            }
            else
            {
                SHIFT_KEY(KC_0); // =
            }
        }
        else {}
        break;
    case CUSTOM_4:
        if (record->event.pressed)
        {
            if (keyboard_report->mods & MOD_BIT(KC_LSFT))
            {
                // disable the left shift key
                unregister_code(KC_LSFT);
                ALTGR_KEY(KC_4); // ~
                // reenable the left shift key
                register_code(KC_LSFT);
            }
            else
            {
                SHIFT_KEY(KC_4); // $
            }
        }
        else {}
        break;
    case CUSTOM_5:
        if (record->event.pressed)
        {
            if (keyboard_report->mods & MOD_BIT(KC_LSFT))
            {
                SHIFT_KEY(KC_5); // %
            }
            else
            {
                SHIFT_KEY(KC_6); // &
            }
        }
        else {}
        break;
    case CUSTOM_6:
        if (record->event.pressed)
        {
            if (keyboard_report->mods & MOD_BIT(KC_LSFT))
            {
                // disable the left shift key
                unregister_code(KC_LSFT);
                ALTGR_KEY(KC_MINS); // \ (backslash)
                // reenable the left shift key
                register_code(KC_LSFT);
            }
            else
            {
                SHIFT_KEY(KC_7); // /
            }
        }
        else {}
        break;
    case CUSTOM_7:
        if (record->event.pressed)
        {
            if (keyboard_report->mods & MOD_BIT(KC_LSFT))
            {
                SHIFT_KEY(KC_QUOTE); // [
            }
            else
            {
                SHIFT_KEY(KC_8); // (
            }
        }
        else {}
        break;
    case CUSTOM_8:
        if (record->event.pressed)
        {
            if (keyboard_report->mods & MOD_BIT(KC_LSFT))
            {
                SHIFT_KEY(KC_BSLS); // ]
            }
            else
            {
                SHIFT_KEY(KC_9); // )
            }
        }
        else {}
        break;
    case CUSTOM_9:
        if (record->event.pressed)
        {
            if (keyboard_report->mods & MOD_BIT(KC_LSFT))
            {
                // disable the left shift key
                unregister_code(KC_LSFT);
                tap_code(KC_NUBS); // <
                // reenable the left shift key
                register_code(KC_LSFT);
            }
            else
            {
                tap_code(KC_QUOTE); // {
            }
        }
        else {}
        break;
    case CUSTOM_10:
        if (record->event.pressed)
        {
            if (keyboard_report->mods & MOD_BIT(KC_LSFT))
            {
                SHIFT_KEY(KC_NUBS); // >
            }
            else
            {
                tap_code(KC_BSLS); // }
            }
        }
        else {}
        break;
    // ! " = $ &  / ( ) { }
    // |   # ~ %  \ [ ] < >
    }

    return true;
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// 
/* CUSTOM DVORAK LAYER
 *                                                     ,-----------------------------------------.                               ,-----------------------------------------.
 *                                                     |MAYUS |   !  |   "  |   =  |   $  |   &  |                               |   /  |   (  |   )  |   {  |   }  |  ¿   |
 *                                                     |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 *                                                     | ESC  |   Q  |   W  |   B  |   P  |   K  |                               |   X  |   L  |   C  |   H  |   F  |  '   |
 *                                                     |------+------+------+------+------+------|                               |------+------+------+------+------+------|
 *                                                     | Tab  |   A  |   O  |   E  |   I  |   Ñ  |-------.               ,-------|   J  |   R  |   T  |   N  |   S  |  ´   |
 *                                                     |------+------+------+------+------+------|   _   |               |   ;   |------+------+------+------+------+------|
 *                                                     |   +  |   -  |   Y  |   G  |   U  |   .  |-------|               |-------|   ,  |   D  |   M  |   V  |   Z  |  `   |
 *                                                     `-----------------------------------------/       /                \      \-----------------------------------------'
 *                                                                       |      |C+Tab |LOWER | /Space  /                  \Bksp  \  |RAISE  |A+Tab | Del  |
 *                                                                       |      |      |      |/       /                    \      \ |Intro  |      |      |
 *                                                                       '----------------------------'                      '------''---------------------'
 */
[_DVO] = LAYOUT(
//*/------------------------------------------------------------------------------------------/--/                             /--/--------------------------------------------------------------------------------------------
/**/  KC_CAPS_LOCK,      CUSTOM_1,     CUSTOM_2,      CUSTOM_3,      CUSTOM_4,      CUSTOM_5, /**/                             /**/      CUSTOM_6,      CUSTOM_7,      CUSTOM_8,      CUSTOM_9,     CUSTOM_10,      KC_EQUAL,
//*/------------------------------------------------------------------------------------------/**/                             /**/--------------------------------------------------------------------------------------------
/**/        KC_ESC,          KC_Q,         KC_W,          KC_B,          KC_P,          KC_K, /**/                             /**/          KC_X,          KC_L,          KC_C,          KC_H,          KC_F,       KC_MINS,
//*/------------------------------------------------------------------------------------------/**/                             /**/--------------------------------------------------------------------------------------------
/**/        KC_TAB,          KC_A,         KC_O,          KC_E,          KC_I,       KC_SCLN, /**/                             /**/          KC_J,          KC_R,          KC_T,          KC_N,          KC_S,       KC_LBRC,
//*/------------------------------------------------------------------------------------------/****************/ /****************/--------------------------------------------------------------------------------------------
/**/       KC_RBRC,       LWINMOD,      LALTMOD,       LSFTMOD,       LCTRMOD,     LALTGRMOD,    S(KC_SLSH),/**/ /**/   S(KC_COMM),     RALTGRMOD,       RCTRMOD,       RSFTMOD,       RALTMOD,       RWINMOD, RALT(KC_BSLS),
//*/----------------------------------------/**/------------------------------------------------------------/**/ /**/------------------------------------------------------------/**/------------------------------------------
                                            /**/       KC_LALT,     C(KC_TAB),      MO(_NUM),        KC_SPC,/**/ /**/      KC_BSPC,        KC_ENT,   A(KC_TAB),          KC_DEL  /**/
                                            ////------------------------------------------------------------/**/ /**/------------------------------------------------------------/**/
),

/* QWERTY
 *                                                  ,-----------------------------------------.                                  ,-----------------------------------------.
 *                                                  |      |   1  |   2  |   3  |   4  |   5  |                                  |   6  |   7  |   8  |   9  |   0  |      |
 *                                                  |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 *                                                  | Tab  |   Q  |   W  |   E  |   R  |   T  |                                  |   Y  |   U  |   I  |   O  |   P  | ESC  |
 *                                                  |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 *                                                  | LSFT |   A  |   S  |   D  |   F  |   G  |-------.                  ,-------|   H  |   J  |   K  |   L  |   Ñ  | LGUI |
 *                                                  |------+------+------+------+------+------|       |                  |       |------+------+------+------+------+------|
 *                                                  |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|                  |-------|   N  |   M  |   ,  |   .  |   -  |Intro |
 *                                                  `-----------------------------------------/       /                   \      \-----------------------------------------'
 *                                                                    |      | LALT |LOWER | /Space  /                     \Bksp  \  |RAISE  | RALT |      |
 *                                                                    |      |      |      |/       /                       \      \ |Intro  |      |      |
 *                                                                    '----------------------------'                         '------''---------------------'
 */
[_QWE] = LAYOUT(
//*/------------------------------------------------------------------------------------------/--/                             /--/--------------------------------------------------------------------------------------------
/**/      XXXXXXX,          KC_1,          KC_2,          KC_3,          KC_4,          KC_5, /**/                             /**/            KC_6,          KC_7,          KC_8,          KC_9,          KC_0,       XXXXXXX,
//*/------------------------------------------------------------------------------------------/**/                             /**/--------------------------------------------------------------------------------------------
/**/       KC_TAB,          KC_Q,          KC_W,          KC_E,          KC_R,          KC_T, /**/                             /**/            KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,        KC_ESC,
//*/------------------------------------------------------------------------------------------/**/                             /**/--------------------------------------------------------------------------------------------
/**/      KC_LSFT,          KC_A,          KC_S,          KC_D,          KC_F,          KC_G, /**/                             /**/            KC_H,          KC_J,          KC_K,          KC_L,       KC_SCLN,       KC_LGUI,
//*/------------------------------------------------------------------------------------------/****************/ /****************/--------------------------------------------------------------------------------------------
/**/      KC_LCTL,          KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,       XXXXXXX,/**/ /**/      XXXXXXX,            KC_N,          KC_M,       KC_COMM,        KC_DOT,       KC_SLSH,       XXXXXXX,
//*/----------------------------------------/**/------------------------------------------------------------/**/ /**/------------------------------------------------------------/**/------------------------------------------
                                            /**/       XXXXXXX,       KC_LALT,      MO(_NUM),        KC_SPC,/**/ /**/       KC_BSPC,         KC_ENT,       KC_RALT,       XXXXXXX/**/
                                            ////------------------------------------------------------------/**/ /**/------------------------------------------------------------/**/
),

/* Number layout
 *                                                  ,-----------------------------------------.                                  ,-----------------------------------------.
 *                                                  | F11  |  F1  |  F2  |  F3  |  F4  |  F5  |                                  |  F6  |  F7  |  F8  |  F9  | F10  | F12  |
 *                                                  |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 *                                                  | ESC  |   1  |   2  |   3  |   4  |   5  |                                  |   6  |   7  |   8  |   9  |   0  |      |
 *                                                  |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 *                                                  | Tab  | Home |PgDwn | PgUp |  End |Insert|-------.                  ,-------|  Del |   ← |   ↓ |   ↑ |   → | LGUI |
 *                                                  |------+------+------+------+------+------| qwe   |                  | dvo   |------+------+------+------+------+------|
 *                                                  |Shift |  G+1 |  G+2 |  G+3 |  G+4 |  G+5 |-------|                  |-------|      |PrevM |VolUp |VolDow|NextM |Intro |
 *                                                  `-----------------------------------------/       /                   \      \-----------------------------------------'
 *                                                                    |      | LALT |LOWER | /Space  /                     \Bksp  \  |RAISE  | RALT |      |
 *                                                                    |      |      |      |/       /                       \      \ |Intro  |      |      |
 *                                                                    '----------------------------'                         '------''---------------------'
 */
[_NUM] = LAYOUT(
//*/------------------------------------------------------------------------------------------/--/                             /--/--------------------------------------------------------------------------------------------
/**/       KC_F11,         KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5, /**/                             /**/         KC_F6,              KC_F7,            KC_F8,          KC_F9,             KC_F10,  KC_F12,
//*/------------------------------------------------------------------------------------------/**/                             /**/--------------------------------------------------------------------------------------------
/**/       KC_ESC,          KC_1,          KC_2,          KC_3,          KC_4,          KC_5, /**/                             /**/          KC_6,               KC_7,             KC_8,           KC_9,               KC_0, XXXXXXX,
//*/------------------------------------------------------------------------------------------/**/                             /**/--------------------------------------------------------------------------------------------
/**/       KC_TAB,       KC_HOME,       KC_PGDN,       KC_PGUP,        KC_END,        KC_INS, /**/                             /**/        KC_DEL,            KC_LEFT,          KC_DOWN,          KC_UP,           KC_RIGHT, KC_LGUI,
//*/------------------------------------------------------------------------------------------/****************/ /****************/--------------------------------------------------------------------------------------------
/**/      KC_LSFT,       G(KC_1),       G(KC_2),       G(KC_3),       G(KC_4),       G(KC_5),      DF(_QWE),/**/ /**/     DF(_DVO),       XXXXXXX,           RCTLMOD2,         RSFTMOD2,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK, XXXXXXX,
//*/----------------------------------------/**/------------------------------------------------------------/**/ /**/------------------------------------------------------------------/**/------------------------------------------
                                            /**/       KC_LCTL,       KC_LALT,       _______,        KC_SPC,/**/ /**/      KC_BSPC,        KC_ENT,            KC_RALT,          KC_LCTL/**/
                                            ////------------------------------------------------------------/**/ /**/------------------------------------------------------------------/**/
)
};
