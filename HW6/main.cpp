#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
#include <vector>

using namespace std;

int main() {

	int num = 0;
	int menu = 0;
	vector<Shape*> v;

	cout << "그래픽 에디터입니다." << endl;

	while (true)
	{
		cout << "삽입: 1, 삭제: 2, 모두보기: 3, 종료: 4 >> ";
		cin >> num;

		if (num == 1)
		{
			cout << "선: 1, 원: 2, 사각형: 3 >> ";
			cin >> menu;
			if (menu == 1)
			{
				Line *l = new Line();
				v.push_back(l);
			}
			else if (menu == 2)
			{
				Circle* c = new Circle();
				v.push_back(c);
			}
			else if (menu == 3)
			{
				Rect* r = new Rect();
				v.push_back(r);
			}
		}
		else if (num == 2)
		{
			int index;
			cout << "삭제하고자 하는 도형의 인덱스 >> ";
			cin >> index;
			v.erase(v.begin() + index);
		}
		else if (num == 3)
		{
			for (int i = 0; i < v.size(); i++)
			{
				cout << i << ": ";
				v.at(i)->paint();
			}
		}
		else if (num == 4) break;
	}
}