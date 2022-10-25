//
//  main.cpp
//  cpp_school
//
//  Created by 손민 on 2022/10/12.
//

#include <iostream>
using namespace std;

class CPerson {
public:
    CPerson() : age(0) {
        cout << "CPerson()" << endl;
    }
    
    int GetAge() {
        return age;
    }
    
    void SetAge(int param) {
        age = param;
    }
    
protected:
    void Print() {
        cout << "CPerson::Print()"<< endl;
    }
    
private:
    int age;
};

class CStudent: public CPerson {
public:
    CStudent() {
        cout << "CStudent()" << endl;
    }
    
    void SetAge(int param) {
        cout << "CPerson::SetAge(0)" << endl;
        if(param < 0) {
            CPerson::SetAge(0);
        }
    }
    
    void testFunc() {
        Print();
        SetAge(45);
        cout << CPerson::GetAge() << endl;
    }
};

int main() {
    CStudent student;
    
    CPerson& person = student;
    
    person.SetAge(15);
    cout << person.GetAge() << endl;
    student.SetAge(10);
    cout << student.GetAge() << endl;
    
    student.testFunc();
}
