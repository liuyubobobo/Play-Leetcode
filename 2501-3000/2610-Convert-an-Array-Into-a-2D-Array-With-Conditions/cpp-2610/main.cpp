/// Source : https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/
/// Author : liuyubobobo
/// Time   : 2023-04-02

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(max_num + max_f)
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {

        int max_num = *max_element(nums.begin(), nums.end());

        vector<int> f(max_num + 1, 0);
        for(int e: nums) f[e] ++;

        int maxf = *max_element(f.begin(), f.end());

        vector<vector<int>> res(maxf);
        for(int e = 0; e <= max_num; e ++){
            if(!f[e]) continue;
            for(int i = 0; i < f[e]; i ++) res[i].push_back(e);
        }
        return res;
    }
};


int main() {

    return 0;
}
