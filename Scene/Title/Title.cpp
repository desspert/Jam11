#include "Title.h"

Title::Title(){
    Setup();


}


void Title::Setup(){
    count = 0;
    titre = Texture("res/Texture/title.png");


}

void Title::Update(){
    
    if (env.isPushButton(Mouse::LEFT) &&
        count == 0)
        count++;
    if (count > 0)
        count++;

}

void Title::Draw(){
    //drawFillBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, Color::blue);
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, 0, 0, 512, 512, titre);
    //drawBox(100, 100, 100, 100, 100, Color::blue);
    font.size(70);
    font.draw("オタガミのスクールウォーズ", Vec2f(0, 80) -
        font.drawSize("オタガミのスクールウォーズ")/2,
        Color::white);
    font.draw("Please Push Boton", Vec2f(0, -100)-
        font.drawSize("Please Push Boton") / 2,
        Color::white);
    drawFillBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, Color(0, 0, 0, (float)count / 30.f));
}


Scenename Title::Shift(){

    if (count == 30){
        Setup();
        return Scenename::GAMEMAIN;
    
    }
    return Scenename::TITLE;
}