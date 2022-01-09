/// Source : https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/
/// Author : liuyubobobo
/// Time   : 2022-01-08

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Map, Using Bitwise
/// Time Complexity: O(|startWords| + |targetWords|)
/// Space Complexity: O(|targetWords|)
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {

        unordered_map<int, int> target_map;
        for(string word: targetWords){
            int state = 0;
            for(char c: word) state |= (1 << (c - 'a'));
            target_map[state] ++;
        }

        int res = 0;
        for(const string& word: startWords){
            int state = 0;
            for(char c: word) state |= (1 << (c - 'a'));
            for(int i = 0; i < 26; i ++)
                if((state & (1 << i)) == 0){
                    auto iter = target_map.find(state | (1 << i));
                    if(iter != target_map.end()){
                        res += iter->second;
                        target_map.erase(iter);
                    }
                }
        }
        return res;
    }
};


int main() {

    vector<string> startWords1 = {"ant","act","tack"};
    vector<string> targetWords1 = {"tack","act","acti"};
    cout << Solution().wordCount(startWords1, targetWords1) << endl;
    // 2

    vector<string> startWords2 = {"ab","a"};
    vector<string> targetWords2 = {"abc","abcd"};
    cout << Solution().wordCount(startWords2, targetWords2) << endl;
    // 1

    return 0;
}
