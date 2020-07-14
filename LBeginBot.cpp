#include "LBeginBot.h"

#include <QVector>

#include "LBoard.h"
#include "LPath.h"
#include "LSquare.h"
#include "LFigure.h"

LPath* LBeginBot::calculateBestMove()
{
	QVector<LPath*> paths = this->uglyMoves();

	int size = paths.size();

	LPath* path;

	if (size)
	{
		int value = 0;
		int index = -1;

		for (int i = 0; i < size; i++)
		{
			LPath* tempPath = paths[i];

			LSquare* from = tempPath->getFrom();
			LSquare* to = tempPath->getTo();

			int fromVer = from->getVertical();
			int fromHor = from->getHorizontal();

			int toVer = to->getVertical();
			int toHor = to->getHorizontal();

			int tempValue = 0;

			if (this->board->getFigure(toVer, toHor))
			{
				tempValue = this->board->getFigure(toVer, toHor)->getValue();
			}

			if (value < tempValue)
			{
				value = tempValue;
				index = i;
			}
		}

		if (index != -1)
		{
			path = paths[index]->getClone();
		}
		else
		{
			path = paths[rand() % size]->getClone();
		}
	}

	for (int i = 0; i < size; i++)
	{
		delete paths[i];
	}

	return path;
}