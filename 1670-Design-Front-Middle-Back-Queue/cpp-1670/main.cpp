/// Source : https://leetcode.com/problems/design-front-middle-back-queue/
/// Author : liuyubobobo
/// Time   : 2020-11-28

#include <iostream>
#include <deque>
using namespace std;


/// Double Deque
/// Time Complexity: O(1) for every operations
/// Space Complexity: O(n)
class FrontMiddleBackQueue {

private:
    deque<int> first, second;

public:
    FrontMiddleBackQueue(){ }

    void pushFront(int val) {

        first.push_front(val);
        if(first.size() == second.size() + 2){
            second.push_front(first.back());
            first.pop_back();
        }
    }

    void pushMiddle(int val) {

        if(first.size() > second.size()){
            second.push_front(first.back());
            first.pop_back();
        }
        first.push_back(val);
    }

    void pushBack(int val) {

        second.push_back(val);
        if(second.size() > first.size()){
            first.push_back(second.front());
            second.pop_front();
        }
    }

    int popFront() {

        if(first.size() == 0) return -1;

        int ret = first.front();
        first.pop_front();
        if(second.size() > first.size()){
            first.push_back(second.front());
            second.pop_front();
        }
        return ret;
    }

    int popMiddle() {

        if(first.size() == 0) return -1;

        int ret = first.back();
        first.pop_back();
        if(second.size() > first.size()){
            first.push_back(second.front());
            second.pop_front();
        }
        return ret;
    }

    int popBack() {

        if(first.size() == 0) return -1;

        if(second.size() == 0){
            int ret = first.back();
            first.pop_back();
            return ret;
        }

        int ret = second.back();
        second.pop_back();
        if(first.size() == second.size() + 2){
            second.push_front(first.back());
            first.pop_back();
        }
        return ret;
    }
};


int main() {

    FrontMiddleBackQueue q1;
    q1.pushFront(1);  // [1]
    q1.pushBack(2);   // [1, 2]
    q1.pushMiddle(3); // [1, 3, 2]
    q1.pushMiddle(4); // [1, 4, 3, 2]

    cout << q1.popFront() << endl;
    // 1 -> [4, 3, 2]

    cout << q1.popMiddle() << endl;
    // return 3 -> [4, 2]

    cout << q1.popMiddle() << endl;
    // return 4 -> [2]

    cout << q1.popBack() << endl;
    // return 2 -> []

    FrontMiddleBackQueue q2;
    q2.pushFront(1); // [1]
    q2.pushFront(2); // [2, 1]
    q2.pushFront(3); // [3, 2, 1]
    q2.pushFront(4); // [4, 3, 2, 1]

    cout << q2.popBack() << endl; // 1
    cout << q2.popBack() << endl; // 2
    cout << q2.popBack() << endl; // 3
    cout << q2.popBack() << endl; // 4

    return 0;
}
