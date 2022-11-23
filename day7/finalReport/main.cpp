//
//  main.cpp
//  cpp_school
//
//  Created by 손민 on 2022/10/26.
//

#include <iostream>
#include "incomeTable.h"
#define month 12  // 달
#define startYear 2023  // 올해는?
#define interestTax 15.4 // 적금,예금 세금
using namespace std;


class Account {  // 나의 계좌 클래스
public:
    int accountIndex = 0;  // 통장의 인덱스 번지
    float realMoney;  // 월 실수령액
    struct datas {   // 통장 칸별 (년도 : 금액)
        int year;
        long long money;
    };

    datas *moneys = new datas();  // 구조체 동적으로 할당해주기
};

class Person {  // 사람(손민) 클래스
public:
    float salary;  // 연봉
    float spend = 1300000;  // 월 고정 지출액
    float monthMoney;  // 월급 ㅎㅎ
    float taxFree;  // 나의 비과세
    Account act;  // 내 통장
};

class Bank {  // 은행 클래스
public:
    float savingInterest;
    float depositInterest;
    
    int getSaving(long long savingMoney) {
        int res = (month) * (savingMoney) + ((double)savingMoney * (double)(savingInterest)/100 * (month + 1) * month / (month+month)) * ((double)(100 - interestTax)/100);
        return res;
    }
    
    int getDeposit(long long depositMoney) {
        int res = (depositMoney) + (depositMoney) * ((double)depositInterest/100) * ((double)(100 - interestTax)/100);
        return res;
    }
    
    void holdMoney(Person& rhs) {
        rhs.act.moneys[rhs.act.accountIndex].year = startYear + rhs.act.accountIndex;  // 올해 몇년인지 구하기
        long long depositMoney = getDeposit(rhs.act.moneys[rhs.act.accountIndex-1].money);  // 예금 결과 구하기
        long long savingMoney = getSaving((rhs.act.realMoney - rhs.spend));  // 적금 결과 9하기
        if(rhs.act.accountIndex-1 < 0) {
            rhs.act.moneys[rhs.act.accountIndex].money = savingMoney;
        }else {
            rhs.act.moneys[rhs.act.accountIndex].money = savingMoney + depositMoney;
        }
//        rhs.act.moneys[rhs.act.accountIndex].money += getSaving((rhs.act.realMoney - rhs.spend));  // (월급 - 사용액) 12달 적금 들었을 때 이자 구해주기
//
//        long long lastMoney = rhs.act.moneys[rhs.act.accountIndex-1].money;  // 작년 보유 자산액 구하기(내 통장 이전 인덱스의 돈)
//        if(lastMoney != 0) { // 작년에 보유자산 0원 아니면(예금할 돈 없으면 예금 안함)
//            rhs.act.moneys[rhs.act.accountIndex].money += getDeposit(lastMoney);
//        }
        
    }
    
    void printYearEnd(Person& rhs) {
        cout << "예금 만기 수령액: " << getDeposit(rhs.act.moneys[rhs.act.accountIndex-1].money) << "원" << endl;
        cout << "적금 만기 수령액: " << getSaving((rhs.act.realMoney - rhs.spend)) << "원" << endl;
        cout << startYear+rhs.act.accountIndex << "년 총 자산은 " << rhs.act.moneys[rhs.act.accountIndex].money << "원" << endl << endl;
        rhs.act.accountIndex++;
    }
};


class Revenue {  // 국세청 클래스
public:
    Revenue(Person& rhs) {  // 국세청에서 사람(손민) 정보 받아오기
        rhs.act.realMoney = rhs.monthMoney; // 손민의 실 수령액 계산 1단계! : 월급 더해주기
        calcRealMoney(rhs);  // 실수령액 계산하기(세금 빼주기)!
        printTax(rhs);
    }
    
    float getNation(int monthMoney) { // 국민 연금 계산
        return monthMoney * nationTax;
    }
    
