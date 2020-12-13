/// Source : https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
/// Author : liuyubobobo
/// Time   : 2020-12-13

#include <iostream>
#include <vector>

using namespace std;


/// LIS
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {

        for(vector<int>& cube: cuboids)
            sort(cube.begin(), cube.end());

        sort(cuboids.begin(), cuboids.end());

        int n = cuboids.size();
        vector<int> dp(n, cuboids[0][2]);
        for(int i = 1; i < n; i ++){
            dp[i] = cuboids[i][2];
            for(int j = i - 1; j >= 0; j --)
                if(cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1] && cuboids[i][2] >= cuboids[j][2])
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};


int main() {

    vector<vector<int>> cubes1 = {{50,45,20},{95,37,53},{45,23,12}};
    cout << Solution().maxHeight(cubes1) << endl;
    // 190

    vector<vector<int>> cubes2 = {{38,25,45},{76,35,3}};
    cout << Solution().maxHeight(cubes2) << endl;
    // 76

    vector<vector<int>> cubes3 = {{7,11,17},{7,17,11},{11,7,17},{11,17,7},{17,7,11},{17,11,7}};
    cout << Solution().maxHeight(cubes3) << endl;
    // 102

    return 0;
}
