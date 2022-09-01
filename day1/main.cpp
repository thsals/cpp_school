#include <iostream>
using namespace std;
// struct

//typedef struct User{
//    int nAge;
//    char szName[32];
//    void(*Print)(struct User*);
//}User;

//void PrintData(User* pUser) {
//    cout << pUser->nAge << " " << pUser->szName << endl;
//
//}

//class

class User {
public:
    int nAge;
    char szName[32];
    void Print() {
        int* ref = &nAge;
        *ref=30;
        cout << *ref << endl;
        cout << nAge << endl;
        
    }
    
};

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

//int TestFunc(int n) {
//    int nResult = n*3;
//    return nResult;
//}

template <typename T>
T testFunc(T a) {
    cout << a << endl;
    return a;
}


template <typename T>
T add(T a, T b) {
    return a+b;
}

inline void add() {
    int a=5;
    cout << a;
}

namespace Test {

int ndata = 100;
void Func() {}

}


class CUser {
public:
    CUser()
//        : nData(10), nData2(20)   // 생성할때 정의
    
    {
        cout << "생성자 호출" << endl;
    }
    
    ~CUser() {          // 소멸자 ~
        cout << "소멸자 호출" <<endl;
    }
    
    int nData=10;
    
    void PrintData() {
        cout << nData << endl;
    }
};


using namespace Test;
int main() {
    
    testFunc(3);
    testFunc("sonmin");
    testFunc(3.5);
    
    Func();
    
    
    add();
    //r value
//    int input =0;
//    cout << "숫자 입력 : ";
//    cin >> input;
//    int&& rdata = input+5;
//    cout << rdata << endl;
//
//    int&& result = TestFunc(10);
//    result += 10;
//    cout << result << endl;

    
    // 3+4+5     (3+4) 가 임시값
    
    
    //struct
//    User user = {18,"sonmin", PrintData};
//    user.Print(&user);
    
    //class
//    User user = {18,"sonmin"};
//    user.Print();
    
    
//    int x=10,y=20;
//    swap(x, y);
//    cout << x << " " << y << endl;
    
    
}
