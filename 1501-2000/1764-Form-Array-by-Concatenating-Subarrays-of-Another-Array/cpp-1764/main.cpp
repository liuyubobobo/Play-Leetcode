/// Source : https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/
/// Author : liuyubobobo
/// Time   : 2021-02-20

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(m * n)
/// Space Complexity: O(1)
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {

        int pos = 0;
        for(const vector<int>& group: groups){
            int tres = find(nums, group, pos);
            if(tres == -1) return false;

            pos = tres + group.size();
        }
        return true;
    }

private:
    int find(const vector<int>& nums, const vector<int>& t, int start){

        for(int i = start; i + (int)t.size() <= nums.size(); i ++){
            int j = 0;
            for(; j < t.size(); j ++)
                if(nums[i + j] != t[j]) break;
            if(j == t.size()) return i;
        }
        return -1;
    }
};


int main() {

    vector<vector<int>> groups1 = {{1, -1, -1}, {3, -2, 0}};
    vector<int> nums1 = {1, -1, 0, 1, -1, -1, 3, -2, 0};
    cout << Solution().canChoose(groups1, nums1) << endl;
    // 1

    return 0;
}
