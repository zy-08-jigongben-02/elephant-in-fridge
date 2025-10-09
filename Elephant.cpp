#include "Elephant.h"
#include <iostream>
using namespace std;

Elephant::Elephant(string n) {
    name = n;
    cout << "[大象] " << name << " 已创建" << endl;
}

void Elephant::enterFridge(Fridge& fridge) {
    cout << "[大象] " << name << " 准备进入冰箱..." << endl;
    fridge.openDoor();
    fridge.putElephant();
    fridge.closeDoor();
}
