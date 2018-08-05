#pragma once

#include<fstream>

#include"logic/Hero.h"

#include"jsoncpp/json/reader.h"
#include"logic/LevelData.h"
class ReadS {
public:
	ReadS() = delete;
	~ReadS() = delete;

public:
	static Player getPlayer(Json::Value &in);
	static AI getAI(Json::Value &in);

	static Item getItem(Json::Value &in);

	static LevelData getLevelData(Json::Value &in);
};