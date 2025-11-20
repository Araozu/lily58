#include QMK_KEYBOARD_H
#include "leader.c"

enum layer_number {
  _DVO = 0,
  _QWE,
  _NUM,
};

// Mod tap left
#define LALTMOD   LALT_T(KC_Y)     // ALT
#define LSFTMOD   LSFT_T(KC_B)     // SHIFT
#define LCTRMOD   LCTL_T(KC_U)     // CTRL
#define LWINMOD   LGUI_T(KC_DOT)  // GUI
// #define LALTGRMOD RALT_T(KC_DOT)   // RALT


// Mod tap right
// #define RALTGRMOD RALT_T(KC_COMM) // RALT
#define RWINMOD   LGUI_T(KC_COMM)    // GUI
#define RCTRMOD   LCTL_T(KC_D)    // CTRL
#define RSFTMOD   LSFT_T(KC_M)    // SHIFT
#define RALTMOD   LALT_T(KC_V)    // ALT




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


/* LEFT  - 01
 *
 *     ,-----------------------------------------------.
 *     |       |  ! |  |  " @  |  = #  |  $ ~  |  & %  |
 *     |-------+-------+-------+-------+-------+-------|
 *     |       |   Q   |   W   |   U   |   P   |   X   |
 *     |-------+-------+-------+-------+-------+-------|
 *     |   Ñ   |   :   |   O   |   A   |   E   |   G   |-------.
 *     |-------+-------+-------+-------+-------+-------|  - _  |
 *     |       |       |   Y   |   B   |   I   |  . :  |-------|
 *     `-----------------------------------------------/       /
 *                       | C+Tab | TAB   |!Leader|   / Space  /
 *                       |       |       | raise |  /        /
 *                       '--------------------------------'
 */
