#include "BattleTime.h"

#include<string>
#include<cstdlib>

#include"logic/Game.h"
#include"logic/ConsoleManager.h"
#include"logic/SavesScan/SaveS.h"

BattleTime::BattleTime(
	unsigned int tLevel, 
	std::function<void()> tShowCallback, 
	std::function<void()> tUpdateCallback,
	std::function<void(bool)> tResultCallback) {

	P1 = Game::Get().MainPlayer;
	P1.ShowTable = tShowCallback;
	P2 = Game::Get().Levels[tLevel].Boss;
	isPlayerTurn = false;
	UpdateCallback = tUpdateCallback;
	ResultCallback = tResultCallback;
}

void BattleTime::Damage(Hero* From, Hero* To) {
	float AD = (float)From->GetAD(), AC = (float)To->GetAC();
	int Damage = (int)(AD * (1 - (AC / (AC + 200))));
	if(To->HP > Damage) {
		To->HP -= Damage;
	}
	else {
		if(To->AI) {
			Victory();
			return;
		}
		else {
			Defeat();
			return;
		}
	}

	ExchangeTurn();
	return;
}

void BattleTime::ExchangeTurn() {
	isPlayerTurn = !isPlayerTurn;
	if(isPlayerTurn) {
		P1.Action();
	}
	else {
		P2.Action();
	}
	UpdateCallback();
	return;
}

void BattleTime::PlayerAttack() {
	Damage(&P1, &P2);
}

void BattleTime::AIAttack() {
	Damage(&P2, &P1);
}

void BattleTime::Victory() {
	HasBeenShut = true;
	auto game = Game::Get();
	auto battle = Game::Get().GetBattle();
	game.MainPlayer.Exp += game.Levels[ThisLevel].Exp;
	game.MainPlayer.Gold += game.Levels[ThisLevel].Gold;

	//处理战利品
	for (auto nItem : game.Levels[ThisLevel].Leaves) {
		float tRand = std::rand() / RAND_MAX;
		if (tRand > nItem.pro) {
			game.MainPlayer.Items.push_back(nItem.item);
			Results.push_back(nItem.item.name);
		}
	}

	SacveS::Save(game.MainPlayer);
	ResultCallback(true);
}

void BattleTime::Defeat() {
	HasBeenShut = true;
	auto game = Game::Get();

	SacveS::Save(game.MainPlayer);
	ResultCallback(false);
}