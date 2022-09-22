//
//  main.cpp
//  cpp_school
//
//  Created by 손민 on 2022/09/14.
//

//복사생성자
//복사생성자가 호출되는 시점은?

#include <iostream>
using namespace std;

class CUser
{
public:
    CUser(int nParam)
    {
        id = new int();
        *id = nParam;
        cout << "constructor" << endl;
    }
    
    CUser(const CUser& rhs)
        :id(rhs.id)
    {
        *id = *rhs.id;
        
    }
    
    CUser& operator=(const CUser& rhs)
    {
        *id = *rhs.id;
        return *this;
    }
    
    int GetID() const
    {
        return *id;
    }

    void SetID(int nParam)
    {
        *id = nParam;
    }

    ~CUser() {
        delete id;
    }
private:
    int *id = 0;
    
};

int main()
{
//    CUser user;
//    user.SetID(10);
//
//    cout << user.GetID() << endl;

    //아래 값은 무엇이 나올까?
    //CUser user2(user);
    //cout << user2.GetID() << endl;

    CUser user1(10);
    CUser user2(20);
    
    cout << user1.GetID() <<endl;
    cout << user2.GetID() << endl;
    user1.operator=(user2); // user1 = user2;
    cout << user1.GetID() << endl;
    return 0;
}
