#pragma once

#include<cocos2d.h>
#include<ui/CocosGUI.h>

#include"logic/ConsoleManager.h"

class LevelScene: public cocos2d::Scene {
public:
	CREATE_FUNC(LevelScene);

	virtual bool init();

	CONSOLE_KEY_PRE;

public:
	void ButtonCallback(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);
private:
	cocos2d::ui::Button* Level1;
	cocos2d::ui::Button* Level2;
	cocos2d::ui::Button* Level3;
	cocos2d::ui::Button* Level4;
	cocos2d::ui::Button* Level5;
	cocos2d::ui::Button* Level6;
	cocos2d::ui::Button* Level7;
	cocos2d::ui::Button* Level8;
	cocos2d::ui::Button* Level9;
	cocos2d::ui::Button* Level10;
};