/// Source : https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/description/
/// Author : liuyubobobo
/// Time   : 2023-01-07

#include <iostream>
#include <deque>

using namespace std;


/// Using Deque
/// Time Complexity: O(n)
/// Space Complexity: O(k)
class DataStream {

private:
    int value, k;
    deque<int> q;
    int equal_value = 0;

public:
    DataStream(int value, int k) : value(value), k(k) {
    }

    bool consec(int num) {
        q.push_back(num);
        equal_value += (num == value);

        if(q.size() > k){
            int front = q.front();
            q.pop_front();
            equal_value -= (front == value);
        }

        return equal_value == k;
    }
};


int main() {

    return 0;
}
