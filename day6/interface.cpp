//
//  main2.cpp
//  cpp_school
//
//  Created by 손민 on 2022/10/19.
//


// 인터페이스

#include <iostream>

using namespace std;

class CDeviceInterface {
public:
    CDeviceInterface(): deviceID(0) {
        cout << "CDeviceInterface()" << endl;
    }

    virtual int GetDeviceId () = 0;

protected:
    int deviceID;
};


class CDisplay : public CDeviceInterface {
public:
    CDisplay() {
        cout << "CDisplay()" << endl;
        deviceID = 10;
    }

    virtual int GetDeviceId() {
        cout << "GetDisplay GetId()" << endl;
        return deviceID;
    }
};


class CAudio : public CDeviceInterface {
public:
    CAudio() {
        cout << "CAudio()" << endl;
        deviceID = 20;
    }

    virtual int GetDeviceId() {
        cout << "GetAudio GetId()" << endl;
        return deviceID;
    }
};


void printDeviceID(CDeviceInterface* cdi) {
    cout << "Device ID : " << cdi->GetDeviceId() << endl;
}

int main() {
    CDisplay sp;
    printDeviceID(&sp);

    CAudio sp1;
    printDeviceID(&sp1);
}
