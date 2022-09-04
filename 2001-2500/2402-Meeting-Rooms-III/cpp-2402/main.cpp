/// Source : https://leetcode.com/problems/meeting-rooms-iii/
/// Author : liuyubobobo
/// Time   : 2022-09-03

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;


/// PQ Events Simulation
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

private:
    const int END_EVENT = 0, START_EVENT = 1;

public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        // event:
        // start_time,
        // 0 -end_meeting, 1 - start_meeting,
        // end_meeting: room_number; start_meeting: end_time
        priority_queue<pair<pair<long long, int>, long long>, vector<pair<pair<long long, int>, long long>>, greater<pair<pair<long long, int>, long long>>> events;
        for(int i = 0; i < meetings.size(); i ++){
            long long start_time = meetings[i][0], end_time = meetings[i][1];
            events.push({{start_time, START_EVENT}, end_time});
        }
        set<int> availables;
        set<pair<long long, long long>> waiting_list; // start, duration
        for(int i = 0; i < n; i ++) availables.insert(i);

        vector<int> cnt(n, 0);
        while(!events.empty()){
            long long start_time = events.top().first.first;
            int type = events.top().first.second;
            long long x = events.top().second;
            events.pop();

            if(type == START_EVENT){
                long long end_time = x;
                if(!availables.empty()){
                    int room_id = *availables.begin();
                    availables.erase(availables.begin());
                    cnt[room_id] ++;
                    events.push({{end_time, END_EVENT}, room_id});
                }
                else{
                    waiting_list.insert({start_time, end_time - start_time});
                }
            }
            else{
                int room_id = x;
                if(waiting_list.empty()){
                    availables.insert(room_id);
                    continue;
                }

                long long duration = waiting_list.begin()->second;
                waiting_list.erase(waiting_list.begin());

                cnt[room_id] ++;
                events.push({{start_time + duration, END_EVENT}, room_id});
            }
        }

        int best = -1, res = -1;
        for(int i = 0; i < n; i ++)
            if(cnt[i] > best) best = cnt[i], res = i;
        return res;
    }
};


int main() {

    vector<vector<int>> meetings1 = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};
    cout << Solution().mostBooked(2, meetings1) << '\n';
    // 0

    vector<vector<int>> meetings2 = {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};
    cout << Solution().mostBooked(3, meetings2) << '\n';
    // 1

    return 0;
}
