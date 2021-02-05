/// Source : https://leetcode.com/problems/longest-harmonious-subsequence/
/// Author : liuyubobobo
/// Time   : 2021-02-05

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int findLHS(vector<int>& nums) {

        unordered_map<int, int> f;
        for(int e: nums) f[e] ++;

        int res = 0;
        for(const pair<int, int>& p: f)
            if(f.count(p.first + 1))
                res = max(res, p.second + f[p.first + 1]);

        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 1, 1, 1};
    cout << Solution().findLHS(nums1) << endl;
    // 4

    return 0;
}
