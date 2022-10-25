//
//  friend.cpp
//  cpp_school
//
//  Created by 손민 on 2022/10/19.
//


// friend  :  private 사용 가능 (선생님께서는 한번도 안쓰셨다함)

#include <iostream>
using namespace std;

class CUser {
public:
    CUser(int n) : id(n) {
        
    }
    
    int GetId() const {
        return id;
    }
    
    void SetId(int n) {
        id = n;
    }
    friend void PrintData(const CUser&);
private:
    int id = 0;
};

void PrintData(const CUser& rData) {
    cout << "PrintData(): " << rData.id << endl;
}


int main() {
    CUser a(5);
    PrintData(a);
}

