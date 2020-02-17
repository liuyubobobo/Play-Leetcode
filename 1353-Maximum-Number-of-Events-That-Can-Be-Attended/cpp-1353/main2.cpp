/// Source : https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
/// Author : liuyubobobo
/// Time   : 2019-02-17

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Using priority queue
/// Time Complexity: O(t * logn)
/// Space Complexity: O(n)
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(const vector<int>& e: events)
            pq.push(make_pair(e[0], e[1]));

        int res = 0;
        for(int i = 0; i <= 100000 && !pq.empty(); i ++){

            pair<int, int> e = pq.top();
            if(i >= e.first && i <= e.second){
                res ++;
                pq.pop();

                while(!pq.empty() && pq.top().first <= i){
                    pair<int, int> t = pq.top();
                    pq.pop();
                    if(i + 1 <= t.second){
                        t.first = i + 1;
                        pq.push(t);
                    }
                }
            }
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
