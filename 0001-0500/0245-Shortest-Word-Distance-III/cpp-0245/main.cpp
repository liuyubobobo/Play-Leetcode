/// Source : https://leetcode.com/problems/shortest-word-distance-iii/
/// Author : liuyubobobo
/// Time   : 2019-02-14
#include <iostream>
#include <vector>

using namespace std;


/// Same as 243
/// Just deal with when word1 == word2
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {

        if(word1 == word2){
            int last = -1, res = INT_MAX;
            for(int i = 0; i < words.size(); i ++)
                if(words[i] == word1){
                    if(last != -1) res = min(res, i - last);
                    last = i;
                }
            return res;
        }

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