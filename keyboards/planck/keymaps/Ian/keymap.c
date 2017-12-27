#include "planck.h"

#include "action_layer.h"
//define layers


enum planck_layers {
  _COLEMAK,
  _ADJUST,
  _RAISE,
  _LOWER
};
#define BASELYR TO(_COLEMAK) // base layer
#define LOWER MO(_LOWER) // momentary lower layer
#define RAISE MO(_RAISE) // momentary raise layer
#define ADJUST MO(_ADJUST) // momentary adjust layer
#define LLOWER TG(_LOWER) // lock for lower layer
#define LRAISE TG(_RAISE) // lock for raise layer
enum planck_keycodes {
    LHALF = SAFE_RANGE,
    TLHALF,
    BLHALF,
    RHALF,
    TRHALF,
    BRHALF,
    CENTER,
    FULL,
    SAFBACK,
    SAFFWD	
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | bspc |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Tab |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  \   |   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | Cmd  |Lower |  spc | shft |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
    {KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,  KC_G,   KC_J,    KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
    {KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,  KC_D,   KC_H,    KC_N,  KC_E,    KC_I,    KC_O,    KC_QUOT},
    {KC_BSLS, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_K,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
    {ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_LSFT, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

[_ADJUST] = {
    {BASELYR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
    {_______, KC_F10,  KC_F11,  KC_F12,  LLOWER,  XXXXXXX, XXXXXXX, LRAISE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Raisez
 * ,-----------------------------------------------------------------------------------
 * |      |   !  |   @  |   #  |   $  |  {   |   }  |  WTL |   WC |  WTR |   F4 | bspc |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   %  |   ^  |   &  |   *  |  (   |   )  |  WL  |  WF  |  WR  |   F8 | VOL+ |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   _  |   +  |   -  |   =  |  [   |   ]  |  WBL |      |  WBR |  F12 | VOL- |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |  F14 |  F15 | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
    {BASELYR, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_LCBR, KC_RCBR, TLHALF,  CENTER,  TRHALF, XXXXXXX, KC_BSPC},
    {KC_TILD, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, LHALF,   FULL,    RHALF,  XXXXXXX, KC_VOLU},
    {KC_GRV,  KC_MINS, KC_PLUS, KC_UNDS, KC_EQL,  KC_LBRC, KC_RBRC, BLHALF,  XXXXXXX, BRHALF, XXXXXXX, KC_VOLD},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, KC_SPC,  KC_LSFT, KC_TRNS, XXXXXXX, KC_F14, KC_F15,  KC_MUTE}
},

/* lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |   {  |   }  |   7  |   8  |   9  |   -  | bspc |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | back |      |      |   (  |   )  |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |   [  |   ]  |   1  |   2  |   3  |   *  |  ent |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  |  00  |   .  |   /  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
    {BASELYR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_7,  KC_8, KC_9,   KC_MINS,  KC_BSPC},
    {XXXXXXX, XXXXXXX, SAFBACK, XXXXXXX, SAFFWD,  KC_LPRN, KC_RPRN, KC_4,  KC_5, KC_6,   KC_PLUS,  XXXXXXX},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_1,  KC_2, KC_3,   KC_ASTR,  KC_ENT},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, KC_SPC,  KC_LSFT, KC_0,  KC_0, KC_DOT, KC_SLASH, XXXXXXX}
}

};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case LHALF:
          if (record->event.pressed) {
         SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI)SS_TAP(X_LEFT)SS_UP(X_LALT)SS_UP(X_LGUI));
          }
          return false;
          break;
      case TLHALF:
          if (record->event.pressed) {
              SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LGUI)SS_TAP(X_LEFT)SS_UP(X_LCTRL)SS_UP(X_LGUI));
          }
          return false;
          break;
      case BLHALF:
          if (record->event.pressed) {
              SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_DOWN(X_LGUI)SS_TAP(X_LEFT)SS_UP(X_LCTRL)SS_UP(X_LSHIFT)SS_UP(X_LGUI));
          }
          return false;
          break;
      case RHALF:
          if (record->event.pressed) {
              SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI)SS_TAP(X_RIGHT)SS_UP(X_LALT)SS_UP(X_LGUI));
          }
          return false;
          break;
      case TRHALF:
          if (record->event.pressed) {
              SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LGUI)SS_TAP(X_RIGHT)SS_UP(X_LCTRL)SS_UP(X_LGUI));
          }
          return false;
          break;
      case BRHALF:
          if (record->event.pressed) {
              SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_DOWN(X_LGUI)SS_TAP(X_RIGHT)SS_UP(X_LCTRL)SS_UP(X_LSHIFT)SS_UP(X_LGUI));
          }
          return false;
          break;
      case CENTER:
          if (record->event.pressed) {
              SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI)SS_TAP(X_C)SS_UP(X_LALT)SS_UP(X_LGUI));
          }
          return false;
          break;
    case FULL:
         if (record->event.pressed) {
             SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI)SS_TAP(X_F)SS_UP(X_LALT)SS_UP(X_LGUI));
        }
      return false;
      break;
      case SAFFWD:
          if (record->event.pressed) {
              SEND_STRING(SS_LGUI("]"));
          }
          return false;
          break;
      case SAFBACK:
          if (record->event.pressed) {
              SEND_STRING(SS_LGUI("["));
          }
          return false;
          break;
  }
  return true;
}
