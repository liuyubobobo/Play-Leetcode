/// Source : https://leetcode.com/problems/index-pairs-of-a-string/description/
/// Author : liuyubobobo
/// Time   : 2023-04-30

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Brute Force
/// Time Complexity: O(|words|^2 * |text|)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {

        vector<vector<int>> res;
        for(const string& word: words) {
            int pos = 0;
            while(true){
                pos = text.find(word, pos);
                if(pos != string::npos) {
                    res.push_back({pos, pos + (int) word.size() - 1});
                    pos = pos + 1;
                }
                else break;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};


int main() {

    return 0;
}
