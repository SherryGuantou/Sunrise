#pragma once

#include<functional>

#include"logic/Hero.h"

class BattleTime {
public:
	BattleTime(
		unsigned int tLevel, 
		std::function<void()> tShowCallback, 
		std::function<void()> tUpdateCallback,
		std::function<void(bool)> tResultCallback
	);
	~BattleTime() = default;

public:
	Player P1;
	AI P2;
	bool isPlayerTurn;
	unsigned int ThisLevel;
	std::vector<std::string> Results;
	bool HasBeenShut = false;

	std::function<void()> UpdateCallback;
	std::function<void(bool tResult)> ResultCallback;

public:
	void ExchangeTurn();
	void Damage(Hero* From, Hero* To);
	void PlayerAttack();
	void AIAttack();

	void Victory();
	void Defeat();
};