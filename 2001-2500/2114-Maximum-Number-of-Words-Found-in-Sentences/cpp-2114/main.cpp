/// Source : https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
/// Author : liuyubobobo
/// Time   : 2021-08-02

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Compelxity: O(1)
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {

        int res = 0;
        for(const string& s: sentences)
            res = max(res, count_words(s));
        return res;
    }

private:
    int count_words(const string& s){

        int res = 0;
        for(int start = 0, i = 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] == ' '){
                res ++;
                start = i + 1;
                i = start;
            }
        return res;
    }
};


int main() {

    return 0;
}
