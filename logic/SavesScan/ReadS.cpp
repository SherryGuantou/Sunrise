#include "ReadS.h"

#include"logic/Game.h"


/*
*此处需要保证 in 是以“Player”为根的Json
*没有错误检验！！！
*用于构造Player对象
*/
Player ReadS::getPlayer(Json::Value & in)
{
	Player tPlayer;
	tPlayer.name = in["Name"].asString();
	tPlayer.AD = in["AD"].asInt();
	tPlayer.AP = in["AP"].asInt();
	tPlayer.PC = in["PC"].asInt();
	tPlayer.AC = in["AC"].asInt();
	tPlayer.HP = in["HP"].asInt();
	tPlayer.HP_Limit = in["HPL"].asInt();
	tPlayer.MP = in["MP"].asInt();
	tPlayer.MP_Limit = in["MPL"].asInt();
	tPlayer.Le = in["level"].asInt();
	tPlayer.Exp = in["Exp"].asInt();
	tPlayer.Gold = in["Gold"].asInt();
	int  temp = 0;
	for (auto nItem : in["Bag"]) {
		tPlayer.Bag[temp++] = getItem(nItem);
	}
	return tPlayer;
}

AI ReadS::getAI(Json::Value & in)
{
	AI tPlayer;
	tPlayer.name = in["Name"].asString();
	tPlayer.AD = in["AD"].asInt();
	tPlayer.AP = in["AP"].asInt();
	tPlayer.PC = in["PC"].asInt();
	tPlayer.AC = in["AC"].asInt();
	tPlayer.HP = in["HP"].asInt();
	tPlayer.HP_Limit = in["HPL"].asInt();
	tPlayer.MP = in["MP"].asInt();
	tPlayer.MP_Limit = in["MPL"].asInt();
	int  temp = 0;
	for (auto nItem : in["Bag"]) {
		tPlayer.Bag[temp++] = getItem(nItem);
	}
	return tPlayer;
}

/*
*此处需要保证 in 是 Bag 的成员
*没有错误检验！！！
*用于构造Item
*/
Item ReadS::getItem(Json::Value & in)
{
	/*
	{
	"Name":"...",
	"AD":10,
	"AP":0,
	"AC":0,
	"PC":0
	}
	*/
	Item pItem;
	pItem.name = in["Name"].asString();
	pItem.AC = in["AC"].asInt();
	pItem.AD = in["AD"].asInt();
	pItem.AP = in["AP"].asInt();
	pItem.PC = in["PC"].asInt();
	return pItem;
}

LevelData ReadS::getLevelData(Json::Value & in)
{
	LevelData tlevel;
	tlevel.AC = in["AC"].asInt();
	tlevel.AD = in["AD"].asInt();
	tlevel.AP = in["AP"].asInt();
	tlevel.PC = in["PC"].asInt();
	tlevel.HP = in["HP"].asInt();
	tlevel.HP_Limit = in["HPL"].asInt();
	tlevel.MP = in["MP"].asInt();
	tlevel.MP_Limit = in["MPL"].asInt();
	tlevel.Exp_Limit = in["ExpL"].asInt();

	return tlevel;
}
