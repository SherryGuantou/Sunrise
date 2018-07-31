#include"LevelScene.h"

#include"ui/Resource.h"
#include"ui/ConsoleLayer.h"
#include"ui/BattleScene.h"
#include"runtime/Macros.h"

USING_NS_CC;

bool LevelScene::init() {
	if(!Scene::init()) {
		return false;
	}
	auto VisionSize = Director::getInstance()->getVisibleSize();

	//Keyboard
	CONSOLE_KEY;

	ConsoleManager::Get()->
		AddCommand("/setpos", 3,
				   [&](std::vector<std::string> t)->bool {
					   this->getChildByName(t[0])->setPosition(Vec2(std::stof(t[1]), std::stof(t[2])));
					   return true;
				   }
	);

	//Background
	auto Background = Sprite::create(DIR_IMAGES + "Background.png");
	Background->setPosition(Vec2(VisionSize.width / 2, VisionSize.height / 2));
	Background->setContentSize(VisionSize);
	this->addChild(Background);

	//Level
	Level1 = CreateDefaultButton("Level1", Vec2(112, 80), Size(160, 70), CC_CALLBACK_2(LevelScene::ButtonCallback, this), T("风暴城\n  ☆"), FONTS_KAI);
	Level2 = CreateDefaultButton("Level2", Vec2(416, 216), Size(160, 70), CC_CALLBACK_2(LevelScene::ButtonCallback, this), T("冰霜山脊\n  ☆"), FONTS_KAI);
	Level3 = CreateDefaultButton("Level3", Vec2(100, 380), Size(160, 70), CC_CALLBACK_2(LevelScene::ButtonCallback, this), T("星殿殿门\n  ☆"), FONTS_KAI);
	Level4 = CreateDefaultButton("Level4", Vec2(220, 520), Size(160, 70), CC_CALLBACK_2(LevelScene::ButtonCallback, this), T("加拉神殿\n  ☆"), FONTS_KAI);
	Level5 = CreateDefaultButton("Level5", Vec2(160, 650), Size(160, 70), CC_CALLBACK_2(LevelScene::ButtonCallback, this), T("神殿瞭望台\n  ☆"), FONTS_KAI);
	Level6 = CreateDefaultButton("Level6", Vec2(350, 700), Size(160, 70), CC_CALLBACK_2(LevelScene::ButtonCallback, this), T("阿拉德右翼\n  ☆"), FONTS_KAI);
	Level7 = CreateDefaultButton("Level7", Vec2(450, 570), Size(160, 70), CC_CALLBACK_2(LevelScene::ButtonCallback, this), T("阿拉德右翅\n  ☆"), FONTS_KAI);
	Level8 = CreateDefaultButton("Level8", Vec2(800, 500), Size(160, 70), CC_CALLBACK_2(LevelScene::ButtonCallback, this), T("阿拉德左翅\n  ☆"), FONTS_KAI);
	Level9 = CreateDefaultButton("Level9", Vec2(900, 600), Size(160, 70), CC_CALLBACK_2(LevelScene::ButtonCallback, this), T("阿拉德左翼\n  ☆"), FONTS_KAI);
	Level10 = CreateDefaultButton("Level10", Vec2(740, 370), Size(160, 70), CC_CALLBACK_2(LevelScene::ButtonCallback, this), T("阿拉德\n  ☆"), FONTS_KAI);
	this->addChild(Level1);
	this->addChild(Level2);
	this->addChild(Level3);
	this->addChild(Level4);
	this->addChild(Level5);
	this->addChild(Level6);
	this->addChild(Level7);
	this->addChild(Level8);
	this->addChild(Level9);
	this->addChild(Level10);

	return true;
}

void LevelScene::ButtonCallback(Ref* sender, ui::Widget::TouchEventType type) {
	if(type == ui::Widget::TouchEventType::BEGAN) {
		unsigned int i = (unsigned)-1;
		if(sender == Level1) {
			i = 0;
		}
		else if(sender == Level2) {
			i = 1;
		}
		else if(sender == Level3) {
			i = 2;
		}
		Director::getInstance()->pushScene(BattleScene::create(i));
	}
}