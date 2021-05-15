/// Source : https://leetcode.com/problems/sorting-the-sentence/
/// Author : liuyubobobo
/// Time   : 2021-05-15

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string sortSentence(string s) {

        vector<string> v;
        for(int start = 0, i = 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] == ' '){
                v.push_back(s.substr(start, i - start));

                start = i + 1;
                i = start;
            }

        sort(v.begin(), v.end(), [](const string& a, const string& b){
            return a.back() < b.back();
        });

        string res = "";
        for(const string& e: v){
            res += e;
            res.pop_back();
            res += " ";
        }
        res.pop_back();
        return res;
    }
};


int main() {

    return 0;
}
