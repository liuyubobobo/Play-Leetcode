/// Source : https://leetcode.com/problems/the-latest-time-to-catch-a-bus/
/// Author : liuyubobobo
/// Time   : 2022-07-12

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Simulation
/// Time Complexity: O(n + m)
/// Space Complexity: O(n)
class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {

        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        vector<int> pre(passengers.size());
        for(int start = 0, i = 1; i <= passengers.size(); i ++)
            if(i == passengers.size() || passengers[i] != passengers[start] + (i - start)){
                for(int j = start; j < i; j ++) pre[j] = passengers[start] - 1;
                start = i;
            }

        int res = 1;
        int pi = 0;
        for(int bi = 0; bi < buses.size(); bi ++){
            vector<int> v;
            for(; pi < passengers.size() && passengers[pi] <= buses[bi] && v.size() < capacity; pi ++)
                v.push_back(pi);

            for(int i: v)
                res = max(res, pre[i]);

            if(v.size() < capacity){
                if(v.empty() || passengers[v.back()] != buses[bi])
                    res = max(res, buses[bi]);
            }
        }
        return res;
    }
};


int main() {

    vector<int> buses1 = {10, 20}, passengers1 = {2, 17, 18, 19};
    cout << Solution().latestTimeCatchTheBus(buses1, passengers1, 2) << '\n';
    // 16

    vector<int> buses2 = {20, 30, 10}, passengers2 = {19, 13, 26, 4, 25, 11, 21};
    cout << Solution().latestTimeCatchTheBus(buses2, passengers2, 2) << '\n';
    // 20

    vector<int> buses3 = {2}, passengers3 = {2};
    cout << Solution().latestTimeCatchTheBus(buses3, passengers3, 2) << '\n';
    // 1

    vector<int> buses4 = {5, 15}, passengers4 = {11, 12, 13, 14, 15};
    cout << Solution().latestTimeCatchTheBus(buses4, passengers4, 2) << '\n';
    // 10

    vector<int> buses5 = {7,12,15,11,14,13,5,4,2,8,9,19}, passengers5 = {2,5,10,12,8,19,9,14,4,7,15,13};
    cout << Solution().latestTimeCatchTheBus(buses5, passengers5, 2) << '\n';
    // 18

    return 0;
}
