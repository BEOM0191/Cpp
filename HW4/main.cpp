#include <iostream>
#include <string>
using namespace std;
#include "Printer.h"

int main() {
    InkjetPrinter* inkjet = new InkjetPrinter("Officejet V40", "HP", 5, 10);
    LaserPrinter* laser = new LaserPrinter("SCX-6X45", "�Ｚ����", 3, 20);

    cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
    cout << "��ũ�� : "; inkjet->printInkjet();
    cout << "������ : "; laser->printLaser();

    char cont;
    do {
        int printerType, pages;
        cout << endl;
        cout << "������(1: ��ũ��, 2:������)�� �ż� �Է�>>";
        cin >> printerType >> pages;

        if (printerType == 1) {
            inkjet->print(pages);
        }
        else if (printerType == 2) {
            laser->print(pages);
        }

        inkjet->printInkjet();
        laser->printLaser();

        cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');

    delete inkjet;
    delete laser;
    return 0;
}