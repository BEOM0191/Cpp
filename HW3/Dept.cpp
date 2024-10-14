#include <iostream>
#include "Dept.h"
using namespace std;

Dept::Dept(const Dept& dept) {
	size = dept.size;
	scores = new int[dept.size];
	for (int i = 0; i < dept.size; i++) {
		scores[i] = dept.scores[i];
	}
}
Dept::~Dept() {
	delete[] scores;
}
void Dept::read() {
	cout << "10개 점수 입력>> ";
	for (int i = 0; i < size; i++)
	{
		cin >> scores[i];
	}
}
bool Dept::isOver60(int index) {
	if (scores[index] > 60) {
		return true;
	}
	else
		return false;
}