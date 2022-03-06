/// Source : https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/
/// Author : liuyubobobo
/// Time   : 2022-03-05

#include <iostream>
#include <map>
#include <vector>

using namespace std;


/// Using Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {

        map<int, int> f;
        for(int i = 0; i + 1 < nums.size(); i ++)
            if(nums[i] == key) f[nums[i + 1]] ++;

        int max_cnt = 0, res;
        for(const pair<int, int>& p: f)
            if(p.second > max_cnt) max_cnt = p.second, res = p.first;
        return res;
    }
};


int main() {

    return 0;
}
