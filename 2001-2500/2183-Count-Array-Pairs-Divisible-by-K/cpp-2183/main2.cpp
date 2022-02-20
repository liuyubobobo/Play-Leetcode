/// Source : https://leetcode.com/problems/count-array-pairs-divisible-by-k/
/// Author : liuyubobobo
/// Time   : 2022-02-20

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


/// Get all divisors for k
/// Time Complexity: O(n*sqrt(k))
/// Space Complexity: O(k)
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {

        vector<int> divisors;
        for(int d = 1; d * d <= k; d ++)
            if(k % d == 0){
                divisors.push_back(d);
                if(d * d < k) divisors.push_back(k / d);
            }
        sort(divisors.begin(), divisors.end());

        vector<int> f(k + 1, 0);
        long long res = 0;
        for(int e: nums){

            int left = -1;
            for(int i = (int)divisors.size() - 1; i >= 0; i --)
                if(e % divisors[i] == 0){
                    left = k / divisors[i];
                    break;
                }
            res += f[left];

            for(int d: divisors) if(e % d == 0) f[d] ++;
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3, 4, 5};
    cout << Solution().countPairs(nums1, 2) << endl;
    // 7

    vector<int> nums2 = {1, 2, 3, 4};
    cout << Solution().countPairs(nums2, 5) << endl;
    // 0

    return 0;
}
