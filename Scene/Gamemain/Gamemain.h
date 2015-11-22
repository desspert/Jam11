#pragma once
#include "../../lib/framework.hpp"
#include "../../Share.h"
#include "../../Classbase.h"
#include "Astar/Astar.h"
#include "Ui/Ui.h"
#include "Map/Map.h"
#include "Player/Player.h"
#include "Enemylist/Enemylist.h"


class Gamemain : public Classbase{
private:
    Ui ui;
    Player player;
	Map map;
	Enemylist enemylist;
	Vec2f _pos;
	int count;
	int enemy_number;
	int a;
    Media BGM;
    
public:
	Gamemain();

	void Setup();
	void Update();
	void Draw();
	Scenename Shift();

    
};