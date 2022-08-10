/// Source : https://leetcode.com/problems/count-number-of-bad-pairs/
/// Author : liuyubobobo
/// Time   : 2022-08-10

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        int n = nums.size();
        for(int i = 0; i < n; i ++)
            nums[i] -= i;

        map<int, int> f;
        for(int e: nums) f[e] ++;

        long long res = 1ll * n * (n - 1) / 2ll;
        for(const pair<int, int>& p: f){
            long long len = p.second;
            res -= len * (len - 1) / 2ll;
        }
        return res;
    }
};


int main() {

    return 0;
}
