/// Source : https://leetcode.com/problems/exam-room/description/
/// Author : liuyubobobo
/// Time   : 2018-06-17

#include <iostream>
#include <set>

using namespace std;

/// Using TreeSet
///
/// Time Complexity: seat - O(N)
///                  leave - O(logN)
/// Space Compexity: O(N)
class ExamRoom {

private:
    set<int> seats;
    int N;

public:
    ExamRoom(int N) {
        this->N = N;
        seats.clear();
    }

    int seat() {

        if(seats.empty()){
            seats.insert(0);
            return 0;
        }

        int maxDis = *seats.begin();
        int res = 0;

        set<int>::iterator last_iter = seats.begin();
        set<int>::iterator iter = seats.begin();
        iter ++;
        for(; iter != seats.end() ; last_iter++, iter ++){
            int dis = (*iter - *last_iter) / 2;
            if(dis > maxDis){
                maxDis = dis;
                res = *last_iter + dis;
            }
        }

        if(N - 1 - *last_iter > maxDis){
            maxDis = N - 1 - *last_iter;
            res = N - 1;
        }

        seats.insert(res);
        return res;
    }

    void leave(int p) {
        seats.erase(p);
    }
};


int main() {

    int N = 10;
    ExamRoom examRoom(N);
    cout << examRoom.seat() << endl; // 0
    cout << examRoom.seat() << endl; // 9
    cout << examRoom.seat() << endl; // 4
    cout << examRoom.seat() << endl; // 2
    examRoom.leave(4);
    cout << examRoom.seat() << endl; // 5

    return 0;
}