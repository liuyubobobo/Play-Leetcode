/// Source : https://leetcode.com/problems/naming-a-company/
/// Author : liuyubobobo
/// Time   : 2022-06-11

#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {

        int n = ideas.size();

        unordered_set<string> ideas_set(ideas.begin(), ideas.end());

        vector<vector<bool>> can_change(26, vector<bool>(n, false));
        vector<vector<int>> ok(26, vector<int>(26, 0));
        for(int i = 0; i < n; i ++){
            char o_first = ideas[i][0];
            for(char c = 'a'; c <= 'z'; c ++){
                ideas[i][0] = c;
                if(c != o_first && !ideas_set.count(ideas[i])){
                    can_change[c - 'a'][i] = true;
                    ok[o_first - 'a'][c - 'a'] ++;
                }

            }
            ideas[i][0] = o_first;
        }

        long long res = 0;
        for(int i = 0; i < n; i ++){
            char o_first = ideas[i][0];
            for(char c = 'a'; c <= 'z'; c ++)
                if(can_change[c - 'a'][i]) res += ok[c - 'a'][o_first - 'a'];
        }
        return res;
    }
};


int main() {

    vector<string> ideas1 = {"coffee","donuts","time","toffee"};
    cout << Solution().distinctNames(ideas1) << '\n';
    // 6

    vector<string> ideas2 = {"lack","back"};
    cout << Solution().distinctNames(ideas2) << '\n';
    // 0

    return 0;
}
