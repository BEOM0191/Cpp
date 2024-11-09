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
            cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
        }
        else {
            this->availableCount -= pages;
            this->printedCount += pages;
            cout << "����Ʈ�Ͽ����ϴ�." << endl;
        }
    }

    void printStatus() {
        cout << this->model << ", " << this->manufacturer << ", ���� ���� " << this->availableCount << "��";
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
            cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
        }
        else {
            this->availableCount -= pages;
            this->availableInk -= pages;
            this->printedCount += pages;
            cout << "����Ʈ�Ͽ����ϴ�." << endl;
        }
    }

    void printInkjet() {
        this->printStatus();
        cout << ", ���� ��ũ " << this->availableInk << endl;
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
            cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
        }
        else {
            this->availableCount -= pages;
            this->availableToner -= pages;
            this->printedCount += pages;
            cout << "����Ʈ�Ͽ����ϴ�." << endl;
        }
    }

    void printLaser() {
        this->printStatus();
        cout << ", ���� ��� " << this->availableToner << endl;
    }
};