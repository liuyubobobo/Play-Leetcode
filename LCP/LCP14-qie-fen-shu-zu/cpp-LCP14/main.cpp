/// Source : https://leetcode-cn.com/problems/qie-fen-shu-zu/
/// Author : liuyubobobo
/// Time   : 2020-04-30

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// DP
/// Time Complexity: O(nlog(maxnum))
/// Space Complexity: O(n)
class Solution {
public:
    int splitArray(vector<int>& nums) {

        if(nums.size() == 1) return 1;

        vector<int> dp(nums.size(), 1);
        unordered_map<int, int> best;
        vector<int> d = get_divisors(nums[0]);
        for(int e: d) best[e] = 0;

        for(int i = 1; i < nums.size(); i ++){
            dp[i] = dp[i - 1] + 1;
            d = get_divisors(nums[i]);
            for(int e: d)
                if(best.count(e)) dp[i] = min(dp[i], best[e] + 1);
            for(int e: d)
                best[e] = best.count(e) ? min(best[e], dp[i - 1]) : dp[i - 1];
        }
        return dp[nums.size() - 1];
    }

private:
    vector<int> get_divisors(int num){

        vector<int> res;
        if(!(num & 1)){
            res.push_back(2);
            while(!(num & 1)) num >>= 1;
        }

        for(int d = 3; d * d <= num; d += 2)
            if(num % d == 0){
                res.push_back(d);
                while(num % d == 0) num /= d;
            }

        if(num != 1) res.push_back(num);
        return res;
    }
};


int main() {

    vector<int> nums1 = {2,3,3,2,3,3};
    cout << Solution().splitArray(nums1) << endl;
    // 2

    vector<int> nums2 = {2,3,5,7};
    cout << Solution().splitArray(nums2) << endl;
    // 4

    vector<int> nums3 = {2,4,6,8,10};
    cout << Solution().splitArray(nums3) << endl;
    // 1

    return 0;
}
