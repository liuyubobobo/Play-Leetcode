/// Source : https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
/// Author : liuyubobobo
/// Time   : 2020-06-05

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Memory Search
/// Time Complexity: O(balls[i]^3 * balls.length * sum)
/// Space Complexity: O(balls[i]^2 * balls.length * sum)
class Solution {

private:
    int n;
    double perm[49];

public:
    double getProbability(vector<int>& balls) {

        perm[0] = 1.0;
        for(int i = 1; i <= 48; i ++) perm[i] = i * perm[i - 1];

        n = accumulate(balls.begin(), balls.end(), 0);

        double all = perm[n];
        for(int e: balls) all /= perm[e];
//        cout << "all : " << all << endl;

        vector<double> dp(25 * 10 * 10 * 10, -1);
        double valid = dfs(balls, 0, 0, 0, n / 2, n / 2, dp);
//        cout << "valid : " << valid << endl;

        return valid / all;
    }

private:
    double dfs(vector<int>& balls, int index, int c1, int c2, int cnt1, int cnt2,
               vector<double>& dp){

        if(index == balls.size())
            return cnt1 == 0 && cnt2 == 0 && c1 == c2;

        int hashcode = cnt1 * 1000 + c2 * 100 + c1 * 10 + index;
        if(dp[hashcode] != -1) return dp[hashcode];

        double res = 0.0;
        for(int i = 0; i <= balls[index] && i <= cnt1; i ++)
            if(balls[index] - i <= cnt2)
                res += dfs(balls, index + 1, i ? c1 + 1 : c1, balls[index] - i ? c2 + 1 : c2, cnt1 - i, cnt2 - (balls[index] - i), dp)
                       * C(cnt1, i) * C(cnt2, balls[index] - i);
        return dp[hashcode] = res;
    }

    double C(int a, int k){
//        assert(k >= 0 && k <= a);
        return perm[a] / perm[k] / perm[a - k];
    }
};


int main() {

    vector<int> balls1 = {1, 1};
    cout << Solution().getProbability(balls1) << endl;
    // 1.0

    vector<int> balls2 = {2, 1, 1};
    cout << Solution().getProbability(balls2) << endl;
    // 0.66667

    vector<int> balls3 = {1, 2, 1, 2};
    cout << Solution().getProbability(balls3) << endl;
    // 0.6

    vector<int> balls4 = {3, 2, 1};
    cout << Solution().getProbability(balls4) << endl;
    // 0.3

    vector<int> balls5 = {6,6,6,6,6,6};
    cout << Solution().getProbability(balls5) << endl;
    // 0.90327

    return 0;
}
