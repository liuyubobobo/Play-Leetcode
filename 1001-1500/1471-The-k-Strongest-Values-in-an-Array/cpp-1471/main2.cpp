/// Source : https://leetcode.com/problems/the-k-strongest-values-in-an-array/
/// Author : liuyubobobo
/// Time   : 2020-06-06

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Using Priority Queue
/// Time Complexity: O(nlogk)
/// Space Complexity: O(k)
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {

        sort(arr.begin(), arr.end());
        int mid = arr[(arr.size() - 1) / 2];

        auto comp = [mid](int a, int b){
            if(abs(a - mid) != abs(b - mid))
                return abs(a - mid) > abs(b - mid);
            return a > b;
        };

        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for(int e: arr)
            if(pq.size() < k) pq.push(e);
            else if(comp(e, pq.top())) pq.pop(), pq.push(e);

        vector<int> res;
        while(!pq.empty()) res.push_back(pq.top()), pq.pop();
        return res;
    }
};


int main() {

    return 0;
}
