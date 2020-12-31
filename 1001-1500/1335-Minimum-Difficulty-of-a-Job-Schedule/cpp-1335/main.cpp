/// Source : https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
/// Author : liuyubobobo
/// Time   : 2020-05-07

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(d * n^2)
/// Space Complexity: O(d * n)
class Solution {

private:
    const int INF = 1e9;
    int n;

public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {

        n = jobDifficulty.size();
        if(d > n) return -1;

        vector<vector<int>> dp(d + 1, vector<int>(n, -1));
        return dfs(jobDifficulty, 0, d, dp);
    }

private:
    int dfs(const vector<int>& nums, int start, int d, vector<vector<int>>& dp){

//        if(start == nums.size()) return d == 0 ? 0 : INF;
        if(dp[d][start] != -1) return dp[d][start];

        if(d == 1) return dp[d][start] = *max_element(nums.begin() + start, nums.end());

        int curmax = nums[start], res = curmax + dfs(nums, start + 1, d - 1, dp);
        for(int i = start + 1; i + d <= nums.size(); i ++){
            curmax = max(curmax, nums[i]);
            res = min(res, curmax + dfs(nums, i + 1, d - 1, dp));
        }
        return dp[d][start] = res;
    }
};


int main() {

    vector<int> job1 = {6,5,4,3,2,1};
    cout << Solution().minDifficulty(job1, 2) << endl;
    // 7

    vector<int> job2 = {9, 9, 9};
    cout << Solution().minDifficulty(job2, 4) << endl;
    // -1

    vector<int> job3 = {1, 1, 1};
    cout << Solution().minDifficulty(job3, 3) << endl;
    // 3

    vector<int> job4 = {7,1,7,1,7,1};
    cout << Solution().minDifficulty(job4, 3) << endl;
    // 15

    vector<int> job5 = {11,111,22,222,33,333,44,444};
    cout << Solution().minDifficulty(job5, 6) << endl;
    // 843

    vector<int> job6 = {42,35,957,671,87,222,524,5,280,878,242,398,610,984,649,513,563,997,786,223,413,961,208,189,519,606,504,406,994,475,940,476,762,283,218,404,715,755,689,457,20,403,749,68,17,763,78,695,445,338,643,400,615,29,866,861,103,665,743,361,798,236,255,15,326,124,14,588,711,992,501,731,538,619,765,8,477,854,243,95,627,480,505,800,818,722,194,717,305,810,497,686,704,322,532,22,234,290,885,416,155,428,161,315,152,441,730,926,175,536,646,922,951,101,107,233,61,735,669,512,28,569,447,982,916,321,1000,754,483,482,811,654,47,344,772,978,467,308,472,269,0,252,131,834,303,945,469,785,537,188,449,675,528,733,271,541,822,328,904,876,889,55,16,853,154,767,573,925,279,697,525,431,375,958,836,911,166,965,523,709,923,587,603,226,354,641,620,316,110,292,529,943,1,151,737,959,27,56,353,681,26,677,337,723,12,914,955,134,370,260,490,684,364,618,232,870,985,196,225,359,129,58,341,67,494,757,229,323,256,21,783,692,642,37,909,248,81,345,425,478,651,309,435,10,534,450,576,144,201,496,267,609,11,454,531,966,156,176,190,542,856,365,983,947,758,950,388,820,867,833,605,741,34,663,884,65,628,969,864,664,718,805,891,657,863,960,518,71,300,756,613,667,228,274,971,970,552,556,648,251};
    cout << Solution().minDifficulty(job6, 10) << endl;
    // 3044

    return 0;
}
