/// Source : https://leetcode.com/problems/count-array-pairs-divisible-by-k/
/// Author : liuyubobobo
/// Time   : 2022-02-19

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


/// Get all divisors for every number
/// Time Complexity: O(n*sqrt(n))
/// Space Complexity: O(maxn)
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {

        int maxn = max(*max_element(nums.begin(), nums.end()), k);

        vector<int> f(maxn + 1, 0);
        long long res = 0;
        for(int e: nums){
            vector<int> divisors;
            for(int d = 1; d * d <= e; d ++)
                if(e % d == 0){
                    divisors.push_back(d);
                    if(d * d < e) divisors.push_back(e / d);
                }
            sort(divisors.begin(), divisors.end());

            int left = -1;
            for(int i = (int)divisors.size() - 1; i >= 0; i --)
                if(k % divisors[i] == 0){
                    left = k / divisors[i];
                    break;
                }
            res += f[left];

            for(int d: divisors) f[d] ++;
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
