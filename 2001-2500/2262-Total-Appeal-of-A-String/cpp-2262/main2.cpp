/// Source : https://leetcode.com/problems/total-appeal-of-a-string/
/// Author : liuyubobobo
/// Time   : 2022-05-03

#include <iostream>
#include <vector>

using namespace std;


/// Two Pointers
/// Time Complexity: O(n)
/// Space Compelxity: O(n)
class Solution {
public:
    long long appealSum(string s) {

        int n = s.size();

        vector<vector<int>> pos(26);
        for(int i = 0; i < n; i ++)
            pos[s[i] - 'a'].push_back(i);

        long long res = 0;
        for(int ch = 0; ch < 26; ch ++){
            vector<int>& v = pos[ch];
            int index = 0;
            for(int l = 0; l < n && index < v.size(); l ++){
                res += n - v[index];
                if(v[index] == l) index ++;
            }
        }
        return res;
    }
};


int main() {

    cout << Solution().appealSum("abbca") << '\n';
    // 28

    cout << Solution().appealSum("code") << '\n';
    // 20

    return 0;
}
