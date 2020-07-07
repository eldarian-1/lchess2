#include "LGame.h"

#include "LConst.h"
#include "LNewGame.h"

#include "LBiGame.h"
#include "LBotGame.h"
#include "LNetGame.h"

LGame* LGame::instance = nullptr;

LGame::LGame()
	:
	isChecked(false),
	gameInstance(L_GAME_RUNNING)
{

}

LGame* LGame::getInstance()
{
	return instance;
}

int LGame::getGameInstance() const
{
	return this->gameInstance;
}

void LGame::changeGameInstance(int gameInstance)
{
	this->gameInstance = gameInstance;
}

void LGame::newGame(LNewGame* dialog)
{
	int gameType = dialog->getGameType();
	int color = dialog->getColor();
	QString name1 = dialog->getName1();
	QString name2 = dialog->getName2();

	if (instance)
	{
		instance->clear();
		instance = nullptr;
	}

	switch (gameType)
	{
	case L_TYPE_BI:
		instance = new LBiGame(name1, name2, color);
		break;
	case L_TYPE_BOT:
		instance = new LBotGame(color);
		break;
	case L_TYPE_NET:
		instance = new LNetGame(color);
		break;
	}
}

void LGame::setChecked(bool isChecked)
{
	if (this->isChecked != isChecked)
	{
		if (isChecked)
			this->checked();
		else
			this->unchecked();

		this->isChecked = isChecked;
	}
}
