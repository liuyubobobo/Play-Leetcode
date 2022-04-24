/// Source : https://leetcode.com/problems/number-of-flowers-in-full-bloom/
/// Author : liuyubobobo
/// Time   : 2022-04-23

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Sweep line
/// Time Complexity: O(|2 * flowers + persons| * log|2 * flowers + persons|)
/// Space Complexity: O(|2 * flowers + persons|)
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {

        vector<vector<int>> events;
        // event flower: start_time 0 0
        //               end_time 0 1
        // person        query_time 1 index

        for(const vector<int>& flower: flowers){
            int start = flower[0], end = flower[1];
            events.push_back({start, 0, 0});
            events.push_back({end + 1, 0, 1});
        }
        for(int i = 0; i < persons.size(); i ++)
            events.push_back({persons[i], 1, i});

        sort(events.begin(), events.end());
        vector<int> res(persons.size(), 0);
        int cur = 0;
        for(const vector<int>& event: events){
            int type = event[1];
            if(type == 0){
                cur += (event[2] == 0 ? 1 : -1);
            }
            else res[event[2]] = cur;
        }
        return res;
    }
};


int main() {

    return 0;
}
