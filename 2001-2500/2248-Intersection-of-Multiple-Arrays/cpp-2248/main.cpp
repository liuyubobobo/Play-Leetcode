/// Source : https://leetcode.com/problems/intersection-of-multiple-arrays/
/// Author : liuyubobobo
/// Time   : 2022-04-23

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using Set
/// Time Complexity: O(sum(nums[i][j]))
/// Space Complexity: O(min(nums[i]))
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {

        set<int> res_set(nums[0].begin(), nums[0].end());
        for(int i = 1; i < nums.size(); i ++)
            res_set = intersect(res_set, nums[i]);
        return vector<int>(res_set.begin(), res_set.end());
    }

private:
    set<int> intersect(const set<int>& s, const vector<int>& v){

        set<int> res;
        for(int e: v) if(s.count(e)) res.insert(e);
        return res;
    }
};


int main() {

    return 0;
}
