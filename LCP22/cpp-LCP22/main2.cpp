/// Source : https://leetcode-cn.com/problems/ccw6C7/
/// Author : liuyubobobo
/// Time   : 2020-09-20

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force and Combination
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {

private:
    vector<vector<int>> c;

public:
    int paintingPlan(int n, int k) {

        if(n * n == k) return 1;

        c = vector<vector<int>>(7, vector<int>(7, -1));

        int res = 0;
        for(int i = 0; i <= n; i ++)
            for(int j = 0; j <= n; j ++){
                int cnt = i * n + j * n - i * j;
                if(cnt == k)
                    res += C(n, i) * C(n, j);
            }
        return res;
    }

private:
    int C(int n, int k){

        if(k == 0 || n == k) return 1;
        if(c[n][k] != -1) return c[n][k];
        return c[n][k] = C(n - 1, k - 1) + C(n - 1, k);
    }
};


int main() {

    cout << Solution().paintingPlan(2, 2) << endl;
    // 4

    cout << Solution().paintingPlan(2, 1) << endl;
    // 0

    cout << Solution().paintingPlan(2, 4) << endl;
    // 1

    return 0;
}
