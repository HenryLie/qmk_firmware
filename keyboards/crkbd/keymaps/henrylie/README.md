# henrylie 36 keys crkbd layout

This is my take on 3x5 corne keyboard, utilizing mod-taps and layer hold keys on the thumb area, and additional mod-taps on the home row.
This keymap is based on Colemak layout, and the arrow keys are placed on the other layers on the home row to minimize finger movement.
In Colemak, this means `neio` acts as `←↑↓→`, respectively, which is slightly different from vim arrow keys. I believe this to be more ergonomic since that's where your fingers rest in neutral position when you touch type, and having `up` before `down` also makes more sense for me coming from the commonly found triangular arrangement of arrow keys on most keyboards.

## Compile

Compile the firmware using this command:
> Note 2022-02-23: Firmware size is approaching maximum, 112 bytes left.
> Consider removing: dynamic tapping term, via, and RGBLight to reduce the firmware size.

```sh
make crkbd/rev1/common:henrylie
```

Then flash it to each side of the board by running this command:

```sh
make crkbd/rev1/common:henrylie:avrdude
```

and tapping the flash button next to the promicro 1-2 times when prompted.
