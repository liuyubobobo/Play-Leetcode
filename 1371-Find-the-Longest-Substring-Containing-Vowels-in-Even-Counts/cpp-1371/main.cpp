/// Source : https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
/// Author : liuyubobobo
/// Time   : 2020-03-14
/// Updated: 2020-05-05

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


/// State Compression
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int findTheLongestSubstring(string s) {

        unordered_map<char, int> vowels = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};

        int state = 0;
        vector<int> pos(1 << 5, -1);
        vector<bool> visited(1 << 5, false);
        visited[0] = true;
        int res = 0;
        for(int i = 0; i < s.size(); i ++){
            if(vowels.count(s[i])) {
                if(state & (1 << vowels[s[i]])) state -= (1 << vowels[s[i]]);
                else state += (1 << vowels[s[i]]);
            }
            if(visited[state]) res = max(res, i - pos[state]);
            else pos[state] = i, visited[state] = true;
        }
        return res;
    }
};


int main() {

    cout << Solution().findTheLongestSubstring("leetcodeisgreat") << endl;
    // 5

    return 0;
}
