# _henry_'s colemak layout

This keymap is `henry`'s Colemak layout for Naked48 keyboard, but treats it as 36 keys keyboard instead. This is revision 10 of the layout.
Currently all keys on base layer are used, adding secondary functions to add a way to ensure those keys are not faulty.

## TODO:

- [ ] Try out [`leader`](https://docs.qmk.fm/#/feature_leader_key) key.
- [ ] Remove testing keys when it's finished, add useful ones to other layers.
- [ ] Add function keys (F1-F12) if necessary.
- [ ] Re-add tap hold modifiers if turns out to be useful. Be mindful of the caveats:
  - Needs to update all keys to use tap-hold to prevent key being sent after another key.
  - Need to check if current timer implementation is usable across multiple keys (whether or not each key get its own timer).
- [ ] Add tap dance to alternate between numbers and their symbols, alternate quotes, alternate colons, etc.

Learn more features here: https://docs.qmk.fm/#/features
