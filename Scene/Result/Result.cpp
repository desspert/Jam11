#include "Result.h"

Result::Result(){

    Setup();

}


void Result::Setup()
{
   /* win = Texture("res/");
    loos = Texture("res/");
*/
    loosse = Media("res/Media/BGM/Result/lost.wav");
    winse = Media("res/Media/BGM/Result/win.wav");
    win_texture = Texture("res/Texture/win.png");
    lose_texture = Texture("res/Texture/lose.png");
    iswin = !env.isPushKey('1');

}

void Result::Update(){

}

void Result::Draw(){
    if (iswin)
    {

        //drawFillBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, Color::red);
        drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, 0, 0, 1024, 1024, win_texture);
        if (!winse.isPlaying()){
            winse.play();
        }
    }
    else
    {
        drawFillBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, Color::green);
        drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, 0, 0, 1024, 1024, lose_texture);

        if (!loosse.isPlaying()){
            loosse.play();
        }
    }
}


Scenename Result::Shift(){
	if (env.isPushButton(Mouse::LEFT)){
        winse.stop();
        loosse.stop();
        env.flushInput();
        return Scenename::TITLE;
	}
    return Scenename::RESULT;
}

void Result::SetWin(bool _win){
    iswin = _win;
}