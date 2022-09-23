/// Source : https://leetcode.cn/contest/cnunionpay2022/problems/wMGN0t/
/// Author : liuyubobobo
/// Time   : 2022-09-23

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int StoredEnergy(int storeLimit, const vector<int>& power, const vector<vector<int>>& supply){

        int cur_store = 0, min_supply, max_supply;
        for(int i = 0, j = 0; i < power.size(); i ++){
            if(j < supply.size() && supply[j][0] == i)
                min_supply = supply[j][1], max_supply = supply[j][2], j ++;

            if(min_supply <= power[i] && power[i] <= max_supply) continue;
            if(power[i] > max_supply) cur_store = min(cur_store + power[i] - max_supply, storeLimit);
            if(power[i] < min_supply) cur_store = max(cur_store - (min_supply - power[i]), 0);
        }
        return cur_store;
    }
};


int main() {

    return 0;
}
