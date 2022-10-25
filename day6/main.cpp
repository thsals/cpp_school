//
//  main.cpp
//  cpp_school
//
//  Created by 손민 on 2022/10/19.
//

//  메모리 누수 해결

#include <iostream>
using namespace std;

class CPerson {
public:
    CPerson() {
        name = new char[32];
    }

    virtual ~CPerson() {   // virtual 붙이면 자식의 ~CStudent 실행해준다
        cout << "~CPerson()" << endl;
        delete [] name;
    }
protected:
    char* name;
};

class CStudent : public CPerson {
public:
    CStudent() {
        id = new int;
    }
    ~CStudent() {
        cout << "~CStudent()" << endl;
        delete id;
    }

protected:
    int* id;
};

int main() {
    CPerson* pPerson = new CStudent;
    delete pPerson;

}


