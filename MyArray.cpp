#include "MyArray.h"
#include <iostream>
#include <cstring>

MyArray::MyArray() {
    p = nullptr;
    N = 0;
}

MyArray::MyArray(int n) {
    if (n <= 0) {
        std::cout << "数组长度必须大于0，创建空数组" << std::endl;
        p = nullptr;
        N = 0;
        return;
    }

    N = n;
    p = new int[N];

    for (int i = 0; i < N; i++) {
        p[i] = i;
    }
}

MyArray::MyArray(const MyArray& arr) {
    N = arr.N;

    if (N > 0) {
        p = new int[N];
        for (int i = 0; i < N; i++) {
            p[i] = arr.p[i];
        }
    }
    else {
        p = nullptr;
    }
}

MyArray::~MyArray() {
    if (p != nullptr) {
        delete[] p;
        p = nullptr;
        N = 0;
    }
}

MyArray MyArray::merge(const MyArray& arr) const {
    MyArray result(N + arr.N);

    for (int i = 0; i < N; i++) {
        result.p[i] = p[i];
    }

    for (int i = 0; i < arr.N; i++) {
        result.p[N + i] = arr.p[i];
    }

    return result;
}

MyArray MyArray::add(const MyArray& arr) const {
    int len = (N < arr.N) ? N : arr.N;
    MyArray result(len);

    for (int i = 0; i < len; i++) {
        result.p[i] = p[i] + arr.p[i];
    }

    return result;
}

MyArray MyArray::subtract(const MyArray& arr) const {
    int len = (N < arr.N) ? N : arr.N;
    MyArray result(len);

    for (int i = 0; i < len; i++) {
        result.p[i] = p[i] - arr.p[i];
    }

    return result;
}

MyArray MyArray::multiply(const MyArray& arr) const {
    int len = (N < arr.N) ? N : arr.N;
    MyArray result(len);

    for (int i = 0; i < len; i++) {
        result.p[i] = p[i] * arr.p[i];
    }

    return result;
}

MyArray MyArray::divide(const MyArray& arr) const {
    int len = (N < arr.N) ? N : arr.N;
    MyArray result(len);

    for (int i = 0; i < len; i++) {
        if (arr.p[i] != 0) {
            result.p[i] = p[i] / arr.p[i];
        }
        else {
            std::cout << "警告：除数为0，结果可能不正确！" << std::endl;
            result.p[i] = 0;
        }
    }

    return result;
}

void MyArray::print() const {
    if (p == nullptr || N == 0) {
        std::cout << "数组为空" << std::endl;
        return;
    }

    std::cout << "数组元素：";
    for (int i = 0; i < N; i++) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
}

int MyArray::getSize() const {
    return N;
}

int MyArray::getElement(int index) const {
    if (index >= 0 && index < N) {
        return p[index];
    }
    else {
        std::cout << "索引越界！" << std::endl;
        return 0;
    }
}