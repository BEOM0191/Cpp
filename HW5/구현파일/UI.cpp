#include <iostream>
#include "UI.h"

using namespace std;

int UI::Menu() {
	int choice;
	cout << "����:1, ����:2, ��κ���:3, ����:4 >>";
	cin >> choice;
	return choice;
}

int UI::AddShape() {
	int choice;
	cout << "��:1, ��:2, �簢��:3 >>";
	cin >> choice;
	return choice;
}

int UI::DeleteIndex() {
	int choice;
	cout << "�����ϰ��� �ϴ� ������ �ε��� >>";
	cin >> choice;
	return choice;
}
