/// Source : https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/
/// Author : liuyubobobo
/// Time   : 2021-05-29

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search + Memory Search
/// Time Complexity: O(n^2 * logn)
/// Space Complexity: O(n^2)
class Solution {

private:
    double speed, hoursBefore;
    vector<vector<double>> dp;

public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {

        this->speed = speed;
        this->hoursBefore = hoursBefore;

        double t = 0;
        for(int d: dist)
            t += d / this->speed;

        if(t > this->hoursBefore) return -1;

        int n = dist.size();
        dp = vector<vector<double>>(n, vector<double>(n + 1, -1.0));

        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(ok(dist, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    bool ok(const vector<int>& dist, int k){

        int n = dist.size();
        return dfs(dist, n - 1, k) <= hoursBefore;
    }

    double dfs(const vector<int>& dist, int i, int k){

        if(i == 0) return dist[i] / speed;
        if(dp[i][k] >= 0.0) return dp[i][k];

        double res = ceil(dfs(dist, i - 1, k) - 1e-8) + dist[i] / speed;
        if(k)
            res = min(res, dfs(dist, i - 1, k - 1) + dist[i] / speed);
        return dp[i][k] = res;
    }
};


int main() {

    vector<int> dist1 = {1, 3, 2};
    cout << Solution().minSkips(dist1, 4, 2) << endl;
    // 1

    vector<int> dist2 = {7, 3, 5, 5};
    cout << Solution().minSkips(dist2, 2, 10) << endl;
    // 2

    vector<int> dist3 = {7, 3, 5, 5};
    cout << Solution().minSkips(dist3, 1, 10) << endl;
    // -1

    vector<int> dist4 = {35,57,85,55,63,78,57,54,35,28,97,66,15,45,56,15,37,87,87,76,63,68,86,40,6,29,51,77,8,1,27,39,28,99,18,98,33,38,42,16,1,64,96,56,23,17,49,69,91,30,65,72,86,46,10,51,95,6,56,3,59,10,41,74,55,74,52,91,82,54,38,15,52,3,42,22,80,59,89,47,12,56,14,32,56,76,52,68,11,51,40,96,44,29,43,100,22,10,66,82,15,68,66,25,100,45,45,94,83,19,31,14,19,33,26,23,78,20,98,98,84,10,23,99,81,64,60,97,73,98,75,58,88,73,83,82,80,42,81,41,20};
    cout << Solution().minSkips(dist4, 59, 128) << endl;
    // 101

    return 0;
}
