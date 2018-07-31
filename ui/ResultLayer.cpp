#include"ui/ResultLayer.h"
#include"ui/Resource.h"
#include"runtime/Macros.h"

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

	}
	
	//BackButton
	BackButton = CreateDefaultButton("BackButton", Vec2(512, 320), Size(100, 50), 
		[](Ref*, ui::Widget::TouchEventType tEvent) {
		cocos2d::Director::getInstance()->popScene();
		}, T("·µ»Ø"), FONTS_KAI);
	this->addChild(BackButton);

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
