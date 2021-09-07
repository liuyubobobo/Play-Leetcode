/// Source : https://leetcode.com/problems/ipo/
/// Author : liuyubobobo
/// Time   : 2021-09-07

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Priority Queue
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = profits.size();
        priority_queue<pair<int, int>> pq1; // profit, capital
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2; // capital, profit

        for(int i = 0; i < n; i ++)
            pq2.push({capital[i], profits[i]});

        int cur = w;
        while(k){
            while(!pq2.empty() && cur >= pq2.top().first)
                pq1.push({pq2.top().second, pq2.top().first}), pq2.pop();

            if(!pq1.empty() && pq1.top().first > 0){
                cur += pq1.top().first;
                pq1.pop();
                k --;
            }
            else break;
        }
        return cur;
    }
};


int main() {

    return 0;
}
