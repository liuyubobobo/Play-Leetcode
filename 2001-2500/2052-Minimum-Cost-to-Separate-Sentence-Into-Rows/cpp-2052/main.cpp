/// Source : https://leetcode.com/problems/minimum-cost-to-separate-sentence-into-rows/
/// Author : liuyubobobo
/// Time   : 2021-10-29

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int minimumCost(string sentence, int k) {

        vector<int> v;
        for(int start = 0, i = 1; i <= sentence.size(); i ++){
            if(i == sentence.size() || sentence[i] == ' '){
                v.push_back(i - start);
                start = i + 1;
                i = start;
            }
        }

        int last = v.size() - 1;
        int cur = v.back();
        for(int i = (int)v.size() - 2; i >= 0; i --)
            if(cur + 1 + v[i] <= k){
                last = i;
                cur += 1 + v[i];
            }
            else break;

        vector<int> dp(v.size(), -1);
        return dfs(v, 0, k, last, dp);
    }

private:
    int dfs(const vector<int>& v, int index, int k, int last, vector<int>& dp){

        if(index >= last) return 0;
        if(dp[index] != -1) return dp[index];

        int cur = v[index];
        int res = (cur - k) * (cur - k) + dfs(v, index + 1, k, last, dp);
        for(int i = index + 1; i < v.size(); i ++)
            if(cur + 1 + v[i] <= k){
                if(i + 1 == v.size()) return 0;
                cur += (1 + v[i]);
                res = min(res, (cur - k) * (cur - k) + dfs(v, i + 1, k, last, dp));
            }
            else break;
        return dp[index] = res;
    }
};


int main() {

    string s1 = "a";
    while(s1.size() + 2 < 5000) s1 += " a";
    cout << Solution().minimumCost(s1, 5000) << endl;
    //

    return 0;
}
