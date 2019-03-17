/// Source : https://leetcode.com/problems/odd-even-jump/
/// Author : liuyubobobo
/// Time   : 2019-03-16

#include <iostream>
#include <vector>
#include <cassert>
#include <stack>

using namespace std;


/// Monotonic Stack
///
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int oddEvenJumps(const vector<int>& A) {

        int n = A.size();

        vector<pair<int, int>> data(n);
        for(int i = 0; i < n; i ++) data[i] = make_pair(A[i], i);

        vector<int> larger(n, -1);
        sort(data.begin(), data.end());
        stack<int> s1;
        s1.push(data[0].second);
        for(int i = 1; i < n; i ++){
            while(!s1.empty() && s1.top() < data[i].second)
                larger[s1.top()] = data[i].second, s1.pop();
            s1.push(data[i].second);
        }

        vector<int> smaller(n, -1);
        for(int i = 0; i < n; i ++) data[i] = make_pair(-A[i], i);
        sort(data.begin(), data.end());
        stack<int> s2;
        s2.push(data[0].second);
        for(int i = 1; i < n; i ++){
            while(!s2.empty() && s2.top() < data[i].second)
                smaller[s2.top()] = data[i].second, s2.pop();
            s2.push(data[i].second);
        }

        vector<vector<bool>> dp(n, vector<bool>(2, false));
        dp[n - 1][0] = dp[n - 1][1] = true;
        for(int i = n - 2; i >= 0; i --){
            if(larger[i] != -1)
                dp[i][0] = dp[larger[i]][1];
            if(smaller[i] != -1)
                dp[i][1] = dp[smaller[i]][0];
        }

        int res = 0;
        for(int i = 0; i < n; i ++)
            res += dp[i][0];
        return res;
    }
};


int main() {

    vector<int> A1 = {10,13,12,14,15};
    cout << Solution().oddEvenJumps(A1) << endl;
    // 2

    vector<int> A2 = {2,3,1,1,4};
    cout << Solution().oddEvenJumps(A2) << endl;
    // 3

    vector<int> A3 = {5,1,3,4,2};
    cout << Solution().oddEvenJumps(A3) << endl;
    // 3

    return 0;
}