/* RIGHT - 01
 *             ,-----------------------------------------------.
 *             |  / \  |  ( [  |  ) ]  |  { <  |  } >  |  ¿ ¡  |
 *             |-------+-------+-------+-------+-------+-------|
 *             |   K   |   H   |   C   |   L   |   F   |  ' ?  |
 *             |-------+-------+-------+-------+-------+-------|
 *     ,-------|   J   |   S   |   N   |   R   |   T   |  ´ ¨  |
 *     |  + *  |-------+-------+-------+-------+-------+-------|
 *     |-------|  , ;  |   D   |   M   |   V   |   Z   |  `    |
 *      \      \-----------------------------------------------'
 *       \Bksp  \   | ENTER  |  Esc  |  Del  |
 *        \      \  | raise  |       |       |
 *         '---------------------------------'
 */



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//
[_DVO] = LAYOUT(
//*/------------------------------------------------------------------------------------------/--/                             /--/--------------------------------------------------------------------------------------------
/**/       MS_BTN1,      CUSTOM_1,     CUSTOM_2,      CUSTOM_3,      CUSTOM_4,      CUSTOM_5, /**/                             /**/      CUSTOM_6,      CUSTOM_7,      CUSTOM_8,      CUSTOM_9,     CUSTOM_10,      KC_EQUAL,
//*/------------------------------------------------------------------------------------------/**/                             /**/--------------------------------------------------------------------------------------------
/**/       XXXXXXX,          KC_Q,         KC_W,          KC_I,          KC_P,          KC_X, /**/                             /**/          KC_K,          KC_H,          KC_C,          KC_L,          KC_F,       KC_MINS,
//*/------------------------------------------------------------------------------------------/**/                             /**/--------------------------------------------------------------------------------------------
/**/       KC_SCLN,     S(KC_DOT),         KC_O,          KC_A,          KC_E,          KC_G, /**/                             /**/          KC_J,          KC_S,          KC_N,          KC_R,          KC_T,       KC_LBRC,
//*/------------------------------------------------------------------------------------------/****************/ /****************/--------------------------------------------------------------------------------------------
/**/       XXXXXXX,       XXXXXXX,      LALTMOD,       LSFTMOD,       LCTRMOD,       LWINMOD,       KC_SLSH,/**/ /**/      KC_RBRC,       RWINMOD,       RCTRMOD,       RSFTMOD,       RALTMOD,          KC_Z, RALT(KC_BSLS),
//*/----------------------------------------/**/------------------------------------------------------------/**/ /**/------------------------------------------------------------/**/------------------------------------------
                                            /**/       C(KC_TAB),     QK_LEAD,LT(_NUM,KC_TAB),       KC_SPC,/**/ /**/      KC_BSPC,        KC_ENT,        KC_ESC,          KC_DEL  /**/
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


/* LEFT  - 01
 *
 *     ,-----------------------------------------------.
 *     | Rclick|  F1   |  F2   |  F3   |  F4   |  F5   |
 *     |-------+-------+-------+-------+-------+-------|
 *     |       |       |   1   |   2   |   3   |       |
 *     |-------+-------+-------+-------+-------+-------|
 *     |       |       |   4   |   5   |   6   |   0   |-------.
 *     |-------+-------+-------+-------+-------+-------|  QWE  |
 *     |       |       |   7   |   8   |   9   |       |-------|
 *     `-----------------------------------------------/       /
 *                       | C+Tab | LAlt  | _____ |   / Space  /
 *                       |       |       | raise |  /        /
 *                       '----------------------------------'
 */
/* RIGHT - 01
 *             ,-----------------------------------------------.
 *             |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |
 *             |-------+-------+-------+-------+-------+-------|
 *             |   ↑   |   ←   |  PgUp |   →   |       |  F12  |
 *             |-------+-------+-------+-------+-------+-------|
 *     ,-------|   ↓   |  Home | PgDown|  End  |       |       |
 *     |  DVO  |-------+-------+-------+-------+-------+-------|
 *     |-------|       |       |       |       |       |       |
 *      \      \-----------------------------------------------'
 *       \Bksp  \   | ENTER  |  Esc  |  Del  |
 *        \      \  | raise  |       |       |
 *         '---------------------------------'
 */
[_NUM] = LAYOUT(
//*/------------------------------------------------------------------------------------------/--/                             /--/--------------------------------------------------------------------------------------------
/**/      MS_BTN2,         KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5, /**/                             /**/         KC_F6,              KC_F7,            KC_F8,          KC_F9,         KC_F10, KC_F11,
//*/------------------------------------------------------------------------------------------/**/                             /**/--------------------------------------------------------------------------------------------
/**/      XXXXXXX,       XXXXXXX,          KC_1,          KC_2,          KC_3,       XXXXXXX, /**/                             /**/         KC_UP,            KC_LEFT,          KC_PGUP,       KC_RIGHT,        XXXXXXX, KC_F12,
//*/------------------------------------------------------------------------------------------/**/                             /**/--------------------------------------------------------------------------------------------
/**/      XXXXXXX,       XXXXXXX,          KC_4,          KC_5,          KC_6,          KC_0, /**/                             /**/       KC_DOWN,            KC_HOME,          KC_PGDN,         KC_END,        XXXXXXX, KC_LGUI,
//*/------------------------------------------------------------------------------------------/****************/ /****************/--------------------------------------------------------------------------------------------
/**/      XXXXXXX,       XXXXXXX,          KC_7,          KC_8,          KC_9,       XXXXXXX,      DF(_QWE),/**/ /**/     DF(_DVO),       XXXXXXX,            XXXXXXX,          XXXXXXX,        XXXXXXX,        XXXXXXX, KC_CAPS,
//*/----------------------------------------/**/------------------------------------------------------------/**/ /**/------------------------------------------------------------------/**/-------------------------------------
                                            /**/       XXXXXXX,       KC_LALT,       _______,        KC_SPC,/**/ /**/      KC_BSPC,        KC_ENT,            KC_ESC,          XXXXXXX/**/
                                            ////------------------------------------------------------------/**/ /**/------------------------------------------------------------------/**/
)
};
