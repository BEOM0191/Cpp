#include <iostream>
#include <string>
using namespace std;

class Printer {
protected:
    string model;
    string manufacturer;
    int printedCount;
    int availableCount;

public:
    Printer(string model, string manufacturer, int availableCount) {
        this->model = model;
        this->manufacturer = manufacturer;
        this->printedCount = 0;
        this->availableCount = availableCount;
    }

    virtual ~Printer() {}

    virtual void print(int pages) {
        if (this->availableCount < pages) {
            cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
        }
        else {
            this->availableCount -= pages;
            this->printedCount += pages;
            cout << "프린트하였습니다." << endl;
        }
    }

    void printStatus() {
        cout << this->model << ", " << this->manufacturer << ", 남은 종이 " << this->availableCount << "장";
    }
};

class InkjetPrinter : public Printer {
private:
    int availableInk;

public:
    InkjetPrinter(string model, string manufacturer, int availableCount, int availableInk) : Printer(model, manufacturer, availableCount) {
        this->availableInk = availableInk;
    }

    void print(int pages) {
        if (this->availableCount < pages) {
            cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
        }
        else {
            this->availableCount -= pages;
            this->availableInk -= pages;
            this->printedCount += pages;
            cout << "프린트하였습니다." << endl;
        }
    }

    void printInkjet() {
        this->printStatus();
        cout << ", 남은 잉크 " << this->availableInk << endl;
    }
};

class LaserPrinter : public Printer {
private:
    int availableToner;

public:
    LaserPrinter(string model, string manufacturer, int availableCount, int availableToner) : Printer(model, manufacturer, availableCount) {
        this->availableToner = availableToner;
    }

    void print(int pages) {
        if (this->availableCount < pages) {
            cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
        }
        else {
            this->availableCount -= pages;
            this->availableToner -= pages;
            this->printedCount += pages;
            cout << "프린트하였습니다." << endl;
        }
    }

    void printLaser() {
        this->printStatus();
        cout << ", 남은 토너 " << this->availableToner << endl;
    }
};