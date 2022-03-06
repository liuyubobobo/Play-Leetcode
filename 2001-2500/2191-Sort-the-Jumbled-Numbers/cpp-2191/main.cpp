/// Source : https://leetcode.com/problems/sort-the-jumbled-numbers/
/// Author : liuyubobobo
/// Time   : 2022-03-05

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(nlogn * log(num))
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        int n = nums.size();
        vector<pair<int, int>> data(n);
        for(int i = 0; i < n; i ++){
            data[i] = {0, i};

            string s = to_string(nums[i]);
            for(char& c: s) c = '0' + mapping[c - '0'];
            data[i].first = atoi(s.c_str());
        }

        sort(data.begin(), data.end());

        vector<int> res(n);
        for(int i = 0; i < n; i ++) res[i] = nums[data[i].second];
        return res;
    }
};


int main() {

    return 0;
}
