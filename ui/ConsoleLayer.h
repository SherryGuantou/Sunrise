#pragma once

#include<string>

#include<cocos2d.h>
#include<ui/CocosGUI.h>

class ConsoleLayer: public cocos2d::Layer {
public:
	virtual bool init() override;
	CREATE_FUNC(ConsoleLayer);
	~ConsoleLayer() override;

private:
	cocos2d::ui::TextField* InputTextField;
	cocos2d::Label* OutputLabel;
	cocos2d::ui::ScrollView* OutputScrollView;
	cocos2d::ui::ScrollView* InputScrollView;
	std::size_t HisPos;
private:
	void ResetInput();
	void ResetOutput();
};