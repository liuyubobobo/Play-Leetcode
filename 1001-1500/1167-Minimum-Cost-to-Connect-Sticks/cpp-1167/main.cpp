/// Source : https://leetcode.com/problems/minimum-cost-to-connect-sticks/
/// Author : liuyubobobo
/// Time   : 2019-08-24

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int connectSticks(vector<int>& sticks) {

        priority_queue<int, vector<int>, greater<int>> pq;
        for(int stick: sticks) pq.push(stick);
        int res = 0;
        while(pq.size() > 1){
            int cost = pq.top();
            pq.pop();
            cost += pq.top();
            pq.pop();

            res += cost;
            pq.push(cost);
        }
        return res;
    }
};


int main() {

    vector<int> sticks1 = {2, 4, 3};
    cout << Solution().connectSticks(sticks1) << endl;

    vector<int> sticks2 = {1, 8, 3, 5};
    cout << Solution().connectSticks(sticks2) << endl;
    return 0;
}