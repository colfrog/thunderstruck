#pragma once
#include <QRgba64>

#define PALETTE(col) QRgba64::fromArgb32((uint) Palette::col)

enum class Palette : uint {
	ORANGE_BRIGHT = 0xff8b07,
	ORANGE = 0xd27305,
	ORANGE_DARK = 0xaf6005,
	ORANGE_DARKER = 0x384103,

	GREEN_BRIGHT = 0xa7c83b,
	GREEN = 0x7f962b,
	GREEN_DARK = 0x53641c,
	GREEN_DARKER = 0x374112,

	BLUE_BRIGHT = 0x39d4ff,
	BLUE = 0x2ca7c8,
	BLUE_DARK = 0x1e768c,
	BLUE_DARKER = 0x134d5a,

	PURPLE_BRIGHT = 0x771cff,
	PURPLE = 0x5814be,
	PURPLE_DARK = 0x430e91,
	PURPLE_DARKER = 0x1c063c,

	BLACK = 0x000000,
	WHITE = 0xffffff
};
