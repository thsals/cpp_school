//
//  main.cpp
//  cpp_school
//
//  Created by 손민 on 2022/09/14.
//

#include <iostream>
#include <string>
#define taxx 15.4
#define savingInterest 4.0
#define depositInterest 3.0
#define monthOfYear 12
using namespace std;

class User {
public:
    int id=0;
    string* name = new string();
    int savingMoney;
    int depositMoney;
    int month;
};

class Saving {
public:
    int savingMoney;
    int month;
    int res;
    
    Saving(const User& rhs) {
        savingMoney = rhs.savingMoney;
        month = rhs.month;
    }
    
    void calc() {
        res = (month) * (savingMoney) + ((double)savingMoney * (double)(savingInterest)/100 * (month + 1) * month / 24) * ((double)(100 - taxx)/100);
        
    }
    
    void printResult() {
        cout << "적금 : 매월 " << savingMoney << "원씩 " << month << "개월 입금하면 " << res << "원" << endl;
    }
};

class Deposit {
public:
    int depositMoney;
    int month;
    int res;
    
    Deposit(const User& rhs) {
        depositMoney = rhs.depositMoney;
        month = rhs.month;
    }
    
    void calc() {
        res = (depositMoney) + (depositMoney) * ((double)depositInterest/100) * ((double)month/monthOfYear) * ((double)(100 - taxx)/100);
    }
    
    void printResult() {
        cout << "예금 : " << depositMoney << "원 " << month << "개월 거치하면 " << res << "원" << endl;
    }
};
int main() {
    User user1;
    
    cout << "사용자 ID 입력 : ";
    cin >> user1.id;
    cout << "사용자 이름 입력 : "; 
    cin >> *user1.name;
    cout << "적금할 돈 : ";
    cin >> user1.savingMoney;
    cout << "예금할 돈 : ";
    cin >> user1.depositMoney;
    cout << "몇달동안 입금할 것인가여 : ";
    cin >> user1.month;
    
    Saving saving(user1);
    Deposit deposit(user1);
    
    saving.calc();
    deposit.calc();
    
    
    cout << user1.id << " / " << *user1.name << endl;
    
    saving.printResult();
    deposit.printResult();
}

