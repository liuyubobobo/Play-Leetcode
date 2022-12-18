/// Source : https://leetcode.com/problems/count-pairs-of-similar-strings/description/
/// Author : liuyubobobo
/// Time   : 2022-12-18

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int similarPairs(vector<string>& words) {

        int n = words.size();
        vector<vector<bool>> f(n, vector<bool>(26, false));
        for(int i = 0; i < n; i ++){
            const string& word = words[i];
            for(char c: word) f[i][c - 'a'] = true;
        }

        int res = 0;
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                res += f[i] == f[j];
        return res;
    }
};


int main() {

    return 0;
}
