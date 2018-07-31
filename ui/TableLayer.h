#pragma once

#include<cocos2d.h>

class TableLayer: public cocos2d::Layer {
public:
	CREATE_FUNC(TableLayer);
public:
	virtual bool init();

private:
	cocos2d::Label* PlayerLabel;
	cocos2d::Label* AILabel;

public:
	void Update();
};