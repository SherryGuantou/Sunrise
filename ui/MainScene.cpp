#include"MainScene.h"

#include<ui/CocosGUI.h>

#include"ui/CharacterScene.h"
#include"ui/Resource.h"
#include"ui/ConsoleLayer.h"
#include"ui/LevelScene.h"
#include"runtime/Others.h"
#include"logic/ConsoleManager.h"

USING_NS_CC;

bool MainScene::init() {
	if(!Scene::init()) {
		return false;
	}
	CharWidgetOpened = false;

	auto VisionSize = Director::getInstance()->getVisibleSize();

	//Keyboard
	CONSOLE_KEY;

	//Background
	auto Background = Sprite::create(DIR_IMAGES + "Background.png");
	Background->setPosition(Vec2(VisionSize.width / 2, VisionSize.height / 2));
	Background->setContentSize(VisionSize);
	this->addChild(Background);

	//LevelButton
	this->addChild(CreateDefaultButton("Level", Vec2(582, 62), Size(80, 80),
				   [&](Ref* sender, ui::Widget::TouchEventType type) {
					   if(type == ui::Widget::TouchEventType::BEGAN) {
						   Director::getInstance()->pushScene(LevelScene::create());
					   }
				   },
				   T("出发"), FONTS_KAI, 32, Color3B(0, 0, 0))
	);

	//CharacterButton
	this->addChild(CreateDefaultButton("Character", Vec2(664, 62), Size(80, 80),
				   [&](Ref* sender, ui::Widget::TouchEventType type) {
					   if(type == ui::Widget::TouchEventType::BEGAN) {
						   if(CharWidgetOpened) {
							   this->removeChildByName("CharWidget");
						   }
						   else {
							   auto ch = CharacterWidget::create();
							   ch->setPosition(Vec2(224, 102));
							   ch->setName("CharWidget");
							   this->addChild(ch);
						   }
						   CharWidgetOpened = !CharWidgetOpened;
					   }
				   },
				   T("人物"), FONTS_KAI, 32, Color3B(0, 0, 0))
	);

	//BagButton
	this->addChild(CreateDefaultButton("Bag", Vec2(746, 62), Size(80, 80),
				   [](cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
					   if(type == ui::Widget::TouchEventType::BEGAN) {
						   //TODO: BagLayer
					   }
				   },
				   T("背包"), FONTS_KAI, 32, Color3B(0, 0, 0))
	);

	//ShopButton
	this->addChild(CreateDefaultButton("Shop", Vec2(828, 62), Size(80, 80),
				   [](cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
					   if(type == ui::Widget::TouchEventType::BEGAN) {
					   }
				   },
				   T("商店"), FONTS_KAI, 32, Color3B(0, 0, 0))
	);

	//ExitButton
	this->addChild(CreateDefaultButton("Exit", Vec2(910, 62), Size(80, 80),
				   [](cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
					   if(type == ui::Widget::TouchEventType::BEGAN) {
						   //TODO: Save
						   Director::getInstance()->end();
					   }
				   },
				   T("退出"), FONTS_KAI, 32, Color3B(0, 0, 0))
	);

	return true;
}