#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class CardUser {
public:
    string userId;
    string userName;
    double balance;
    int transactionCount;

    CardUser(string id = "", string name = "", double bal = 0.0) 
        : userId(id), userName(name), balance(bal), transactionCount(0) {}
};

class CardSystem {
private:
    CardUser* users;
    int userCount;
    int maxUsers;

public:
    CardSystem(int max = 100) {
        maxUsers = max;
        userCount = 0;
        users = new CardUser[maxUsers];
    }

    ~CardSystem() {
        delete[] users;
    }

    bool addUser(string userId, string userName, double initBalance) {
        if (userCount >= maxUsers) {
            cout << "系统用户容量已达上限（" << maxUsers << "人），无法添加新用户！" << endl;
            return false;
        }
        if (initBalance < 0) {
            cout << "初始余额不能为负数，添加失败！" << endl;
            return false;
        }
        users[userCount++] = CardUser(userId, userName, initBalance);
        cout << "用户【" << userName << "（ID：" << userId << "）】添加成功！初始余额：" 
             << fixed << setprecision(2) << initBalance << "元" << endl;
        return true;
    }

    bool recharge(string userId, double amount) {
        if (amount <= 0) {
            cout << "充值金额必须大于0，充值失败！" << endl;
            return false;
        }
        for (int i = 0; i < userCount; i++) {
            if (users[i].userId == userId) {
                users[i].balance += amount;
                users[i].transactionCount++;
                cout << "充值成功！用户【" << users[i].userName << "】当前余额：" 
                     << fixed << setprecision(2) << users[i].balance << "元" << endl;
                return true;
            }
        }
        cout << "未找到用户ID：" << userId << "，充值失败！" << endl;
        return false;
    }

    bool consume(string userId, double amount) {
        if (amount <= 0) {
            cout << "消费金额必须大于0，消费失败！" << endl;
            return false;
        }
        for (int i = 0; i < userCount; i++) {
            if (users[i].userId == userId) {
                if (users[i].balance >= amount) {
                    users[i].balance -= amount;
                    users[i].transactionCount++;
                    cout << "消费成功！用户【" << users[i].userName << "】当前余额：" 
                         << fixed << setprecision(2) << users[i].balance << "元" << endl;
                    return true;
                } else {
                    cout << "余额不足！用户【" << users[i].userName << "】当前余额：" 
                         << fixed << setprecision(2) << users[i].balance << "元，消费失败！" << endl;
                    return false;
                }
            }
        }
        cout << "未找到用户ID：" << userId << "，消费失败！" << endl;
        return false;
    }

    bool queryUser(string userId) const {
        for (int i = 0; i < userCount; i++) {
            if (users[i].userId == userId) {
                cout << "\n===== 用户信息查询结果 =====" << endl;
                cout << "用户ID：" << users[i].userId << endl;
                cout << "用户名：" << users[i].userName << endl;
                cout << "当前余额：" << fixed << setprecision(2) << users[i].balance << "元" << endl;
                cout << "累计交易次数：" << users[i].transactionCount << "次" << endl;
                cout << "===========================\n" << endl;
                return true;
            }
        }
        cout << "未找到用户ID：" << userId << "，查询失败！" << endl;
        return false;
    }

    void printReport() const {
        cout << "\n===== 高校一卡通系统用户报表 =====" << endl;
        cout << setw(12) << left << "用户ID" 
             << setw(12) << left << "用户名" 
             << setw(15) << left << "当前余额（元）" 
             << setw(12) << left << "累计交易次数" << endl;
        cout << "-----------------------------------------" << endl;
        for (int i = 0; i < userCount; i++) {
            cout << setw(12) << left << users[i].userId
                 << setw(12) << left << users[i].userName
                 << setw(15) << left << fixed << setprecision(2) << users[i].balance
                 << setw(12) << left << users[i].transactionCount << endl;
        }
        cout << "=========================================\n" << endl;
    }
};

int main() {
    CardSystem cardSys(50);

    cardSys.addUser("1115001", "张三", 100.0);
    cardSys.addUser("1115002", "李四", 200.5);
    cardSys.addUser("1115003", "王五", 150.0);

    cardSys.recharge("1115001", 50.0);
    cardSys.consume("1115001", 30.5);
    cardSys.consume("1115002", 250.0);
    cardSys.recharge("1115004", 80.0);

    cardSys.queryUser("1115003");
    cardSys.queryUser("1115005");

    cardSys.printReport();

    return 0;
}
