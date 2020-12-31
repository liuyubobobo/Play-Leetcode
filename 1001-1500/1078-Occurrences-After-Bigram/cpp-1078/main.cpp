/// Source : https://leetcode.com/problems/occurrences-after-bigram/
/// Author : liuyubobobo
/// Time   : 2019-06-08

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan and split
/// Time Complexity: O(|text|)
/// Space Complexity: O(|text|)
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {

        vector<string> res;
        vector<string> v;
        for(int start = 0, i = start + 1; i <= text.size(); i ++)
            if(i == text.size() || text[i] == ' '){
                string word = text.substr(start, i - start);
                if(v.size() >= 2 && v[v.size() - 2] == first && v[v.size() - 1] == second)
                    res.push_back(word);
                v.push_back(word);

                start = i;
                i = start;
            }
        return res;
    }
};


int main() {

    return 0;
}