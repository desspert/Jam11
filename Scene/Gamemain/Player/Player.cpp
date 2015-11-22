#include "Player.h"


/////////コンストラクタ
Player::Player(){
    
    Setup();

}

void Player::Setup(){
    cost = 50;
    select_Item = Item::DESK;
    player = Texture("res/Texture/got.png");
    
}

void Player::Update(){
    ani_count++;
}


Vec2f Player::GetMousePosition(){
    return env.mousePosition();
}

bool Player::MouseClick(){
    return env.isPushButton(Mouse::LEFT);
}

Item Player::GetSelectItem(){

    return select_Item;
}

int Player::GetCost(){
    return cost;
}

void Player::SetSelectItem(Item _item){
    select_Item = _item;
}

void Player::SetPos(Vec2f _pos){
    pos = _pos;
}

void Player::Draw(){
    drawTextureBox(pos.x(), pos.y(), HEIGHT / 8, HEIGHT / 8, 0, 0, 512, 512, player);
}
