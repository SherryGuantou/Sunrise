#pragma once

#include<cocos2d.h>
#include<ui/CocosGUI.h>

#include"runtime/Resource.h"

inline cocos2d::ui::Button* CreateDefaultButton(std::string Name, cocos2d::Vec2 Pos, cocos2d::Size Size, std::function<void(cocos2d::Ref*, cocos2d::ui::Widget::TouchEventType)> TouchEvent,
												std::string Title, std::string Font, float FontSize = 32, cocos2d::Color3B FontColor = cocos2d::Color3B::BLACK) {
	auto Button = cocos2d::ui::Button::create(Resource::Assets::Images::ButtonNormal, Resource::Assets::Images::ButtonPress, Resource::Assets::Images::ButtonDisable);
	Button->setName(Name);
	Button->setPosition(Pos);
	Button->setScale9Enabled(true);
	Button->setContentSize(Size);
	Button->addTouchEventListener(TouchEvent);
	auto ButtonLabel = cocos2d::Label::createWithTTF(Title, Font, FontSize);
	ButtonLabel->setColor(FontColor);
	Button->setTitleLabel(ButtonLabel);
	return Button;
}