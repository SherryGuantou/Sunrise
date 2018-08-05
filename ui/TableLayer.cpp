#include "TableLayer.h"

#include"ui/Resource.h"
#include"runtime/Macros.h"
#include"logic/Game.h"

USING_NS_CC;

bool TableLayer::init() {
	if(!Layer::init()) {
		return false;
	}
	auto VisionSize = Director::getInstance()->getVisibleSize();

	//Buttons
	this->addChild(
		CreateDefaultButton("Attack", Vec2(340, 400), Size(120, 60),
		[this](Ref*, ui::Widget::TouchEventType type) {
			if(type == ui::Widget::TouchEventType::BEGAN) {
				if (Game::Get().GetBattle()->HasBeenShut) {
					return;
				}
				this->setVisible(false);
				Game::Get().GetBattle()->PlayerAttack();
			}
		},
		T("¹¥»÷"), FONTS_KAI));

	//Labels
	PlayerLabel = Label::createWithTTF("abc", FONTS_KAI, 20);
	PlayerLabel->setPosition(Vec2(140, 300));
	this->addChild(PlayerLabel);

	AILabel = Label::createWithTTF("def", FONTS_KAI, 20);
	AILabel->setPosition(Vec2(700, 300));
	this->addChild(AILabel);

	return true;
}

void TableLayer::Update() {
	const Player& p1 = Game::Get().GetBattle()->P1;
	const auto& p2 = Game::Get().GetBattle()->P2;

	PlayerLabel->setString(std::to_string(p1.HP) + "/" + std::to_string(p1.HP_Limit) + "\n" +
						   std::to_string(p1.MP) + "/" + std::to_string(p1.MP_Limit)
	);

	AILabel->setString(std::to_string(p2.HP) + "/" + std::to_string(p2.HP_Limit) + "\n" +
					   std::to_string(p2.MP) + "/" + std::to_string(p2.MP_Limit)
	);
}