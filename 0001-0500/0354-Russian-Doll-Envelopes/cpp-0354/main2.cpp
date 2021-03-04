/// Source : https://leetcode.com/problems/russian-doll-envelopes/
/// Author : liuyubobobo
/// Time   : 2021-03-03

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// LIS - O(nlogn)
/// How to sort the two dimensional data is the key!
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        if(envelopes.empty()) return 0;

        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& e1, const vector<int>& e2){

            if(e1[0] != e2[0]) return e1[0] < e2[0];
            return e1[1] > e2[1];
        });

        vector<int> v(envelopes.size());
        for(int i = 0; i < envelopes.size(); i ++)
            v[i] = envelopes[i][1];

        return lis(v);
    }

private:
    int lis(const vector<int>& v){

        vector<int> dp;
        for(int e: v){
            if(dp.empty() || e > dp.back())
                dp.push_back(e);
            else{
                vector<int>::iterator iter = lower_bound(dp.begin(), dp.end(), e);
                if(iter != dp.end()) dp[iter - dp.begin()] = e;
            }
        }
        return dp.size();
    }
};


int main() {

    vector<vector<int>> envelopes1 = {
            {5,4},{6,4},{6,7},{2,3}
    };
    cout << Solution().maxEnvelopes(envelopes1) << endl;
    // 3

    vector<vector<int>> envelopes2 = {
            {1,3},{3,5},{6,7},{6,8},{8,4},{9,5}
    };
    cout << Solution().maxEnvelopes(envelopes2) << endl;
    // 3

    vector<vector<int>> envelopes3 = {
            {1,2},{2,3},{3,4},{3,5},{4,5},{5,5},{5,6},{6,7},{7,8}
    };
    cout << Solution().maxEnvelopes(envelopes3) << endl;
    // 7

    return 0;
}
