#pragma once
#include "lib/framework.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>



#define env App::Get()


enum WindowSize{
	WIDTH = 1280,
	HEIGHT = 1024,
};

class App{
public:
	static AppEnv& Get(){
		static AppEnv singleton_env(WIDTH, HEIGHT, false, true);
		return singleton_env;
	}
};
class Rand_{
public:

    static Random& get()
    {
        static Random rand;

        return rand;
    }


};

enum class Scenename{
	TITLE,
	STAGESELECT,
	GAMEMAIN,
	RESULT,
};

enum class Ismove{
	STOP,
	MOVE,
};

enum class Direction{
	UP,
	DOWN,
	LEFT,
	RIGHT,

	NONE,
};

enum class Item{
	ROBOT,
	COMIC,
    GAME,
    MAX,
};

struct Object{
	Vec2f pos;			//���_�ʒu
	Vec2f size;			//�T�C�Y
	Vec2f offset_pos;	//�؂���ʒu
	Vec2f offset_size;	//�؂���T�C�Y

	Color color;

	Texture tex;

	float angle;
	Vec2f zoom;
	Vec2f center;
};
