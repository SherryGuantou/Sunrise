#include<string>

#include"ui/ResultLayer.h"
#include"ui/Resource.h"
#include"runtime/Macros.h"
#include"logic/Game.h"

USING_NS_CC;

bool ResultLayer::init()
{
	if (!Layer::init()) {
		return false;
	}
	auto VisionSize = Director::getInstance()->getVisibleSize();


	//background
	if (Result) {
	auto Background = Sprite::create(DIR_IMAGES + "success.jfif");
	Background->setPosition(Vec2(VisionSize.width / 2, VisionSize.height / 2));
	Background->setContentSize(Size(VisionSize.width/4,VisionSize.height/4));
	this->addChild(Background);

	}else{
		auto Background = Sprite::create(DIR_IMAGES + "defeat.jpg");
		Background->setPosition(Vec2(VisionSize.width / 2, VisionSize.height / 2));
		Background->setContentSize(Size(VisionSize.width / 4, VisionSize.height / 4));
		this->addChild(Background);

	}
	
	//BackButton
	BackButton = CreateDefaultButton("BackButton", Vec2(512, 320), Size(100, 50), 
		[](Ref*, ui::Widget::TouchEventType tEvent) {
		Game::Get().EndBattle();
		cocos2d::Director::getInstance()->popScene();
		}, T("返回"), FONTS_KAI);
	this->addChild(BackButton);

	//Results
	if (Result) {
		std::string rItems;

		auto ResultLable = Label::createWithTTF(T("胜利奖励:\n经验：") +
			std::to_string(Game::Get().Levels[Game::Get().GetBattle()->ThisLevel].Exp) +
			T("  金币：") +
			std::to_string(Game::Get().Levels[Game::Get().GetBattle()->ThisLevel].Gold) +
			T("\n物品：\n") +
			rItems, FONTS_KAI, 25);
		ResultLable->setPosition(Vec2(760, 440));
		this->addChild(ResultLable);
	
	}
	
	return true;
}


ResultLayer* ResultLayer::create(bool tResult) { 
	ResultLayer *pRet = new(std::nothrow) ResultLayer(); 
	if (pRet &&(pRet->Result=tResult,true)&& pRet->init())	{ 
		pRet->autorelease(); 
		return pRet; 
	} 
	else { 
		delete pRet; 
		pRet = nullptr; 
		return nullptr; 
	} 
}
