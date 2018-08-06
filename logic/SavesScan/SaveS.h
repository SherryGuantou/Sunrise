#pragma once

#include"jsoncpp/json/value.h"

#include"logic/Item.h"
#include"logic/Hero.h"

class SaveS {
public:
	SaveS() = delete;
	~SaveS() = delete;

public:
	static void saveItem(Json::Value &in, Item &tItem);

	static void savePlayer(Json::Value &in, Player &tPlayer);
	static void saveAI(Json::Value &in, AI &tAI);

public:
	static void Save(Player &in);
};