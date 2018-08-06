#include"CharacterScene.h"

#include<ui/CocosGUI.h>

#include"ui/ConsoleLayer.h"
#include"runtime/Resource.h"
#include"runtime/Macros.h"
#include"runtime/RapidFuncs.h"

USING_NS_CC;

bool CharacterScene::init() {
	if(!Scene::init()) {
		return false;
	}
	//BackButton
	this->addChild(CreateDefaultButton(T("back"), Vec2(23, 745), Size(40, 40),
				   [&](Ref* sender, ui::Widget::TouchEventType type) {
					   switch(type) {
					   case ui::Widget::TouchEventType::BEGAN:

						   Director::getInstance()->popScene();
						   break;
					   }
				   },
				   T("<-"), Resource::Assets::Fonts::Kai, 32, Color3B(0, 0, 0)));

	//Key
	CONSOLE_KEY;

	return true;
}

bool CharacterWidget::init() {
	this->setContentSize(Size(400, 500));

	auto BackGround = LayerColor::create(Color4B::GRAY, 400, 500);
	this->addChild(BackGround);

	auto CharNameLabel = Label::createWithTTF(CharName, Resource::Assets::Fonts::Kai, 32);
	CharNameLabel->setPosition(Vec2(66, 466));
	CharNameLabel->setContentSize(Size(300, 40));
	this->addChild(CharNameLabel);

	auto CharPhotoSprite = Sprite::create(Resource::Assets::Images::ButtonNormal);
	CharPhotoSprite->setPosition(79, 340);
	CharPhotoSprite->setContentSize(Size(133, 182));
	this->addChild(CharPhotoSprite);

	return true;
}