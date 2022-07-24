/// Source : https://leetcode.com/problems/number-of-excellent-pairs/
/// Author : liuyubobobo
/// Time   : 2022-07-24

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;


/// bitwise
/// Time Compelxity: O(nlogn(max_a))
/// Space Complexity: O(n)
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {

        map<int, int> ones;
        for(int e: nums){
            if(ones.count(e)) continue;
            ones[e] = get_ones(e);
        }

        vector<int> cnt(63, 0);
        for(const pair<int, int>& p: ones)
            cnt[p.second] ++;

        for(int i = 61; i >= 0; i --)
            cnt[i] += cnt[i + 1];

        long long res = 0;
        for(const pair<int, int>& p: ones){
            int e = p.first;
            int one = p.second;

            int t = max(k - one, 0);
            res += cnt[t];
        }
        return res;
    }

private:
    int get_ones(int e){
        int res = 0;
        while(e){
            res ++;
            e &= (e - 1);
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3, 1};
    cout << Solution().countExcellentPairs(nums1, 3) << '\n';
    // 5

    vector<int> nums2 = {5, 1, 1};
    cout << Solution().countExcellentPairs(nums2, 10) << '\n';
    // 0

    return 0;
}
