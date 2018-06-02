//Function Definitions

#include "Player.h"

Player::Player(){
    newAge = 0;
}

Player::Player(string name, int age){
    newName=name;
    newAge=age;
}

Player::~Player(){
    
}

string Player::getName() const{
    return newName;
}

int Player::getAge() const{
    return newAge;
}

void Player::setName(string name){
    newName=name;
}

void Player::setAge(int age){
    newAge=age;
}