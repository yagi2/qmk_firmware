#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

// Layers
enum lets_split_layers {
  _DEFAULT,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Special Keycodes
enum lets_split_keycodes {
  DEFAULT = SAFE_RANGE
};

// Keycodes define
#define LOW_ES  LT(_LOWER, KC_LANG2)  // タップで英数 ホールドでLower
#define RIS_KN  LT(_RAISE, KC_LANG1)  // タップでかな ホールドでRaise

#define ADJUST  MO(_ADJUST)           // ホールドでAdjustレイヤーをon
#define MY_VOLD LALT(LSFT(KC_VOLD))   // 細かいボリュームダウン
#define MY_VOLU LALT(LSFT(KC_VOLU))   // 細かいボリュームアップ

#define TGL_LOW TG(_LOWER)            // Lowerトグル
#define TGL_RIS TG(_RAISE)            // Raiseトグル

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Default
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | '    |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Adjust| Alt | GUI  |英数/L |Space |Space |かな/R | Left | Up   | Down |Right|
 * `-----------------------------------------------------------------------------------'
 */
[_DEFAULT] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTRL,KC_A,    KC_S,    KC_D,     KC_F,    KC_G,    KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN, KC_ENT , \
  KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT, \
  KC_ESC,  ADJUST,  KC_LALT, KC_LGUI,  LOW_ES,  KC_SPC,  KC_SPC,  RIS_KN,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   4  |   5  |   6  |   -  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   1  |   2  |   3  |   +  |   *  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  |   ,  |   .  |   /  |   =  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_ESC , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_DEL,  \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_4,    KC_5,    KC_6,   KC_PMNS, _______, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_1,    KC_2,    KC_3,   KC_PPLS, KC_PAST, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_COMM, KC_DOT, KC_PSLS, KC_PEQL  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | Vol- | Vol+ | Mute |   \  |   `  |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | Prev | Next | Play |   |  |   ~  |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
  _______, XXXXXXX, MY_VOLD, MY_VOLU, KC_MUTE, KC_BSLS, KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC ,KC_RBRC, _______, \
  _______, XXXXXXX, KC_MRWD, KC_MFFD, KC_MPLY, KC_PIPE, KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, \
  _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______  \
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      |Reset |      |      |      |TglLow|TglRis|      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Power |      |      |Aud on|Audoff|      |      | DFLT |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|      |      |BLtogg| BL - | BL + |BLstep|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = KEYMAP( \
  XXXXXXX, RESET,   XXXXXXX, XXXXXXX, TGL_LOW, TGL_RIS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_POWER,XXXXXXX, MU_MOD,  AU_ON,   AU_OFF,  XXXXXXX, XXXXXXX, DEFAULT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  XXXXXXX, XXXXXXX, BL_TOGG, BL_DEC,  BL_INC,  BL_STEP, XXXXXXX, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)
};

void init_layer(void) {
  layer_off(_LOWER);
  layer_off(_RAISE);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DEFAULT:
      if (record->event.pressed) {
        init_layer();
        set_single_persistent_default_layer(_DEFAULT);
      }
      return false;
      break;
    
    case LOW_ES:
      if (record->event.pressed) {
        if (IS_LAYER_ON(_LOWER)) {
          layer_off(_LOWER);
          return false;
          break;
        }
      }
      return true;
      break;

    case RIS_KN:
      if (record->event.pressed) {
        if (IS_LAYER_ON(_RAISE)) {
          layer_off(_RAISE);
          return false;
          break;
        }
      }
      return true;
      break;
  }

  return true;
}