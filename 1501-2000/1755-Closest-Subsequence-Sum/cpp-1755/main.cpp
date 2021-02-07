/// Source : https://leetcode.com/problems/closest-subsequence-sum/
/// Author : liuyubobobo
/// Time   : 2021-02-06

#include <iostream>
#include <vector>

using namespace std;


/// Halve and Binary Search
/// Time Comelixity: O(2^(n/2) + nlogn)
/// Space Complexity: O(2^(n/2))
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {

        if(nums.size() == 1) return min(abs(goal), abs(nums[0] - goal));

        int n = nums.size();
        vector<int> a, b;
        for(int i = 0; i < n / 2; i ++) a.push_back(nums[i]);
        for(int i = n / 2; i < n; i ++) b.push_back(nums[i]);

        vector<int> A = get(a), B = get(b);
//        for(int e: A) cout << e << " "; cout << endl;
//        for(int e: B) cout << e << " "; cout << endl;
        sort(B.begin(), B.end());

        int res = abs(goal);
        for(int e: A){
            vector<int>::iterator iter = lower_bound(B.begin(), B.end(), goal - e);
            if(iter != B.end()) res = min(res, abs(e + *iter - goal));
            if(iter != B.begin()){
                iter --;
                res = min(res, abs(e + *iter - goal));
            }
        }
        return res;
    }

private:
    vector<int> get(const vector<int>& nums){

        int n = nums.size(), p;
        vector<int> res(1 << n, 0);
        for(int i = 1; i < (1 << n); i ++){
            p = __builtin_ffs(i) - 1;
            res[i] = nums[p] + res[i - (1 << p)];
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {5, -7, 3, 5};
    cout << Solution().minAbsDifference(nums1, 6) << endl;
    // 0

    vector<int> nums2 = {7, -9, 15, -2};
    cout << Solution().minAbsDifference(nums2, -5) << endl;
    // 1

    vector<int> nums3 = {1, 2, 3};
    cout << Solution().minAbsDifference(nums3, -7) << endl;
    // 7

    vector<int> nums4 = {1556913,-259675,-7667451,-4380629,-4643857,-1436369,7695949,-4357992,-842512,-118463};
    cout << Solution().minAbsDifference(nums4, -9681425) << endl;
    // 10327

    return 0;
}
