/// Source : https://leetcode.com/problems/odd-string-difference/
/// Author : liuyubobobo
/// Time   : 2022-10-30

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map
/// Time Complexity: O(|words| * len)
/// Space Compelxity: O(|words| * len)
class Solution {
public:
    string oddString(vector<string>& words) {

        map<vector<int>, vector<string>> diff2str;
        for(const string& word: words){
            int n = word.size();
            vector<int> d(n - 1, 0);
            for(int i = 1; i < n; i ++)
                d[i - 1] = word[i] - word[i - 1];
            diff2str[d].push_back(word);
        }

        for(const auto& p: diff2str)
            if(p.second.size() == 1) return p.second[0];
        return "";
    }
};


int main() {

    return 0;
}
