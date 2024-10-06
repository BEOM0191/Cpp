#include <iostream>
#include <string>
#include "GamblingGame.h"
using namespace std;

void Player::setName(string playerName) {
	name = playerName;
}
string Player::getName()
{
	return name;
}
int GamblingGame::getRandom() {
	int num;
	num = rand() % 3;
	return num;
}