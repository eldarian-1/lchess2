#pragma once

enum LConst
{
	L_COLOR_WHITE,
	L_COLOR_BLACK,
	L_COLOR_ANY,

	L_TYPE_BI,
	L_TYPE_BOT,
	L_TYPE_NET,

	L_FIGURE_KING,
	L_FIGURE_QUEEN,
	L_FIGURE_ELEPHANT,
	L_FIGURE_HORSE,
	L_FIGURE_ROOK,
	L_FIGURE_PAWN,

	L_PATH_FALSE = 0,
	L_PATH_TRUE = 1,
	L_PATH_CASTLING = 2,
	L_PATH_TRANSFORMATION = 4,

	L_SQUARE_NATIVE,
	L_SQUARE_FOCUSED,
	L_SQUARE_SELECTED,
	L_SQUARE_VARIANT,
	L_SQUARE_VARIANT_FOCUSED,

	L_CHESS_BOARD_SIZE = 8,
	L_FIGURE_COUNT = 32,
	L_SQUARE_COUNT = 64,

	L_WIDTH_MENU = 150,
	L_WIDTH_CHESS = 1130,
	L_HEIGHT = 720
};
