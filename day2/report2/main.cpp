//
//  main.cpp
//  cpp_school
//
//  Created by 손민 on 2022/08/31.
//
#include <iostream>
#include <cmath>
using namespace std;


double interest;
int month = 12;

class softBank {
public:
    int money;
    int year;
    int withTax=0.0;
    int withoutTax=0.0;
    
    softBank(int witchInterest) : userInterest(witchInterest) {};
    
    int getMoney(int tax) {
        if(userInterest == 0) interest = 3.0;
        if(userInterest == 1) interest = 4.0;
        if(tax==1) {
            for(int i=1;i<=year*12;i++) {
                int tempInterest = (double)money * interest/100 * ((double)i/(double)month);
                withTax+= money;
                withTax += tempInterest*(84.6/100);
            }
            return withTax;
        }else {
            for(int i=1;i<=year*12;i++) {
                int tempInterest = (double)money * interest/100 * ((double)i/(double)month);
                withoutTax+= money;
                withoutTax += tempInterest;
            }
            return withoutTax;
        }
    }
    
private:
    int userInterest;
    int tax;
    int taxData;
};


int main() {
    int witchInterest;
    cout << "소프트 뱅크 적금 계산기" << endl;
    cout << "일반적금(0입력) : 이율 3%" << endl << "특판적금(1입력) : 이율 4%" << endl;
    cout << "어떤 적금에 가입하시겠습니까? : ";
    cin >> witchInterest;
    softBank userWithoutTax(witchInterest);
    cout << "매달 얼만큼 적금하시겠습니까? : ";
    cin >> userWithoutTax.money;
    cout << "몇년동안 적금하시겠습니까? : ";
    cin >> userWithoutTax.year;
    cout << userWithoutTax.getMoney(0) << endl;
    cout << userWithoutTax.getMoney(1) << endl;
    
}
