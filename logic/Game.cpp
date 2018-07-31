#include "Game.h"

#include<fstream>

#include<cocos2d.h>

#include"jsoncpp/json/reader.h"

#include"logic/ConsoleManager.h"
#include"logic/SavesScan/ReadS.h"
#include"runtime/Others.h"
#include"runtime/Macros.h"
#include"ui/Resource.h"

Game::Game() {
	Read();
	ConsoleManager::Get()->
		AddCommand("/back", 0,
				   [](std::vector<std::string>)->bool {
					   cocos2d::Director::getInstance()->popScene();
					   return true;
				   }
	);
	ConsoleManager::Get()->
		AddCommand("/exit", 0,
				   [](std::vector<std::string>)->bool {
					   cocos2d::Director::getInstance()->end();
					   return true;
				   }
	);
}

Game * Game::Get() {
	static Game t;
	return &t;
}

void Game::Read() {
	Json::Value Root;
	Json::Reader R;
	std::string name = cocos2d::FileUtils::getInstance()->fullPathForFilename(CONFIG_LEVEL);
	R.parse(std::fstream(name), Root);

	for(auto t : Root["Level"]) {
		Level tLevel;
		tLevel.LevelName = t["Name"].asString();

		Json::Value& boss = t["Boss"];
		tLevel.Boss=ReadS::getAI(boss);

		for(auto le : t["Leaves"]) {
			Item lea = getItem(le);
			float pro = le["Pro"].asFloat();
			tLevel.Leaves.push_back({lea, pro});
		}

		tLevel.Exp = t["Exp"].asInt();
		tLevel.Gold = t["Gold"].asInt();

		Levels.push_back(tLevel);
	}

	//player
	name = cocos2d::FileUtils::getInstance()->fullPathForFilename(CONFIG_SAVE);
	R.parse(std::fstream(name), Root);
	Json::Value& p = Root["Player"];
	MainPlayer = ReadS::getPlayer(p);

	/*MainPlayer.name = p["Name"].asString();
	MainPlayer.AD = p["AD"].asInt();
	MainPlayer.AP = p["AP"].asInt();
	MainPlayer.AC = p["AC"].asInt();
	MainPlayer.PC = p["PC"].asInt();
	int temp = 0;
	for(auto nItem : p["Bag"]) {
		MainPlayer.Bag[temp] = getItem(nItem);
		temp++;
	}*/
}

void Game::Save() {
}

Item Game::getItem(Json::Value & in) {
	Item nBag;
	auto bag = in;
	nBag.AC = bag["AC"].asInt();
	nBag.AD = bag["AD"].asInt();
	nBag.AP = bag["AP"].asInt();
	nBag.PC = bag["PC"].asInt();
	nBag.name = bag["Name"].asString();
	return nBag;
}

BattleTime * Game::GetBattle() {
	return Battle;
}

void Game::BeginBattle(unsigned int tLevel, 
	std::function<void()> tShowCallback, 
	std::function<void()> tUpdateCallback,
	std::function<void(bool)> tResultCallback) {

	Battle = new BattleTime(tLevel, tShowCallback, tUpdateCallback,tResultCallback);
	Battle->ExchangeTurn();
}

void Game::EndBattle() {
	delete Battle;
}