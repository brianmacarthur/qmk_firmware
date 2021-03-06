#include "nyquist.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _GAMER 3
#define _LOWER 4
#define _RAISE 5
#define _FN1 6
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  GAMER,
  LOWER,
  RAISE,
  FN1,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------------------------------.
 * |   1    |   2    |   3    |   4    |   5    |   `    |   Del  |   6    |   7    |   8    |   9    |   0    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |   Q    |   W    |   E    |   R    |   T    |   Tab  |   Bkspc|   Y    |   U    |   I    |   O    |   P    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |   A    |   S    |   D    |   F    |   G    |   Fn1  |   "    |   H    |   J    |   K    |   L    |   ;    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |   Z    |   X    |   C    |   V    |   B    |   Shift|   Enter|   N    |   M    |   ,    |   .    |   /    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | GUI    | Alt    |Adjust  |Lower   |Shift   |   Ctrl |   Ctrl |Space   |Raise   |Adjust  | Alt    | GUI    |
 * `-----------------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,  KC_DEL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0, \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TAB,  KC_RSFT, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
  LT(_FN1 ,KC_A),    KC_S,    KC_D,    KC_F,    KC_G,    FN1,     KC_QUOT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    RAISE,   LOWER,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
  KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_LSFT, KC_BSPC, KC_ENT,  KC_SPC,  RAISE,   KC_RALT, KC_RGUI, KC_RCTL \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Fn1  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |Adjust|Lower |Shift |Space |Raise |Adjust| Alt  | GUI  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 *
 * [_COLEMAK] = LAYOUT( \
 *   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
 *   KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
 *   FN1,     KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
 *   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
 *   KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_LSFT, KC_BSPC, KC_ENT,  KC_SPC,  RAISE,   KC_RALT, KC_RGUI, KC_RCTL \
 * ),
*/

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Fn1  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |Adjust|Lower |Shift |Space |Raise |Adjust| Alt  | GUI  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  FN1,     KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
  KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_LSFT, KC_BSPC, KC_ENT,  KC_SPC,  RAISE,   KC_RALT, KC_RGUI, KC_RCTL \
),

/* Gamer
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Fn1  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |Adjust|Lower |Shift |Space |Raise |Adjust| Alt  | GUI  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMER] = LAYOUT( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_ESC,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TAB,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LSFT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_M,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_LCTL, ADJUST,  KC_SPC,  RAISE,   ADJUST,  KC_RALT, KC_RGUI, KC_RCTL \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |Ctrl A|Ctrl S|Ctrl D|Ctrl F|Ctrl G|    |   _  | --+  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Ctrl Z|Ctrl X|Ctrl C|Ctrl V|Ctrl B| |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_GRV,   KC_DEL,  KC_6,         KC_7,    KC_8, KC_9,       KC_0, \
  KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   KC_TILD, KC_BSPC,  KC_CIRC,   KC_AMPR, KC_ASTR, KC_LPRN,    KC_RPRN, \
  KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_ESC,  KC_PIPE,  KC_F6,     KC_UNDS, KC_PLUS, KC_LCBR,    KC_RCBR, \
  KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    ADJUST,  _______,  KC_F12,    _______, _______, S(KC_COMM),S(KC_DOT), \
  _______,   _______,   _______,   _______,   _______,   _______, _______,  _______,   ADJUST,  _______,   _______,  _______ \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
// Start and finish this layer
[_RAISE] = LAYOUT( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,  KC_DEL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,  KC_BSPC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_ESC,  KC_BSLS, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,  \
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, ADJUST,  KC_F12,  _______,_______,S(KC_COMM),S(KC_DOT),  \
  _______, _______, _______, ADJUST,  _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Fn1
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Prev | Play | Next |      |      | PgUp |  Up  |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Mute | VolD | VolU |      | Home | Left | Down | Rght | End  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | PgDn |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN1] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,  KC_DEL, _______, KC_PGUP, KC_UP,   _______, _______, \
  _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Qwerty|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Dvorak|      |Aud on|Aud of|Gamer |AGnorm|AGswap|      |      |      |PrScrn|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Colmak|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  QWERTY,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  DVORAK,  _______, AU_ON,   AU_OFF,  GAMER,   _______, KC_PSCR, AG_NORM, AG_SWAP, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    // case COLEMAK:
    //   if (record->event.pressed) {
    //     #ifdef AUDIO_ENABLE
    //       PLAY_NOTE_ARRAY(tone_colemak, false, 0);
    //     #endif
    //     persistent_default_layer_set(1UL<<_COLEMAK);
    //   }
    //   return false;
    //   break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case GAMER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_GAMER);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case FN1:
      if (record->event.pressed) {
        layer_on(_FN1);
      } else {
        layer_off(_FN1);
      }
      return false;
      break;
  }
  return true;
}
