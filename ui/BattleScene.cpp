#include"BattleScene.h"

#include<functional>

#include"runtime/Resource.h"
#include"ui/ConsoleLayer.h"
#include"ui/TableLayer.h"
#include"runtime/Macros.h"
#include"logic/Game.h"

USING_NS_CC;
BattleScene* BattleScene::create(unsigned int tLevel) {
	BattleScene *pRet = new(std::nothrow) BattleScene();
	if(pRet && (pRet->ThisLevel = tLevel, true) && pRet->init()) {
		pRet->autorelease();
		return pRet;
	}
	else {
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool BattleScene::init() {
	if(!Scene::init()) {
		return false;
	}
	auto VisionSize = Director::getInstance()->getVisibleSize();

	//Background
	auto Background = Sprite::create(Resource::Assets::Images::BattleBG);
	Background->setPosition(Vec2(VisionSize.width / 2, VisionSize.height / 2));
	Background->setContentSize(VisionSize);
	this->addChild(Background);

	//TableLayer
	Table = TableLayer::create();
	this->addChild(Table);

	//BeginBattle
	GET(Game)BeginBattle(
		ThisLevel,
		std::bind(&BattleScene::ShowTable, this),
		std::bind(&TableLayer::Update, Table),
		std::bind(&BattleScene::ShowResult, this, std::placeholders::_1)
	);

	//Keyboard
	CONSOLE_KEY;

	GET(Game)GetBattle()->ThisLevel = ThisLevel;

	return true;
}

void BattleScene::ShowTable() {
	Table->setVisible(true);
}

void BattleScene::ShowResult(bool tResult) {
	Result = ResultLayer::create(tResult);
	this->addChild(Result);
}