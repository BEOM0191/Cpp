#include <iostream>
#include <string>
#include "GamblingGame.h"
using namespace std;

int main() {
	Player player[2];
	GamblingGame g[3];
	string name;
	int count = 0;
	int ranNum[3];
	srand((unsigned int)time(0));

	cout << "***** 겜블링 게임을 시작합니다. *****" << endl;
	cout << "첫번째 선수 이름 >> ";
	cin >> name;
	player[0].setName(name);
	cout << "두번째 선수 이름 >> ";
	cin >> name;
	player[1].setName(name);

	for (;;)
	{
		cin.ignore();
		cout << player[count].getName() << ": <Enter>";
		cin.get();
		for (int i = 0; i < 3; i++)
		{
			ranNum[i] = g[i].getRandom();
		}
		if (ranNum[0] == ranNum[1] && ranNum[1] == ranNum[2])
		{
			cout << "		" << ranNum[0] << "		" << ranNum[1] << "		" << ranNum[2] << "		" << player[count].getName() << "님 승리!!" << endl;
			break;
		}
		else
		{
			cout << "		" << ranNum[0] << "		" << ranNum[1] << "		" << ranNum[2] << "		" << "아쉽군요!";
		}
		count = (count + 1) % 2;
	}
}