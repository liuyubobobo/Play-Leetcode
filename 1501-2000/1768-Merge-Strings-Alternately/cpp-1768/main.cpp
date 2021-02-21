/// Source : https://leetcode.com/problems/merge-strings-alternately/
/// Author : liuyubobobo
/// Time   : 2021-02-20

#include <iostream>
#include <vector>

using namespace std;


/// Merge
/// Time Complexity: O(|word1| + |word2|)
/// Space Complexity: O(1)
class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int p = 0, q = 0;
        string res = "";
        while(p < word1.size() || q < word2.size()){
            if(p < word1.size()) res += word1[p ++];
            if(q < word2.size()) res += word2[q ++];
        }
        return res;
    }
};


int main() {

    return 0;
}
