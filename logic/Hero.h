#pragma once

#include<vector>
#include<functional>
#include <string>

#include"logic/Item.h"

class Hero {
public:
	Hero() = default;
	~Hero() = default;

public:
	std::string name;
	unsigned int HP, HP_Limit; //血
	unsigned int MP, MP_Limit; //蓝
	unsigned int AD, /* 物理攻击 */
		AP,/* 法术强度 */
		AC,/* 护甲 */
		PC,/* 魔抗 */
		Le,/*等级*/
		Exp,/*当前经验*/
		Gold
		;
	Item Bag[6] {};//装备栏

	std::vector<Item> Items;//背包
	bool AI = false;

public:
	int GetAD();
	int GetAP();
	int GetAC();
	int GetPC();

public:
	virtual void Action() = 0;
};

class AI: public Hero {
public:
	AI() {
		Hero::AI = true;
	}
public:
	void Action() override;
};

class Player: public Hero {
public:
	Player() {
		Hero::AI = false;
	}
public:
	void Action() override;

public:
	std::function<void()> ShowTable;
};