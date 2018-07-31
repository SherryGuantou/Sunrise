#pragma once

#include<cocos2d.h>

#include"logic/ConsoleManager.h"
#include"ui/ResultLayer.h"

class TableLayer;

class BattleScene: public cocos2d::Scene {
public:
	static BattleScene* create(unsigned int tLevel);
	virtual bool init();
public:
	CONSOLE_KEY_PRE;

private:
	unsigned int ThisLevel;
	TableLayer* Table;
	ResultLayer* Result;

public:
	void ShowTable();
	void ShowResult(bool tResult);
};