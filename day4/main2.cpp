//
//  main2.cpp
//  cpp_school
//
//  Created by 손민 on 2022/10/05.
//


// 이름 없는 객체
#include <iostream>
using namespace std;

class CUser {
private:
    int id = 0;
    
public:
    CUser() {
        cout << "CUer()" << endl;
    }
    ~CUser() {
        cout << "~CUser()" << endl;
    }
    
    CUser(const CUser& rhs):id(rhs.id)
    {
        cout << "CUer& rhs" << endl;
    }
    
    CUser(const CUser&& rhs):id(rhs.id)
    {
        cout << "CUer&& rhs" << endl;
    }
    
    CUser& operator=(const CUser&) = default;
    
    int GetData() const
    {
        return id;
    }

    void SetData(int nParam)
    {
        id = nParam;
    }
};

CUser Func(int nParam) {
    CUser a;
    return a;
}

int main() {
    CUser user;
    
//    int&& data = 3+5;
    
    CUser user2 = Func(10);
    
}
