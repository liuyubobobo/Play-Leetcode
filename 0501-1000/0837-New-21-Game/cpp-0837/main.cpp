/// Source : https://leetcode.com/problems/new-21-game/description/
/// Author : liuyubobobo
/// Time   : 2023-05-25

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(k + maxPts)
/// Space Complexity: O(k + maxPts)
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {

        if(k == 0) return 1.0;

        vector<long double> p(k + maxPts, 0), presum(k + maxPts + 1, 0);
        p[0] = 1.0;
        presum[1] = 1.0;
        for(int i = 1; i < p.size(); i ++){
            int r = min(i - 1, k - 1), l = max(i - maxPts, 0);
            long double sum = presum[r + 1] - presum[l];
            p[i] = sum / maxPts;
            presum[i + 1] = presum[i] + p[i];
        }

        long double res = 0.0;
        for(int i = k; i <= n && i < p.size(); i ++) res += p[i];
        return res;
    }
};


int main() {

    cout << Solution().new21Game(10, 1, 10) << '\n';
    // 1.0

    return 0;
}
