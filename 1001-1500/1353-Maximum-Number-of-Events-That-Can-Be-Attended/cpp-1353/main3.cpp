/// Source : https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
/// Author : liuyubobobo
/// Time   : 2019-02-17

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Using priority queue to only record the end date
/// Time Complexity: O(t * logn)
/// Space Complexity: O(n)
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {

        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        int res = 0, e = 0;
        for(int i = 0; i <= 100000; i ++){
            while(e < events.size() && events[e][0] == i) pq.push(events[e ++][1]);
            while(!pq.empty() && pq.top() < i) pq.pop();
            if(!pq.empty()) res ++, pq.pop();
        }
        return res;
    }
};


int main() {

    vector<vector<int>> events1 = {{1, 2}, {2, 3}, {3, 4}, {1, 2}};
    cout << Solution().maxEvents(events1) << endl;
    // 4

    vector<vector<int>> events2 = {{1, 4}, {4, 4}, {2, 2}, {3, 4}, {1, 1}};
    cout << Solution().maxEvents(events2) << endl;
    // 4

    vector<vector<int>> events3 = {{1, 5}, {1, 5}, {1, 5}, {2, 3}, {2, 3}};
    cout << Solution().maxEvents(events3) << endl;
    // 5

    vector<vector<int>> events4 = {{7, 11}, {7, 11}, {7, 11}, {9, 10}, {9, 11}};
    cout << Solution().maxEvents(events4) << endl;
    // 5

    return 0;
}
