#include <iostream>
#include <conio.h>
#include "LinkedList.h"

using namespace std;

void buses() {
    auto *park = new Park();

    auto bus1 = *new Bus(1, (char *) "Иванов И.И.", 15);
    park->addBus(bus1);
    auto bus2 = *new Bus(2, (char *) "Петров П.П.", 20);
    park->addBus(bus2);
    auto bus3 = *new Bus(3, (char *) "Смирнов С.С.", 33);
    park->addBus(bus3);

    park->print();

    cout << endl;
    park->goOnRoute(bus2);
    park->print();

    cout << endl;
    park->goInPark(bus2);
    park->print();

    getch();
}

int main() {
    buses();
    return 0;
}