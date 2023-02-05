/// Source : https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/
/// Author : liuyubobobo
/// Time   : 2023-02-05

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;


/// Using PQ
/// Time Complexity: O(klogn + nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        priority_queue<int> pq;
        for(int e: gifts) pq.push(e);
        for(int i = 0; i < k; i ++){
            int e = pq.top(); pq.pop();
            int x = sqrt(e);
            pq.push(x);
        }

        long long res = 0;
        while(!pq.empty()){
            int e = pq.top(); pq.pop();
            res += e;
        }
        return res;
    }
};


int main() {

    return 0;
}
