/// Source : https://leetcode.com/problems/edit-distance/
/// Author : liuyubobobo
/// Time   : 2018-11-23

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Memory Serach
/// Time Complexity: O(len(word1) * len(word2))
/// Space Complexity: O(len(word1) * len(word2))
class Solution {

private:
    map<pair<int, int>, int> dp;

public:
    int minDistance(string word1, string word2) {
        return dfs(word1, word2, 0, 0);
    }

private:
    int dfs(const string& word1, const string& word2, int index1, int index2){

        if(index1 == word1.size())
            return word2.size() - index2;

        if(index2 == word2.size())
            return word1.size() - index1;

        pair<int, int> hash = make_pair(index1, index2);
        if(dp.count(hash))
            return dp[hash];

        int res = INT_MAX;
        if(word1[index1] == word2[index2])
            res = min(res, dfs(word1, word2, index1 + 1, index2 + 1));

        res = min(res, 1 + dfs(word1, word2, index1, index2 + 1));
        res = min(res, 1 + dfs(word1, word2, index1 + 1, index2));
        res = min(res, 1 + dfs(word1, word2, index1 + 1, index2 + 1));
        return dp[hash] = res;
    }
};


int main() {

    return 0;
}