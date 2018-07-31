#include "Hero.h"

#include"logic/Game.h"

int Hero::GetAD() {
	unsigned int tAD = 0;
	for(int i = 0; i < 6; i++) {
		tAD += Bag[i].AD;
	}
	tAD += AD;
	return tAD;
}

int Hero::GetAP() {
	unsigned int tAP = 0;
	for(int i = 0; i < 6; i++) {
		tAP += Bag[i].AP;
	}
	tAP += AP;
	return tAP;
}

int Hero::GetAC() {
	unsigned int tAC = 0;
	for(int i = 0; i < 6; i++) {
		tAC += Bag[i].AC;
	}
	tAC += AC;
	return tAC;
}

int Hero::GetPC() {
	unsigned int tPC = 0;
	for(int i = 0; i < 6; i++) {
		tPC += Bag[i].PC;
	}
	tPC += PC;
	return tPC;
}

void AI::Action() {
	Game::Get()->GetBattle()->AIAttack();
}

void Player::Action() {
	ShowTable();
}