//
//  main.cpp
//  cpp_school
//
//  Created by 손민 on 2022/08/31.
//
#include <iostream>
#include <cmath>
#define TAX 15.4;

using namespace std;
double interest;
int yearMonth;
int month = 12;
double interestCalc(int nMoney, double nInterest,double nowMonth) {
//    cout << nMoney * nInterest/100 * nowMonth/month <<endl;
    return (double)nMoney * nInterest/100 * (nowMonth/month);
}

class softBank {
public:
    int money;
    int year;
    int withTax=0.0;
    int withoutTax=0.0;

    void calculator() {
            for(int i=1;i<=yearMonth;i++) {
                int tempInterest = ceil((interestCalc(money, interest, (double)i)));
                withoutTax+= money;
                withTax+=money;
                withoutTax += tempInterest;
                withTax += tempInterest - tempInterest*(15.4/100);
//                cout << money * (interest/100) << endl;
            }
        
    }

};


int main() {
    softBank user1;
    
    cout << "소프트 뱅크 적금 계산기" << endl;
    
    cout << "매달 얼만큼 적금하시겠습니까? : ";
    cin >> user1.money;
    cout << "몇년동안 적금하시겠습니까? : ";
    cin >> user1.year;
    cout << "적금 이자율이 얼마인가요? : ";
    cin >> interest;
    yearMonth = 12*user1.year;
    user1.calculator();
    cout << "세전 총액 : " << (int)user1.withoutTax << endl;
    cout << "세후 총액 : " << (int)user1.withTax;
}
