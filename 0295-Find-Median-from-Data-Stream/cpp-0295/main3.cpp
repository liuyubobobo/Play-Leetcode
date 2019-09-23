/// https://leetcode.com/problems/find-median-from-data-stream/
/// Author : liuyubobobo
/// Time   : 2019-09-23

#include <iostream>
#include <map>
#include <queue>

using namespace std;


/// Two Priority Queue
/// Time Complexity: add: O(logn)
///                  findMedian: O(logn)
class MedianFinder {

private:
    priority_queue<int> left; // maxheap
    priority_queue<int, vector<int>, greater<int>> right; // minheap

public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {

        if(!left.size() && !right.size()){
            left.push(num);
            return;
        }

        if((left.size() + right.size()) % 2){ // odd
            if(num >= left.top()) right.push(num);
            else{
                right.push(left.top());
                left.pop();
                left.push(num);
            }
        }
        else{ // even
            if(num <= right.top()) left.push(num);
            else{
                left.push(right.top());
                right.pop();
                right.push(num);
            }
        }
    }

    double findMedian() {

        if((left.size() + right.size()) % 2) return left.top();
        return (left.top() + right.top()) / 2.0;
    }
};


int main() {

    MedianFinder mf;
    mf.addNum(40);
    cout << "after adding 40 : " << mf.findMedian() << endl; // 40

    mf.addNum(12);
    cout << "after adding 12 : " << mf.findMedian() << endl; // 26

    mf.addNum(16);
    cout << "after adding 16 : " << mf.findMedian() << endl; // 16

    return 0;
}