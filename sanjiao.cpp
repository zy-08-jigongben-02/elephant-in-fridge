#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

class Triangle {
private:
    double a, b, c;

public:
    Triangle() : a(0), b(0), c(0) {}

    void Init(double sideA, double sideB, double sideC) {
        if (sideA > 0 && sideB > 0 && sideC > 0) {
            a = sideA;
            b = sideB;
            c = sideC;
            cout << "三角形初始化成功，边长：a=" << a << ", b=" << b << ", c=" << c << endl;
        } else {
            cout << "边长输入非法（必须为正数），已默认初始化为直角三角形（a=3, b=4, c=5）" << endl;
            a = 3;
            b = 4;
            c = 5;
        }
    }

    double getSideA() const { return a; }
    double getSideB() const { return b; }
    double getSideC() const { return c; }

    void setSideA(double sideA) {
        if (sideA > 0) {
            a = sideA;
            cout << "边长a修改成功，当前a=" << a << endl;
        } else {
            cout << "边长a输入非法（必须为正数），保持原a=" << a << endl;
        }
    }

    void setSideB(double sideB) {
        if (sideB > 0) {
            b = sideB;
            cout << "边长b修改成功，当前b=" << b << endl;
        } else {
            cout << "边长b输入非法（必须为正数），保持原b=" << b << endl;
        }
    }

    void setSideC(double sideC) {
        if (sideC > 0) {
            c = sideC;
            cout << "边长c修改成功，当前c=" << c << endl;
        } else {
            cout << "边长c输入非法（必须为正数），保持原c=" << c << endl;
        }
    }

    bool isTriangle() const {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }

    double perimeter() const {
        if (isTriangle()) {
            return a + b + c;
        } else {
            cout << "当前边长无法构成三角形，周长计算无效！" << endl;
            return 0;
        }
    }

    double area() const {
        if (!isTriangle()) {
            cout << "当前边长无法构成三角形，面积计算无效！" << endl;
            return 0;
        }
        double p = perimeter() / 2;
        double area = sqrt(p * (p - a) * (p - b) * (p - c));
        return area;
    }

    int typeTriangle() const {
        if (!isTriangle()) {
            return 0;
        }

        double x = a, y = b, z = c;
        if (x > z) swap(x, z);
        if (y > z) swap(y, z);

        const double EPS = 1e-6;
        double x2y2 = x * x + y * y;
        double z2 = z * z;

        if (fabs(x2y2 - z2) < EPS) {
            return 1;
        } else if (x2y2 > z2) {
            return 2;
        } else {
            return 3;
        }
    }

    void displayInfo() const {
        cout << "\n===== 三角形信息汇总 =====" << endl;
        cout << "边长：a=" << fixed << setprecision(2) << a 
             << ", b=" << fixed << setprecision(2) << b 
             << ", c=" << fixed << setprecision(2) << c << endl;
        
        cout << "能否构成三角形：" << (isTriangle() ? "是" : "否") << endl;
        
        if (isTriangle()) {
            cout << "周长：" << fixed << setprecision(2) << perimeter() << endl;
            cout << "面积：" << fixed << setprecision(2) << area() << endl;
            
            int type = typeTriangle();
            cout << "三角形类型：";
            switch (type) {
                case 1: cout << "直角三角形" << endl; break;
                case 2: cout << "锐角三角形" << endl; break;
                case 3: cout << "钝角三角形" << endl; break;
            }
        }
        cout << "=========================\n" << endl;
    }
};

int main() {
    Triangle t1;
    t1.Init(3, 4, 5);
    t1.displayInfo();

    Triangle t2;
    t2.Init(2, 3, 4);
    t2.displayInfo();

    Triangle t3;
    t3.Init(5, 5, 5);
    t3.displayInfo();

    Triangle t4;
    t4.Init(1, 2, 4);
    t4.displayInfo();

    Triangle t5;
    t5.Init(6, 8, 10);
    t5.setSideC(11);
    t5.displayInfo();

    return 0;
}
