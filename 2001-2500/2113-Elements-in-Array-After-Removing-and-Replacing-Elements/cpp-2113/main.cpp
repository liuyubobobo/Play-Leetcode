/// Source : https://leetcode.com/problems/elements-in-array-after-removing-and-replacing-elements/
/// Author : liuyubobobo
/// Time   : 2021-12-24

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(q)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();

        vector<int> res(queries.size());
        for(int i = 0; i < queries.size(); i ++){
            int t = queries[i][0], index = queries[i][1];

            t %= (2 * n);
            int m;
            if(t < n) m = n - t;
            else m = t - n;

            if(index >= m) res[i] = -1;
            else if(t < n) res[i] = nums[index + t];
            else res[i] = nums[index];
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<int> nums1 = {0, 1, 2};
    vector<vector<int>> queries1 = {{0, 2}, {2, 0}, {3, 2}, {5, 0}};
    print_vec(Solution().elementInNums(nums1, queries1));
    // 2 2 -1 0

    vector<int> nums2 = {2};
    vector<vector<int>> queries2 = {{0, 0}, {1, 0}, {2, 0}, {3, 0}};
    print_vec(Solution().elementInNums(nums2, queries2));
    // 2 -1 2 -1

    return 0;
}
