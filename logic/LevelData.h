#pragma once

struct LevelData
{
	unsigned int HP, HP_Limit; //血
	unsigned int MP, MP_Limit; //蓝
	unsigned int AD,
		AP,/* 法术强度 */
		AC,/* 护甲 */
		PC,/* 魔抗 */
		Le,/*等级*/
		Exp_Limit/*最大经验*/;
};