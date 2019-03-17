/// Source : https://leetcode.com/problems/gas-station/
/// Author : liuyubobobo
/// Time   : 2019-03-16

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// This solution is more intuitive, see Leetcode Official Solution for details:
/// https://leetcode.com/problems/gas-station/solution/
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();

        int res = 0, total = 0, cur = 0;
        for(int i = 0; i < n; i ++){
            cur += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if(total <= 0) res = (i + 1) % n, total = 0;
        }
        if(cur < 0) return -1;
        return res;
    }
};


int main() {

    return 0;
}