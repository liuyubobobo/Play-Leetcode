/// Source : https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/
/// Author : liuyubobobo
/// Time   : 2021-06-05

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Sorting + Presum
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int reductionOperations(vector<int>& nums) {

        unordered_map<int, int> f;
        for(int e: nums) f[e] ++;

        vector<pair<int, int>> data;
        for(const pair<int, int>& p: f) data.push_back(p);

        sort(data.rbegin(), data.rend());

        int res = 0, prev = 0;
        for(int i = 0; i + 1 < data.size(); i ++){
            prev += data[i].second;
            res += prev;
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {5, 1, 3};
    cout << Solution().reductionOperations(nums1) << endl;
    // 3

    vector<int> nums2 = {1, 1, 1};
    cout << Solution().reductionOperations(nums2) << endl;
    // 0

    vector<int> nums3 = {1, 1, 2, 2, 3};
    cout << Solution().reductionOperations(nums3) << endl;
    // 4

    return 0;
}
