/// Source : https://leetcode.com/problems/moving-average-from-data-stream/description/
/// Author : liuyubobobo
/// Time   : 2018-08-24

#include <iostream>
#include <queue>

using namespace std;


/// Using Queue
/// Time Complexity: O(1)
/// Space Complexity: O(size)
class MovingAverage {

private:
    queue<int> q;
    int sz, sum;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sz = size;
        sum = 0;
    }

    double next(int val) {

        if(q.size() == sz){
            sum -= q.front();
            q.pop();
        }

        sum += val;
        q.push(val);

        return (double)sum / q.size();
    }
};


int main() {

    return 0;
}