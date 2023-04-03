/// Source : https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/description/
/// Author : liuyubobobo
/// Time   : 2023-04-02

#include <iostream>
#include <vector>

using namespace std;


/// String split
/// Time Complexity: O(n)
/// Space Compelxity: O(n)
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {

        int n = s.size();

        vector<pair<int, int>> segs;
        for(int start = 0, i = 1; i <= n; i ++){
            if(i == n || s[i] != s[start]){
                segs.push_back({s[start] - '0', i - start});
                start = i;
            }
        }

        int res = 0;
        for(int i = 0; i + 1 < (int)segs.size(); i ++)
            if(segs[i].first == 0 && segs[i + 1].first == 1)
                res = max(res, 2 * min(segs[i].second, segs[i + 1].second));
        return res;
    }
};


int main() {

    return 0;
}
