//
//  main.cpp
//  cpp_school
//
//  Created by 손민 on 2022/09/21.
//



#include <iostream>
using namespace std;

class CUser
{
public:
    
    CUser(int nParam)   // explicit CUer(int nParam)
        :id(nParam)
    {
        cout << "constructor" << endl;
    }
    
    operator int(void) {
        return id;
    }
    
    CUser(const CUser& rhs)
        :id(rhs.id)
    {
        cout << "copy" << endl;
    }
    
    int GetID() const
    {
        return id;
    }

    void SetID(int nParam)
    {
        id = nParam;
    }
    
private:
    int id = 0;
    
};

void TestFunc(CUser user) {
    cout << "testfunc : " << user.GetID() << endl;
}

int main()
{
    CUser user(10);
    
    cout << user << endl;
    cout << (int)user << endl;
    cout << static_cast<int>(user) << endl;
    
    TestFunc(10);
    
    return 0;
}
