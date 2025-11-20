2. 
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Date {
private:
    int year;
    int month;
    int date;

public:
    // 显式默认构造函数，初始化成员为0
    Date() : year(0), month(0), date(0) {}

    void Init(int y, int m, int d) {
        if (y > 0 && m >= 1 && m <= 12 && d >= 1 && d <= 31) {
            year = y;
            month = m;
            date = d;
            cout << "日期初始化成功：";
            display();
        } else {
            cout << "日期输入非法（" << y << "年" << m << "月" << d << "日），已默认初始化为2025年1月1日" << endl;
            year = 2025;
            month = 1;
            date = 1;
        }
    }

    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDate() const { return date; }

    void setYear(int y) {
        if (y > 0) {
            year = y;
            cout << "年份修改成功，当前年份：" << year << endl;
        } else {
            cout << "年份输入非法（必须为正数），保持原年份：" << year << endl;
        }
    }

    void setMonth(int m) {
        if (m >= 1 && m <= 12) {
            month = m;
            cout << "月份修改成功，当前月份：" << month << endl;
        } else {
            cout << "月份输入非法（必须1-12），保持原月份：" << month << endl;
        }
    }

    void setDate(int d) {
        if (d >= 1 && d <= 31) {
            date = d;
            cout << "日期修改成功，当前日期：" << date << endl;
        } else {
            cout << "日期输入非法（必须1-31），保持原日期：" << date << endl;
        }
    }

    void display() const {
        cout << year << "年" 
             << setw(2) << setfill('0') << month << "月" 
             << setw(2) << setfill('0') << date << "日" 
             << endl;
        cout << setfill(' ');
    }

    int calWeekday() const {
        int y = year;
        int m = month;
        int d = date;

        if (m == 1 || m == 2) {
            y--;
            m += 12;
        }

        int weekday = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;

        if (weekday < 0) weekday += 7;

        return weekday;
    }

    void displayWeekday() const {
        int wd = calWeekday();
        string weekdayStr[] = {"星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};
        cout << "当前日期对应的星期：" << weekdayStr[wd] << endl;
    }
};

int main() {
    Date d1;
    d1.Init(2025, 11, 20);
    d1.displayWeekday();

    Date d2;
    d2.Init(2024, 2, 30);
    d2.setMonth(3);
    d2.setDate(15);
    cout << "修改后的日期：";
    d2.display();
    d2.displayWeekday();

    Date d3;
    d3.Init(2025, 1, 1);
    d3.displayWeekday();

    Date d4;
    d4.Init(2024, 2, 29);
    d4.displayWeekday();

    return 0;
}

