#include "Scenemanager.h"

Scenemanager::Scenemanager(){
    Setup();
}

void Scenemanager::Setup(){
	scenechange = Scenename::TITLE;

    title.Setup();
    ////‚±‚±‚ÍÅŒã‚Éíœ‚·‚é‚æ‚¤‚É
   /* gamemanager.Setup();
    result.Setup();
    stageselect.Setup();
*/
}


void Scenemanager::Update(){
    //std::cout << scenechange << std::endl;
	
    switch (scenechange)
	{
	case Scenename::TITLE:
        title.Update();

		break;
	case Scenename::STAGESELECT:
        stageselect.Update();

		break;

	case Scenename::GAMEMAIN:
        gamemanager.Update();
		break;
    case Scenename::RESULT:
        result.Update();

        break;
	}
}

void Scenemanager::Draw(){


	switch (scenechange){
	case Scenename::TITLE:
        title.Draw();

		break;
	case Scenename::STAGESELECT:
        stageselect.Draw();

		break;
	case Scenename::GAMEMAIN:
        gamemanager.Draw();
		break;
    case Scenename::RESULT:
        result.Draw();

        break;
	}
}


void Scenemanager::Shift(){

    switch (scenechange){
    case Scenename::TITLE:
        scenechange = title.Shift();
        if (scenechange != Scenename::TITLE){
            stageselect.Setup();
            gamemanager.Setup();

        }
        break;
    case Scenename::STAGESELECT:

        scenechange = stageselect.Shift();
        if (scenechange != Scenename::STAGESELECT){
            gamemanager.Setup();
        }

        break;

    case Scenename::GAMEMAIN:
        scenechange = gamemanager.Shift();
        if (scenechange != Scenename::GAMEMAIN){
            //result.SetWin();
            result.Setup();
        }
        break;

    case Scenename::RESULT:
        scenechange = result.Shift();
        if (scenechange != Scenename::RESULT){
            title.Setup();
        }
        break;
    }
}

