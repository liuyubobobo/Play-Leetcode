/// Source : https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/
/// Author : liuyubobobo
/// Time   : 2022-07-10

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Using PQ
/// Time Complexity: O(sum(amount))
/// Space Complexity: O(1)
class Solution {
public:
    int fillCups(vector<int>& amount) {

        priority_queue<int> pq;
        for(int i = 0; i < 3; i ++)
            if(amount[i]) pq.push(amount[i]);

        int res = 0;
        while(pq.size() >= 2){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            res ++, a --, b --;
            if(a) pq.push(a);
            if(b) pq.push(b);
        }

        if(pq.size()) res += pq.top();
        return res;
    }
};


int main() {

    return 0;
}
