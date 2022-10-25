//
//  main.cpp
//  cpp_school
//
//  Created by 손민 on 2022/10/12.
//

#include <iostream>
#define month 12
using namespace std;

class Person {
public:
    float salary;
    float realMoney;
    float monthMoney;   // 월급
    float mealMoney;  // 식대비
    float developMoney;  // 개발비
    float incomeTax; // 소득세
};

class Insurance {
public:
    Person person;
    
    Insurance(const Person& rhs) {
        person = rhs;
        person.monthMoney = (person.salary / month - (person.mealMoney + person.developMoney));   //월급(연봉/12 - 비과세)
        person.realMoney = person.salary/month;   //월별 실 수령액
    }
    
    float getNation() {
        return person.monthMoney * nationTax;
    }
    
    float getHealth() {
        return person.monthMoney * healthTax;
    }
    
    float getCare() {
        return getHealth() * careTax;
    }
    
    float getEmploy() {
        return person.monthMoney * employTax;
    }
    
    float getIncome() {
        return person.incomeTax + person.incomeTax * localIncomeTax;
    }
    
    void printRealMoney() {
        person.realMoney -= getNation();
        person.realMoney -= getHealth();
        person.realMoney -= (int)(getCare());
        person.realMoney -= getEmploy();
        person.realMoney -= getIncome();
        cout << "당신의 4대보험을 제외한 월 수령액은?! : " << (int)person.realMoney << endl;
    }
    
private:
    float nationTax = 0.045;
    float healthTax = 0.03495;
    float careTax = 0.1227;
    float employTax = 0.009;
    float localIncomeTax = 0.1;
};

int main() {
    
    Person sonmin;
    while(1) {
        cout << "당신의 연봉은?! : ";
        cin >> sonmin.salary;
        
        if(sonmin.salary == 0) {
            cout << "소득이 없네요ㅠㅠ";
            break;
        }
        
        cout << "당신의 식대비는?! : ";
        cin >> sonmin.mealMoney;
        
        cout << "당신의 (연구)개발비는?! : ";
        cin >> sonmin.developMoney;
        
        cout << "당신의 소득세는!? : ";
        cin >> sonmin.incomeTax;
        
        Insurance insurance(sonmin);
        
        insurance.printRealMoney();
    }
}
