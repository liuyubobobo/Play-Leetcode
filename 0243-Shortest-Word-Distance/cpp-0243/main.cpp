/// Source : https://leetcode.com/problems/shortest-word-distance/
/// Author : liuyubobobo
/// Time   : 2019-02-13

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Compelxity: O(1)
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {

        int last_index = -1, last_tag = 0, res = INT_MAX;
        for(int i = 0; i < words.size(); i ++){
            int cur_tag = 0;
            if(words[i] == word1) cur_tag = 1;
            else if(words[i] == word2) cur_tag = 2;

            if(last_tag && cur_tag && cur_tag != last_tag)
                res = min(res, i - last_index);

            if(cur_tag)
                last_index = i, last_tag = cur_tag;
        }

        return res;
    }
};


int main() {

    return 0;
}