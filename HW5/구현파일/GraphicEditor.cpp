#include <iostream>
#include "GraphicEditor.h"

using namespace std;

GraphicEditor::GraphicEditor() {
	pStart = pLast = NULL;
}

void GraphicEditor::RunEditor() {
	UI ui;
	cout << "�׷��� �������Դϴ�." << endl;
	int menu, index, type;
	while (true) {
		menu = ui.Menu();
		switch (menu) {
		case 1:
			type = ui.AddShape();
			insertItem(type);
			break;
		case 2:
			index = ui.DeleteIndex();
			deleteItem(index);
			break;
		case 3:
			show();
			break;
		default:
			return;
		}
	}
}

void GraphicEditor::insertItem(int type) {
	Shape* p = NULL;
	switch (type) {
	case 1:
		p = new Line();
		break;
	case 2:
		p = new Circle();
		break;
	case 3:
		p = new Rectangle();
		break;
	default:
		break;
	}
	if (pStart == NULL) {
		pStart = p;
		pLast = p;
		return;
	}
	pLast->add(p);
	pLast = pLast->getNext();
}

void GraphicEditor::deleteItem(int index) {
	Shape* pre = pStart;
	Shape* tmp = pStart;
	if (pStart == NULL) {
		cout << "������ �����ϴ�!" << endl;
		return;
	}
	int i = 0;
	while (tmp != NULL && i < index) {
		pre = tmp;
		tmp = tmp->getNext();
		i++;
	}
	if (tmp == NULL) {
		cout << "�ε����� �߸��Ǿ����ϴ�!" << endl;
		return;
	}
	if (tmp == pStart) {
		pStart = tmp->getNext();
		delete tmp;
	}
	else {
		pre->add(tmp->getNext());
		delete tmp;
	}
}

void GraphicEditor::show() {
	Shape* tmp = pStart;
	int i = 0;
	while (tmp != NULL) {
		cout << i++ << ": ";
		tmp->paint();
		tmp = tmp->getNext();
	}
}

