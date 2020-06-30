#pragma once

#include "LFigure.h"

class LQueen final
	: public LFigure
{
public:
	LQueen(int color);

	void draw(LSquare* position, bool reverse) override;
	bool isPossiblePosition(LSquare* oldPosition, LSquare* newPosition) override;
	QString getName() const override;

};
