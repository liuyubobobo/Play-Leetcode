/// Source : https://leetcode.com/problems/meeting-scheduler/
/// Author : liuyubobobo
/// Time   : 2019-10-19

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Using Priority Queue
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1;
        for(const vector<int>& p: slots1)
            pq1.push(make_pair(p[0], p[1]));

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
        for(const vector<int>& p: slots2)
            pq2.push(make_pair(p[0], p[1]));

        while(!pq1.empty() && !pq2.empty()){
            pair<int, int> p1 = pq1.top();
            pair<int, int> p2 = pq2.top();

            int a = max(p1.first, p2.first);
            int b = min(p1.second, p2.second);
            if(a <= b && a + duration <= b) return {a, a + duration};
            if(p1 < p2) pq1.pop();
            else pq2.pop();
        }
        return {};
    }
};


int main() {

    return 0;
}