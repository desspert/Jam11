#include "Ui.h"

bool collision(Vec2f pos, Vec2f floor_pos, Vec2f floor_size){
    return (
        pos.x() >= floor_pos.x() &&
        pos.x() <= floor_pos.x() + floor_size.x() &&
        pos.y() >= floor_pos.y() &&
        pos.y() <= floor_pos.y() + floor_size.y());

}
void drawBox(Vec2f pos,Vec2f size,Color _color){
    drawBox(pos.x(), pos.y(), size.x(), size.y(), 100, _color);
}

Ui::Ui()
{
    Setup();
    
}


void Ui::Setup(){
    for (int i = 0; i < static_cast<int>(Item::MAX); i++)
    {
        itemobject[i].size = Vec2f(100, 100);
        itemobject[i].pos = Vec2f(350 + (i / 5) * 120, 120 - (i % 5) * 120 - (i / 5)*240 + 70);
    }
    
    desk = Texture("res/Texture/desk.png");
    game = Texture("res/Texture/vita.png");
    robot = Texture("res/Texture/roboticon.png");
    comic = Texture("res/Texture/comicicon.png");
    floor = Texture("res/Texture/stage_classroom.png");
    blackboard = Texture("res/Texture/blackboard.png");
    b = Texture("res/Texture/keshigomu.png");

    count = 181;
}
void Ui::Cost(const int& cost){
    font.size(80);

    font.draw("コスト　" , Vec2f(WIDTH / 4, HEIGHT / 2-100),Color::white);
    font.draw(std::to_string(cost), Vec2f(WIDTH / 2 - font.drawSize(std::to_string(cost)).x()-30,
        HEIGHT / 2 - 200), Color::white);

}


void Ui::Draw(){

    drawFillBox(WIDTH / 4, -HEIGHT / 2, WIDTH / 4, HEIGHT, Color::green);
    /*for (int y = 0; y < 8; y++){
        for (int x = 0; x < 8; x++)
        {
            drawBox(-WIDTH / 2 + (WIDTH * 3 / 4 / 8)*x, -HEIGHT / 2 + (HEIGHT / 8)*y,
                WIDTH * 3 / 4 / 8, HEIGHT / 8,100,Color::white);
        }
    }*/
    FloorDraw();
    drawTextureBox(WIDTH / 4, -HEIGHT / 2, WIDTH / 4, HEIGHT,
        0, 90, 128, 320, blackboard);

    for (int i = 0; i < static_cast<int>(Item::MAX); i++)
    {
       /* drawFillBox(itemobject[i].pos.x(), itemobject[i].pos.y(),
            itemobject[i].size.x(), itemobject[i].size.y(), Color::white);*/
        switch (static_cast<Item>(i))
        {
        case Item::AIR:
                /*drawFillBox(itemobject[i].pos.x(), itemobject[i].pos.y(),
                itemobject[i].size.x(), itemobject[i].size.y(), Color::white);*/
                drawTextureBox(itemobject[i].pos.x(), itemobject[i].pos.y(),
                    itemobject[i].size.x(), itemobject[i].size.y(),
                    0, 0, 512, 512, b);
            break;
        case Item::DESK:
            drawTextureBox(itemobject[i].pos.x(), itemobject[i].pos.y(),
                itemobject[i].size.x(), itemobject[i].size.y(), 0, 0, 512, 512, desk);
            break;
        case Item::ROBOT:
            drawTextureBox(itemobject[i].pos.x(), itemobject[i].pos.y(),
                itemobject[i].size.x(), itemobject[i].size.y(), 0, 0, 512, 512, robot);

            break;
        case Item::COMIC:
            drawTextureBox(itemobject[i].pos.x(), itemobject[i].pos.y(),
                itemobject[i].size.x(), itemobject[i].size.y(), 0, 0, 512, 512, comic);

            break;
        case Item::GAME:
            drawTextureBox(itemobject[i].pos.x(), itemobject[i].pos.y(),
                itemobject[i].size.x(), itemobject[i].size.y(), 0, 0, 512, 512, game);

            break;

        case Item::ROBOT_EX:
            drawTextureBox(itemobject[i].pos.x(), itemobject[i].pos.y(),
                itemobject[i].size.x(), itemobject[i].size.y(),
                0, 0, 512, 512, robot,Color::red);

            break;
        case Item::COMIC_EX:
            drawTextureBox(itemobject[i].pos.x(), itemobject[i].pos.y(),
                itemobject[i].size.x(), itemobject[i].size.y(),
                0, 0, 512, 512, comic, Color::red);

            break;
        case Item::GAME_EX:
            drawTextureBox(itemobject[i].pos.x(), itemobject[i].pos.y(),
                itemobject[i].size.x(), itemobject[i].size.y(),
                0, 0, 512, 512, game, Color::red);

            break;


        default:
            /*std::cout <<
                "x  " << itemobject[i].pos.x() <<
                "y  " << itemobject[i].pos.y()<<
                "i  " <<i<< std::endl;*/
            //font.draw(std::to_string(i))
            /*drawFillBox(itemobject[i].pos.x(), itemobject[i].pos.y(),
                itemobject[i].size.x(), itemobject[i].size.y(), Color::white);
            */
            drawTextureBox(itemobject[i].pos.x(), itemobject[i].pos.y(),
                itemobject[i].size.x(), itemobject[i].size.y(),
                0, 0, 512, 512, b);
            break;

        }
    }
    FontStart();
    if (count < 181 && count > 0){
        count--;
    }
    CountDraw();
}

void Ui::SelectDraw(Item _item){
    

    for (int i = 0; i < static_cast<int>(Item::MAX); i++)
    {  
        if (_item == static_cast<Item>(i))
        {
            drawBox(itemobject[i].pos, itemobject[i].size, Color::yellow);
        }        
    }
}

Item Ui::Select(Item _item){


    if (env.isPushButton(Mouse::LEFT)){
        for (int i = 0; i < static_cast<int>(Item::MAX); i++)
        {
            if (collision(env.mousePosition(), itemobject[i].pos, itemobject[i].size)){
                return static_cast<Item>(i);
            }
        }
    }
    return _item;
}

void Ui::FloorDraw(){
    drawTextureBox(WIDTH / 4, -HEIGHT / 2,
        WIDTH * 3 / 4, HEIGHT,
        0, 0,
        1024, 1024, floor);
}
void Ui::FontStart(){
    font.size(60);
    Color a = Color::yellow;
    if (collision(env.mousePosition(), Vec2f(WIDTH / 2 - font.drawSize("スタート").x() - 50,
        -HEIGHT / 2 + 100), font.drawSize("スタート"))){
        a = Color::red;
        if (env.isPushButton(Mouse::LEFT)){
            if (count == 181)
            count--;
        }
    }
    
    font.draw("スタート", Vec2f(WIDTH / 2 - font.drawSize("スタート").x() - 50,
        -HEIGHT / 2+100)
        ,a);
}


bool Ui::IsStart(){
    return count <= 0;
}

void Ui::CountDraw(){
    
    if (count > 0 && count < 181){
    font.size(100);
        font.draw(std::to_string(count / 60+1),Vec2f(0,0), Color::yellow);
    }
    if (IsStart()){
        count--;
        if(count > -60)
        
            font.draw("スタート", - font.drawSize("スタート")/2, Color::yellow);
    }
}

void Ui::CountReset(){
    count = 181;
}
