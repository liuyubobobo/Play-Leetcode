/// Source : https://leetcode.com/problems/meeting-scheduler/
/// Author : liuyubobobo
/// Time   : 2019-10-19
/// Updated: 2021-04-29

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

            if(p1.second < p2.second) pq1.pop();
            else if(p2.second < p1.second) pq2.pop();
            else if(p1 < p2) pq1.pop();
            else pq2.pop();
        }
        return {};
    }
};


void print_vec(const vector<int>& vec){

    for(int e: vec) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> slot1 = {{10, 60}}, slot2 = {{12, 17}, {21, 50}};
    print_vec(Solution().minAvailableDuration(slot1, slot2, 8));

    return 0;
}