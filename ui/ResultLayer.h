#pragma once

#include<cocos2d.h>
#include<ui/CocosGUI.h>

class ResultLayer : public cocos2d::Layer {
public:
	static ResultLayer* create(bool tResult);
public:
	virtual bool init();

private:
	cocos2d::ui::Button* BackButton;

private:
	bool Result;
};