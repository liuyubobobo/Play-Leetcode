/// Source : https://leetcode.com/problems/time-to-cross-a-bridge/description/s
/// Author : liuyubobobo
/// Time   : 2023-01-09

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <climits>
#include <cassert>

using namespace std;


/// Event Simulation, Using PQ
/// Time Complexity: O(nlogk)
/// Space Complexity: O(k)
class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> left_ready_q, right_ready_q; // ready_time, index
        priority_queue<pair<int, int>> bridge_left_q, bridge_right_q; // efficient, index
        for(int i = 0; i < k; i ++)
            bridge_left_q.push({time[i][0] + time[i][2], i});

        int cur_time = 0, left = n, complete = 0;
        while(true){

            while(!left_ready_q.empty() && cur_time >= left_ready_q.top().first){
                int index = left_ready_q.top().second;
                left_ready_q.pop();
                bridge_left_q.push({time[index][0] + time[index][2], index});
            }

            while(!right_ready_q.empty() && cur_time >= right_ready_q.top().first){
                int index = right_ready_q.top().second;
                right_ready_q.pop();
                bridge_right_q.push({time[index][0] + time[index][2], index});
            }

            if(!bridge_right_q.empty()){
                int index = bridge_right_q.top().second;
                bridge_right_q.pop();

                cur_time += time[index][2];

                left_ready_q.push({cur_time + time[index][3], index});

                complete ++;
                if(complete == n) return cur_time;
            }
            else if(left && !bridge_left_q.empty()){
                int index = bridge_left_q.top().second;
                bridge_left_q.pop();

                cur_time += time[index][0];

                right_ready_q.push({cur_time + time[index][1], index});

                left --;
            }
            else{
                int next_time = INT_MAX;
                if(!left_ready_q.empty()) next_time = min(next_time, left_ready_q.top().first);
                if(!right_ready_q.empty()) next_time = min(next_time, right_ready_q.top().first);
                assert(next_time != INT_MAX);
                cur_time = next_time;
            }
        }
        return -1;
    }
};


int main() {

    vector<vector<int>> time1 = {{1, 1, 2, 1}, {1, 1, 3, 1}, {1, 1, 4, 1}};
    cout << Solution().findCrossingTime(1, 3, time1) << '\n';
    // 6

    return 0;
}
