#pragma once

#include<cocos2d.h>

#include"logic/ConsoleManager.h"

class MainScene: public cocos2d::Scene {
public:
	CREATE_FUNC(MainScene);

	virtual bool init();

	CONSOLE_KEY_PRE;
private:
	bool CharWidgetOpened;
};