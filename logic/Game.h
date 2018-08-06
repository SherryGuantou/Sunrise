#pragma once

#include<vector>
#include<functional>

#include"jsoncpp/json/value.h"

#include"runtime/Singletion.h"
#include"logic/Level.h"
#include"logic/BattleTime.h"
#include"logic/LevelData.h"

class Game {
	SINGLETION_CLASS_WITH_INIT(Game);
private:
	void Init();

	/* Data */
public:
	Player MainPlayer;
	std::vector<Level> Levels;
	std::vector<LevelData> LevelDatas;

public:
	void Read();
	void Save();
	Item getItem(Json::Value &in);

	/* Battle */
private:
	BattleTime * Battle;
public:
	BattleTime * GetBattle();
	/* Battle: Interface to UI */
public:
	void BeginBattle(unsigned int tLevel,
					 std::function<void()> tShowCallback,
					 std::function<void()> tUpdateCallback,
					 std::function<void(bool)> tResultCallback);
	void EndBattle();
};