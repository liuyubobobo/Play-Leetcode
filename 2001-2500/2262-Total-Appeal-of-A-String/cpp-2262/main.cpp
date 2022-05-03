/// Source : https://leetcode.com/problems/total-appeal-of-a-string/
/// Author : liuyubobobo
/// Time   : 2022-04-30

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
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
            for(int l = 0; l < n; l ++){
                auto iter = lower_bound(v.begin(), v.end(), l);
                if(iter != v.end())
                    res += n - *iter;
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
