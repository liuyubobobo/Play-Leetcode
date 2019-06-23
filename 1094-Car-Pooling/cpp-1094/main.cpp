/// Source : https://leetcode.com/problems/car-pooling/
/// Author : liuyubobobo
/// Time   : 2019-06-22

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using TreeMap to record all the time events
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        map<int, int> map;
        for(const vector<int>& trip: trips)
            map[trip[1]] += trip[0], map[trip[2]] -= trip[0];

        int cur = 0;
        for(const pair<int, int>& p: map){
            cur += p.second;
            if(cur > capacity) return false;
        }
        return true;
    }
};


int main() {

    return 0;
}