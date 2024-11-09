#include <iostream>
#include <string>
using namespace std;
#include "Printer.h"

int main() {
    InkjetPrinter* inkjet = new InkjetPrinter("Officejet V40", "HP", 5, 10);
    LaserPrinter* laser = new LaserPrinter("SCX-6X45", "삼성전자", 3, 20);

    cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
    cout << "잉크젯 : "; inkjet->printInkjet();
    cout << "레이저 : "; laser->printLaser();

    char cont;
    do {
        int printerType, pages;
        cout << endl;
        cout << "프린터(1: 잉크젯, 2:레이저)와 매수 입력>>";
        cin >> printerType >> pages;

        if (printerType == 1) {
            inkjet->print(pages);
        }
        else if (printerType == 2) {
            laser->print(pages);
        }

        inkjet->printInkjet();
        laser->printLaser();

        cout << "계속 프린트 하시겠습니까(y/n)>>";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');

    delete inkjet;
    delete laser;
    return 0;
}