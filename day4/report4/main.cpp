//
//  main.cpp
//  cpp_school
//
//  Created by 손민 on 2022/10/05.
//

#include <iostream>
#include <ctime>
#define kilometer 1000
#define Minute 60
using namespace std;


class information {
public:
    int startTime = 6;
    int lastTime = 22;
    int betweenBuses;
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);
};

class Student {
public:
    int Speed;
    int distance;
    int timeToBus;
    int leaveHour;
    int leaveMinute;
    
    information inform;
    
    Student() = default;
    
    ~Student() = default;
    
    Student(const information& rhs) {
        inform = rhs;
    }
    
    void calcTimeToStop() {
        timeToBus = (float)distance/kilometer / (float)Speed * Minute;
    }
    
    void calcHaveToGo() {
        int nowPlusMin = inform.t->tm_min+timeToBus;  // 현재 분 + 정류장까지 가는데 걸리는 분
        for(int i=0;;i+=inform.betweenBuses) {
            if(i>=nowPlusMin) {
                leaveHour = inform.t->tm_hour + nowPlusMin/Minute;
                leaveMinute = i%Minute - timeToBus;
                
                if(leaveHour >= inform.lastTime) {      // 지금 출발해서 도착하는 시간(현재시간 + 정류장까지 걸리는 시간) 이 막차시간 뒤일때 처리
                    leaveHour = inform.startTime - 1;
                    leaveMinute = Minute - timeToBus;
                }
                
                if(leaveMinute < 0) {
                    leaveMinute += Minute;
                }
                break;
            }
        }
    }
    
    void printTime() {
        calcTimeToStop();
        calcHaveToGo();
        cout << leaveHour << " : " << leaveMinute << "에 나가면 됩니다!" << endl;
    }
};



int main() {
    
    information express8;
    
    cout << "배차간격이 몇분인가요? : ";
    cin >> express8.betweenBuses;
    Student student1(express8);
    cout << "당신의 걷기 속도는 얼마나 되나요?(km/h) : ";
    cin >> student1.Speed;
    cout << "버스정류장까지의 거리가 몇미터 인가요? : ";
    cin >> student1.distance;
    
    
    student1.printTime();
    
}
