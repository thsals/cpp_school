//
//  main.cpp
//  cpp_school
//
//  Created by 손민 on 2022/09/07.
//

#include <iostream>

using namespace std;

class CUser {
public:
    CUser(int nparam)           //다중생성자
        :data(nparam)
    {
//        this->data = nparam;
        cout << "생성자 호출" << endl;
    }
    ~CUser() {
        cout << "소멸자 호출" << endl;
    }
    int data;
    
    int GetID() const {
        return data;
    }
};



int main() {
    cout << "code start" << endl;

    CUser user(0);
    
    cout << "code end" << endl;
}
