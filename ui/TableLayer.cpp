#include "TableLayer.h"

#include"runtime/Resource.h"
#include"runtime/Macros.h"
#include"runtime/RapidFuncs.h"
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
				if(GET(Game)GetBattle()->HasBeenShut) {
					return;
				}
				this->setVisible(false);
				GET(Game)GetBattle()->PlayerAttack();
			}
		},
		T("¹¥»÷"), Resource::Assets::Fonts::Kai));

	//Labels
	PlayerLabel = Label::createWithTTF("abc", Resource::Assets::Fonts::Kai, 20);
	PlayerLabel->setPosition(Vec2(140, 300));
	this->addChild(PlayerLabel);

	AILabel = Label::createWithTTF("def", Resource::Assets::Fonts::Kai, 20);
	AILabel->setPosition(Vec2(700, 300));
	this->addChild(AILabel);

	return true;
}

void TableLayer::Update() {
	const Player& p1 = GET(Game)GetBattle()->P1;
	const auto& p2 = GET(Game)GetBattle()->P2;

	PlayerLabel->setString(std::to_string(p1.HP) + "/" + std::to_string(p1.HP_Limit) + "\n" +
						   std::to_string(p1.MP) + "/" + std::to_string(p1.MP_Limit)
	);

	AILabel->setString(std::to_string(p2.HP) + "/" + std::to_string(p2.HP_Limit) + "\n" +
					   std::to_string(p2.MP) + "/" + std::to_string(p2.MP_Limit)
	);
}