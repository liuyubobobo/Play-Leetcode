/// Source : https://leetcode-cn.com/problems/WHnhjV/
/// Author : liuyubobobo
/// Time   : 2022-04-16

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(|gem| + |op|)
/// Space Complexity: O(1)
class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {

        for(const vector<int>& op: operations){
            int x = op[0], y = op[1];
            int t = gem[x] / 2;
            gem[x] -= t, gem[y] += t;
        }
        return *max_element(gem.begin(), gem.end()) - *min_element(gem.begin(), gem.end());
    }
};


int main() {

    return 0;
}
