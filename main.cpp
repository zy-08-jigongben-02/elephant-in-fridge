#include "MyArray.h"
#include <iostream>
#include<windows.h>
int main() {
    MyArray arr1;
    std::cout << "arr1 的长度：" << arr1.getSize() << std::endl;
    arr1.print();

    MyArray arr2(5);
    std::cout << "\narr2 的长度：" << arr2.getSize() << std::endl;
    arr2.print();

    MyArray arr3(arr2);
    std::cout << "\narr3 的长度：" << arr3.getSize() << std::endl;
    arr3.print();

    MyArray arr4(3);
    std::cout << "\n修改arr4的元素..." << std::endl;

    MyArray arr5(3);
    std::cout << "arr5 的长度：" << arr5.getSize() << std::endl;
    arr5.print();

    MyArray arr6 = arr2.merge(arr5);
    std::cout << "\n合并arr2和arr5后的arr6：" << std::endl;
    arr6.print();

    MyArray arr7 = arr2.add(arr5);
    std::cout << "\narr2 + arr5 的结果：" << std::endl;
    arr7.print();

    MyArray arr8 = arr2.subtract(arr5);
    std::cout << "\narr2 - arr5 的结果：" << std::endl;
    arr8.print();

    MyArray arr9 = arr2.multiply(arr5);
    std::cout << "\narr2 * arr5 的结果：" << std::endl;
    arr9.print();

    MyArray arr10 = arr2.divide(arr5);
    std::cout << "\narr2 / arr5 的结果：" << std::endl;
    arr10.print();

    std::cout << "\n测试边界情况..." << std::endl;
    MyArray arr11(0);
    MyArray arr12(-5);
    Sleep(5000);
    return 0;
}