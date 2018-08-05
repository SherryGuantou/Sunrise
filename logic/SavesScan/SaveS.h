#pragma once

#include"jsoncpp/json/value.h"

#include"logic/Item.h"
#include"logic/Hero.h"

class SacveS {
public:
	SacveS() = delete;
	~SacveS() = delete;

public:
	static void saveItem(Json::Value &in,Item &tItem);

	static void savePlayer(Json::Value &in, Player &tPlayer);
	static void saveAI(Json::Value &in, AI &tAI);

public:
	static void Save(Player &in);
};