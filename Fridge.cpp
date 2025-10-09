#include "Fridge.h"
#include <iostream>
using namespace std;

Fridge::Fridge() {
    doorOpen = false;
    cout << "[冰箱] 已创建，门处于关闭状态" << endl;
}

void Fridge::openDoor() {
    doorOpen = true;
    cout << "[冰箱] 门被打开" << endl;
}

void Fridge::closeDoor() {
    doorOpen = false;
    cout << "[冰箱] 门被关闭" << endl;
}

void Fridge::putElephant() {
    if (doorOpen) {
        cout << "[冰箱] 大象已被放入" << endl;
    }
    else {
        cout << "[冰箱] 错误：门未打开，无法放入大象" << endl;
    }
}
