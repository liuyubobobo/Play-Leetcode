/// Source : https://leetcode.com/problems/soup-servings/description/
/// Author : liuyubobobo
/// Time   : 2018-03-31

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Dynamic Programming
///
/// 1. N should be round up based on 25, suppose that's n;
/// 2. We can consifer the 4 types of serving as (4, 0), (3, 1), (2, 2), (1, 3)
///    Then we remove 1 from ever pair, and become (3, 0), (2, 1), (1, 2), (0, 3)
///    We can see that after n/2 serving,
///    it's only (1/2)^(n/2) probability that B is empty
///    because every time, 1 unit of soup will be served from A
/// 3. We can see that for n is large, there's really low probability that B will be empty,
///    which means there's a low probability that A and B are both empty
/// 4. For how large n, we can safely say the result is 1? When (1/2)^n < 10^(-6)
/// 5. For the smaller n, we use dp to solve the problem.
///
/// Using Memory Search
///
/// Time Complexity: O(1) (Compare to N)
/// Space Complexity: O(1) (Compare to N)
class Solution {

private:
    vector<vector<double>> memo1, memo2;
public:
    double soupServings(int N) {

        int n_limit = 50;

        int n = N / 25 + (N % 25 == 0 ? 0 : 1);
        if(n >= n_limit)
            return 1.0;

        return solve(n);
    }

private:
    double solve(int n){

        memo1 = vector<vector<double>>(n + 1, vector<double>(n + 1, -1.0));
        double res1 = solve1(n, n);
        // cout << "res1 = " << res1 << endl;

        memo2 = vector<vector<double>>(n + 1, vector<double>(n + 1, -1.0));
        double res2 = solve2(n, n);
        // cout << "res2 = " << res2 << endl;

        return res1 + 0.5 * res2;
    }

    double solve1(int x, int y){

        if(x <= 0 && y > 0)
            return 1.0;

        if(y <= 0)
            return 0.0;

        if(memo1[x][y] >= 0)
            return memo1[x][y];

        double res = 0.0;
        res += 0.25 * solve1(x - 4, y);
        res += 0.25 * solve1(x - 3, y - 1);
        res += 0.25 * solve1(x - 2, y - 2);
        res += 0.25 * solve1(x - 1, y - 3);
        return memo1[x][y] = res;
    }

    double solve2(int x, int y){

        if(x <= 0 && y <= 0)
            return 1.0;

        if(x <= 0 || y <= 0)
            return 0.0;

        if(memo2[x][y] >= 0)
            return memo2[x][y];

        double res = 0.0;
        res += 0.25 * solve2(x - 4, y);
        res += 0.25 * solve2(x - 3, y - 1);
        res += 0.25 * solve2(x - 2, y - 2);
        res += 0.25 * solve2(x - 1, y - 3);
        return memo2[x][y] = res;
    }
        
    int get_n_limit(){
        double prob = 1.0;
        for(int n = 1; ;n ++){
            prob *= 0.5;
            if(prob < 0.000001)
                return n;
        }
        assert(false);
        return -1;
    }
};

int main() {
    cout << Solution().soupServings(50) << endl;
    return 0;
}