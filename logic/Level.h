#pragma once

#include<string>
#include<map>
#include<vector>

#include"logic/Hero.h"
#include"logic/Item.h"

struct Level {
	std::string LevelName;

	AI Boss;

	struct PItem {
		Item item;
		float pro;
	};
	//std::map<Item, float> Leaves;
	std::vector<PItem> Leaves;

	unsigned int Exp, Gold;
};