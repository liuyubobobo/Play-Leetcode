/// Source : https://leetcode.com/problems/sum-of-special-evenly-spaced-elements-in-array/
/// Author : liuyubobobo
/// Time   : 2021-01-08

#include <iostream>
#include <vector>

using namespace std;


/// SQRT Decomposition
/// Time Complexity: O(n*sqrt(n))
/// Space Complexity: O(n*sqrt(n))
class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    vector<int> solve(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        int B = (int)sqrt(n);

        vector<vector<int>> table(B + 1, vector<int>(n + 1, 0));
        for(int b = 1; b <= B; b ++) {
            table[b][1] = nums[0];
            for (int i = 1; i < n; i++)
                table[b][i + 1] = ((i - b >= 0 ? table[b][i - b + 1] : 0) + nums[i]) % MOD;
        }

        vector<int> res(queries.size());
        for(int i = 0; i < queries.size(); i ++){
            int x = queries[i][0], y = queries[i][1];
            if(y > B){
                int t = 0;
                for(int j = x; j < n; j += y)
                    t = (t + nums[j]) % MOD;
                res[i] = t;
            }
            else{
                int t = (n - 1) / y * y + x % y;
                while(t >= n) t -= y;
                res[i] = (table[y][t + 1] - table[y][max(0, x - y + 1)] + MOD) % MOD;
            }
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums1 = {0,1,2,3,4,5,6,7};
    vector<vector<int>> queries1 = {{0, 3}, {5, 1}, {4, 2}, {3, 2}};
    print_vec(Solution().solve(nums1, queries1));
    // 9 18 10 10

    vector<int> nums2 = {100,200,101,201,102,202,103,203};
    vector<vector<int>> queries2 = {{0, 7}};
    print_vec(Solution().solve(nums2, queries2));
    // 303

    vector<int> nums3 = {1123,9873123,83745634,78649234,872842342,234239847};
    vector<vector<int>> queries3 = {{0, 1}, {3, 4}, {3, 2}};
    print_vec(Solution().solve(nums3, queries3));
    // 279351296 78649234 312889081

    return 0;
}
