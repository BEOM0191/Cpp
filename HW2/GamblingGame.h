#include <iostream>
#include <string>
using namespace std;

class GamblingGame {
public:
	int getRandom();
};
class Player{
public:
	void setName(string);
	string getName();
	string name;
};