/// Source : https://leetcode.com/problems/minimum-cost-to-set-cooking-time/
/// Author : liuyubobobo
/// Time   : 2021-02-06

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Brute Force
/// Time Complexity: O(targetSeconds / 60)
/// Space Complexity: O(1)
class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {

        int res = INT_MAX;
        for(int minutes = 0; minutes <= 99 && minutes * 60 <= targetSeconds; minutes ++){
            int seconds = targetSeconds - minutes * 60;
            if(seconds > 99) continue;
            res = min(res, get_time(startAt, moveCost, pushCost, minutes, seconds));
        }
        return res;
    }

private:
    int get_time(int startAt, int moveCost, int pushCost, int minute, int seconds){

        vector<int> v(4);
        v[0] = minute / 10, v[1] = minute % 10, v[2] = seconds / 10, v[3] = seconds % 10;

        while(!v.empty() && v[0] == 0) v.erase(v.begin());
        assert(!v.empty());

        int cur_pos = startAt, res = 0;
        for(int e: v){
            if(cur_pos != e) res += moveCost, cur_pos = e;
            res += pushCost;
        }
        return res;
    }
};


int main() {

    cout << Solution().minCostSetTime(1, 2, 1, 600) << endl;
    // 6

    cout << Solution().minCostSetTime(0, 1, 2, 76) << endl;
    // 6

    return 0;
}
