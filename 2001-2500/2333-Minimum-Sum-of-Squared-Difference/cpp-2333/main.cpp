/// Source : https://leetcode.com/problems/minimum-sum-of-squared-difference/
/// Author : liuyubobobo
/// Time   : 2022-07-10

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Soring and Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        int n = nums1.size();
        vector<long long> d(n);
        for(int i = 0; i < n; i ++) d[i] = abs(nums1[i] - nums2[i]);

        sort(d.begin(), d.end(), greater<int>());
        d.push_back(0);
        n ++;

        long long k = k1 + k2;

        long long pre = d[0];
        int i;
        for(i = 1; i < n; i ++){
            long long cur = d[i];
            long long diff = pre - cur;
            if(diff * i <= k){
                k -= diff * i;
                pre = cur;
            }
            else{
                break;
            }
        }

        if(i < n){
            for(int j = 0; j < i; j ++) d[j] = pre;

            for(int j = 0; j < i; j ++){
                d[j] -= k / i;
                if(j < k % i) d[j] --;
            }
        }
        else return 0;

        long long res = 0;
        for(int i = 0; i < n; i ++)
            res += d[i] * d[i];
        return res;
    }
};


int main() {

    vector<int> nums11 = {1, 2, 3, 4}, nums12 = {2, 10, 20, 19};
    cout << Solution().minSumSquareDiff(nums11, nums12, 0, 0) << '\n';
    // 579

    vector<int> nums21 = {1, 4, 10, 12}, nums22 = {5, 8, 6, 9};
    cout << Solution().minSumSquareDiff(nums21, nums22, 1, 1) << '\n';
    // 43

    vector<int> nums31 = {19, 18, 19, 18, 18, 19, 19}, nums32 = {1, 0, 1, 0, 0, 1, 1};
    cout << Solution().minSumSquareDiff(nums31, nums32, 10, 33) << '\n';
    // 985

    return 0;
}
