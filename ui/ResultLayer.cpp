#include<string>

#include"ui/ResultLayer.h"
#include"runtime/Resource.h"
#include"runtime/Macros.h"
#include"runtime/RapidFuncs.h"
#include"logic/Game.h"

USING_NS_CC;

bool ResultLayer::init() {
	if(!Layer::init()) {
		return false;
	}
	auto VisionSize = Director::getInstance()->getVisibleSize();

	//background
	if(Result) {
		auto Background = Sprite::create(Resource::Assets::Images::Success);
		Background->setPosition(Vec2(VisionSize.width / 2, VisionSize.height / 2));
		Background->setContentSize(Size(VisionSize.width / 4, VisionSize.height / 4));
		this->addChild(Background);
	}
	else {
		auto Background = Sprite::create(Resource::Assets::Images::Defeat);
		Background->setPosition(Vec2(VisionSize.width / 2, VisionSize.height / 2));
		Background->setContentSize(Size(VisionSize.width / 4, VisionSize.height / 4));
		this->addChild(Background);
	}

	//BackButton
	BackButton = CreateDefaultButton("BackButton", Vec2(512, 320), Size(100, 50),
									 [](Ref*, ui::Widget::TouchEventType tEvent) {
										 GET(Game)EndBattle();
										 cocos2d::Director::getInstance()->popScene();
									 }, T("����"), Resource::Assets::Fonts::Kai);
	this->addChild(BackButton);

	//Results
	if(Result) {
		std::string rItems;

		auto ResultLable = Label::createWithTTF(T("ʤ������:\n���飺") +
												std::to_string(GET(Game)Levels[GET(Game)GetBattle()->ThisLevel].Exp) +
												T("  ��ң�") +
												std::to_string(GET(Game)Levels[GET(Game)GetBattle()->ThisLevel].Gold) +
												T("\n��Ʒ��\n") +
												rItems, Resource::Assets::Fonts::Kai, 25);
		ResultLable->setPosition(Vec2(760, 440));
		this->addChild(ResultLable);
	}

	return true;
}

ResultLayer* ResultLayer::create(bool tResult) {
	ResultLayer *pRet = new(std::nothrow) ResultLayer();
	if(pRet && (pRet->Result = tResult, true) && pRet->init()) {
		pRet->autorelease();
		return pRet;
	}
	else {
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}