/// Source : https://leetcode.com/problems/minimum-number-of-refueling-stops/description/
/// Author : liuyubobobo
/// Time   : 2020-05-10

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Greedy using PQ
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        if(startFuel >= target)
            return 0;

        int n = stations.size();
        priority_queue<int> pq;
        int i = 0, cur = startFuel, res = 0;
        while(cur < target){
            for(; i < n && cur >= stations[i][0]; i ++)
                pq.push(stations[i][1]);

            if(!pq.empty()) cur += pq.top(), pq.pop(), res ++;
            else break;
        }
        return cur >= target ? res : -1;
    }
};


int main() {

    int target1 = 1, startFuel1 = 1;
    vector<vector<int>> stations1;
    cout << Solution().minRefuelStops(target1, startFuel1, stations1) << endl;
    // 0

    int target2 = 100, startFuel2 = 1;
    vector<vector<int>> stations2 = {{10, 100}};
    cout << Solution().minRefuelStops(target2, startFuel2, stations2) << endl;
    // -1

    int target3 = 100, startFuel3 = 10;
    vector<vector<int>> stations3 = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    cout << Solution().minRefuelStops(target3, startFuel3, stations3) << endl;
    // 2

    int target4 = 1000, startFuel4 = 83;
    vector<vector<int>> stations4 = {{25, 27}, {36, 187}, {140, 186}, {378, 6}, {492, 202},
                                     {517, 89}, {579, 234}, {673, 86}, {808, 53}, {954, 49}};
    cout << Solution().minRefuelStops(target4, startFuel4, stations4) << endl;
    // -1

    return 0;
}