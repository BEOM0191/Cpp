#include <iostream>
#include "UI.h"

using namespace std;

int UI::Menu() {
	int choice;
	cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>";
	cin >> choice;
	return choice;
}

int UI::AddShape() {
	int choice;
	cout << "선:1, 원:2, 사각형:3 >>";
	cin >> choice;
	return choice;
}

int UI::DeleteIndex() {
	int choice;
	cout << "삭제하고자 하는 도형의 인덱스 >>";
	cin >> choice;
	return choice;
}
