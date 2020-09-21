/// Source : https://leetcode-cn.com/problems/ccw6C7/
/// Author : liuyubobobo
/// Time   : 2020-09-13

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(4^n * n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int paintingPlan(int n, int k) {

        if(n * n == k || n * n == 0) return 1;

        int res = 0;
        for(int x = 0; x < (1 << n); x ++)
            for(int y = 0; y < (1 << n); y ++)
                if(paint(n, x, y) == k){
//                    cout << x << " " << y << endl;
                    res ++;
                }
        return res;
    }

private:
    int paint(int n, int x, int y){

        vector<vector<int>> g(n, vector<int>(n, 0));

        int r = 0;
        while(x){
            if(x & 1){
                for(int j = 0; j < n; j ++)
                    g[r][j] = 1;
            }
            x >>= 1;
            r ++;
        }

        int c = 0;
        while(y){
            if(y & 1){
                for(int i = 0; i < n; i ++)
                    g[i][c] = 1;
            }
            y >>= 1;
            c ++;
        }

        int res = 0;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                res += g[i][j];
        return res;
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
