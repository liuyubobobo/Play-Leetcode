/// Source : https://leetcode.com/problems/arithmetic-subarrays/
/// Author : liuyubobobo
/// Time   : 2020-10-24

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(qnlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {

        vector<bool> res(l.size());
        for(int i = 0; i < l.size(); i ++)
            res[i] = ok(nums, l[i], r[i]);
        return res;
    }

private:
    bool ok(const vector<int>& nums, int l, int r){

        vector<int> a(nums.begin() + l, nums.begin() + (r + 1));
        sort(a.begin(), a.end());

        int d = a[1] - a[0];
        for(int i = 2; i < a.size(); i ++)
            if(a[i] - a[i - 1] != d) return false;
        return true;
    }
};


void print_vec(const vector<bool>& v){
    for(bool e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums1 = {4,6,5,9,3,7}, l1 = {0, 0, 2}, r1 = {2, 3, 5};
    print_vec(Solution().checkArithmeticSubarrays(nums1, l1, r1));
    // 1 0 1

    vector<int> nums2 = {-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10},
                l2 = {0,1,6,4,8,7}, r2 = {4,4,9,7,9,10};
    print_vec(Solution().checkArithmeticSubarrays(nums2, l2, r2));
    // 0 1 0 0 1 1

    return 0;
}
