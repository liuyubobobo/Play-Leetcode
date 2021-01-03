/// Source : https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
/// Author : liuyubobobo
/// Time   : 2021-01-03

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// use self-implement binary search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int waysToSplit(vector<int>& nums) {

        int n = nums.size();

        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + nums[i];

        int res = 0;
        for(int i = 0; i + 2 < n; i ++){
            int lsum1 = presum[i + 1];
            int a = lower_ceil(presum, lsum1 + lsum1, i + 2, (int)presum.size() - 1);
            if(a >= (int)presum.size() - 1) continue;

            int sum = presum.back() - lsum1;
            int lsum2 = sum / 2;

            int b = upper_ceil(presum, lsum1 + lsum2, i + 2, (int)presum.size() - 2);
            if(b == (int) presum.size() - 1 || presum[b] > lsum1 + lsum2) b --;
            if(b >= a)
                res = (res + (b - a + 1)) % MOD;
        }
        return res;
    }

private:
    int lower_ceil(const vector<int>& v, int t, int L, int R){

        if(L > R) return R + 1;
        int l = L, r = R + 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(v[mid] >= t) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    int upper(const vector<int>& v, int t, int L, int R){

        if(L > R) return R + 1;
        int l = L, r = R + 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(v[mid] > t) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    int upper_ceil(const vector<int>& v, int t, int L, int R){

        if(L > R) return R + 1;
        int index = upper(v, t, L, R);
        if(index - 1 >= L && v[index - 1] == t) return index - 1;
        return index;
    }
};


int main() {

    vector<int> nums1 = {1, 1, 1};
    cout << Solution().waysToSplit(nums1) << endl;
    // 1

    vector<int> nums2 = {1, 2, 2, 2, 5, 0};
    cout << Solution().waysToSplit(nums2) << endl;
    // 3

    vector<int> nums3 = {3, 2, 1};
    cout << Solution().waysToSplit(nums3) << endl;
    // 0

    vector<int> nums4 = {0, 3, 3};
    cout << Solution().waysToSplit(nums4) << endl;
    // 1

    vector<int> nums5(1e5, 0);
    cout << Solution().waysToSplit(nums5) << endl;
    // 999849973

    return 0;
}
