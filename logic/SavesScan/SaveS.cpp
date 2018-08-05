#include "SaveS.h"

#include<fstream>

#include"ui/Resource.h"

void SacveS::saveItem(Json::Value & in,Item &tItem)
{
	in["Name"] = tItem.name;
	in["AD"] = tItem.AC;
	in["AP"] = tItem.AP;
	in["AC"] = tItem.AC;
	in["PC"] = tItem.PC;
}

void SacveS::savePlayer(Json::Value & in, Player & tPlayer)
{
	in["Name"] = tPlayer.name;
	in["AD"] = tPlayer.AD;
	in["AP"] = tPlayer.AP;
	in["AC"] = tPlayer.AC;
	in["AP"] = tPlayer.AP;
	for (Item nItem : tPlayer.Bag) {
		Json::Value tItem;
		saveItem(tItem, nItem);
		in["Bag"].append(tItem);
	}
	in["HP"] = tPlayer.HP;
	in["HPL"] = tPlayer.HP_Limit;
	in["MP"] = tPlayer.MP;
	in["MPL"] = tPlayer.MP_Limit;
	in["Exp"] = tPlayer.Exp;
	in["Le"] = tPlayer.Le;
	in["Gold"] = tPlayer.Gold;
	for (Item &nItem : tPlayer.Items) {
		Json::Value tItem;
		saveItem(tItem, nItem);
		in["Item"].append(tItem);
	}

}

void SacveS::saveAI(Json::Value & in, AI & tAI)
{
	in["Name"] = tAI.name;
	in["AD"] = tAI.AD;
	in["AP"] = tAI.AP;
	in["AC"] = tAI.AC;
	in["AP"] = tAI.AP;
	for (Item nItem : tAI.Bag) {
		Json::Value tItem;
		saveItem(tItem, nItem);
		in["Bag"].append(tItem);
	}
	in["HP"] = tAI.HP;
	in["HPL"] = tAI.HP_Limit;
	in["MP"] = tAI.MP;
	in["MPL"] = tAI.MP_Limit;

}

void SacveS::Save(Player &in)
{
	std::ofstream ofs;
	ofs.open(CONFIG_SAVE);
	Json::Value root;
	Json::Value p;
	savePlayer(p, in);
	root["Player"] = p;
	ofs << root.toStyledString();
	ofs.close();
}
