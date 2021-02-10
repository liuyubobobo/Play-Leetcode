/// Source : https://leetcode.com/problems/kth-largest-element-in-a-stream/
/// Author : liuyubobobo
/// Time   : 2021-02-10

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Priority Queue
/// Time Complexity: init: O(nlogk)
///                  add: O(logk)
/// Space Complexity: O(k)
class KthLargest {

private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums) : k(k) {

        for(int e: nums)
            if(pq.size() < k)
                pq.push(e);
            else if(e > pq.top()){
                pq.pop();
                pq.push(e);
            }
    }

    int add(int val) {

        if(pq.size() < k)
            pq.push(val);
        else if(val > pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};


int main() {

    return 0;
}