    float getHealth(int monthMoney) { // 건강보험 계산
        return monthMoney * healthTax;
    }
    
    float getCare(int monthMoney) { // 장기요양 계산
        return getHealth(monthMoney) * careTax;
    }
    
    float getEmploy(int monthMoney) { // 고용보험 계산
        return monthMoney * employTax;
    }
    
    float getIncome(int monthMoney) {  // 소득세 계산하기
        int tableSize = sizeof(table);
        
        for (int i = 0; i < tableSize; i++) {
            if ((table[i].start*1000 <= monthMoney) && (table[i].end*1000 > monthMoney)) {
                return table[i].tax;
            }
        }
        return 0;
    }
    
    float getLocalIncome(int monthMoney) {  // 지방소득세 계산하기
        return getIncome(monthMoney) * localIncomeTax;
    }
    
    void calcRealMoney(Person& rhs) {  // 받아온 사람의 통장에서 세금 때주기
        rhs.act.realMoney -= getNation(rhs.monthMoney);
        rhs.act.realMoney -= getHealth(rhs.monthMoney);
        rhs.act.realMoney -= (int)(getCare(rhs.monthMoney));
        rhs.act.realMoney -= getEmploy(rhs.monthMoney);
        rhs.act.realMoney -= getIncome(rhs.monthMoney);
        rhs.act.realMoney -= getLocalIncome(rhs.monthMoney);
        rhs.act.realMoney += rhs.taxFree;
    }
    
    void printTax(Person& rhs) {
        cout << "--------------------------------------------------" << endl << endl;
        cout << "공제액합계" << endl;
        cout << "국민연금 = " << (int)(getNation(rhs.monthMoney)) << "원" << endl;
        cout << "건강보험 = " << (int)(getHealth(rhs.monthMoney)) << "원" << endl;
        cout << "장기요양 = " << (int)(getCare(rhs.monthMoney)) << "원" << endl;
        cout << "고용보험 = " << (int)(getEmploy(rhs.monthMoney)) << "원" << endl;
        cout << "소득세 = " << (int)(getIncome(rhs.monthMoney)) << "원" << endl;
        cout << "지방소득세 = " << (int)(getLocalIncome(rhs.monthMoney)) << "원" << endl;
        cout << "월 실수령액 = " << (int)(rhs.act.realMoney) << "원" << endl;
    }
    
private:
    float nationTax = 0.045;
    float healthTax = 0.03495;
    float careTax = 0.1227;
    float employTax = 0.009;
    float localIncomeTax = 0.1;
};


class Office {  // 회사 클래스
public:
    float increase;  // 인상률
    
    void getSalary(Person& rhs) {
        if(rhs.act.accountIndex != 0) {
            rhs.salary = rhs.salary + rhs.salary * increase/100; // 연봉 인상해주기
        }
        
        rhs.monthMoney = (rhs.salary/month - rhs.taxFree);  // 월급 측정하기
        
        Revenue revenue(rhs);  // 월급 입금을 위해 세금 때기 => 국세청으로 ㄲ
    }
};


int main() {
    Person sonmin;
    Office semes;
    Bank nonghyup;
    
    cout << "연봉을 입력하세요: ";
    cin >> sonmin.salary;
    cout << "연봉 인상률: ";
    cin >> semes.increase;
    cout << "비과세액을 입력하세요: ";
    cin >> sonmin.taxFree;
    cout << "적금 이자율: ";
    cin >> nonghyup.savingInterest;
    cout << "예금 이자율: ";
    cin >> nonghyup.depositInterest;
    
    for(int i=0;i<10;i++) {
        semes.getSalary(sonmin); // 1년동안 회사에 손민 보내서 일 시키기...
        nonghyup.holdMoney(sonmin); // 매달 월급 실수령하고 농협가서 돈 맡기는 손민...

        nonghyup.printYearEnd(sonmin); // 은행 연말 정산하기 :)
    }
    
}

