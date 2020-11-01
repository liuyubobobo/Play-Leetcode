/// Source : https://leetcode.com/problems/kth-smallest-instructions/
/// Author : liuyubobobo
/// Time   : 2020-10-31

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {

private:
    int R, C;

public:
    string kthSmallestPath(vector<int>& destination, int k) {

        R = destination[0] + 1, C = destination[1] + 1;
        vector<vector<int>> dp(R, vector<int>(C, 1));
        for(int i = R - 2; i >= 0; i --)
            for(int j = C - 2; j >= 0; j --)
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];

//        for(const vector<int>& row: dp){
//            for(int e: row) cout << e << " "; cout << endl;
//        }

        string res = "";
        int x = 0, y = 0;
        while(!(x == destination[0] && y == destination[1])){
            if(in_area(x, y + 1) && k <= dp[x][y + 1]){
                res += "H";
                y ++;
            }
            else{
                res += "V";
                if(in_area(x, y + 1)) k -= dp[x][y + 1];
                x ++;
            }
        }
        return res;
    }

private:
    bool in_area(int x, int y){
        return x >= 0 && x < R && y >= 0 && y < C;
    }
};


int main() {

    vector<int> d1 = {2, 3};
    cout << Solution().kthSmallestPath(d1, 1) << endl;
    // HHHVV

    vector<int> d2 = {2, 3};
    cout << Solution().kthSmallestPath(d1, 2) << endl;
    // HHVHV

    vector<int> d3 = {2, 3};
    cout << Solution().kthSmallestPath(d1, 3) << endl;
    // HHVVH

    vector<int> d4 = {2, 3};
    cout << Solution().kthSmallestPath(d4, 4) << endl;
    // HVHHV

    vector<int> d = {2, 3};
    vector<string> ans = {"HHHVV", "HHVHV", "HHVVH", "HVHHV", "HVHVH", "HVVHH", "VHHHV", "VHHVH", "VHVHH", "VVHHH"};
    for(int i = 1; i <= 10; i ++)
        if(Solution().kthSmallestPath(d, i) != ans[i - 1]){
            cout << "Error! " << i << endl;
        }

    return 0;
}
