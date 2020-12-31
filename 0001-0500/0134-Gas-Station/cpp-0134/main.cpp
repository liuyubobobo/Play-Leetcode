/// Source : https://leetcode.com/problems/gas-station/
/// Author : liuyubobobo
/// Time   : 2019-03-16

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();

        int minv = INT_MAX, res = -1, cur = 0;
        for(int i = 0; i < n; i ++){
            cur += gas[i] - cost[i];
            if(cur < minv) minv = cur, res = i;
        }
        if(cur < 0) return -1;
        return (res + 1) % n;
    }
};


int main() {

    return 0;
}