/// Source : https://leetcode.com/problems/append-k-integers-with-minimal-sum/
/// Author : liuyubobobo
/// Time   : 2022-03-05

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {

        nums.push_back(0);
        nums.push_back(INT_MAX);
        sort(nums.begin(), nums.end());

        long long res = 0;
        for(int i = 1; i < nums.size() && k; i ++){
            long long l = nums[i - 1] + 1, r = nums[i] - 1;
            long long len = r - l + 1;
            if(len <= 0) continue;

            if(len <= k){
                res += (l + r) * len / 2ll;
                k -= len;
            }
            else{
                len = k, r = l + len - 1ll;
                res += (l + r) * len / 2ll;
                k = 0;
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
