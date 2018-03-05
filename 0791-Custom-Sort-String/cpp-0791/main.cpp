/// Source : https://leetcode.com/problems/custom-sort-string/description/
/// Author : liuyubobobo
/// Time   : 2018-02-24

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


/// Count and write
/// Time Complexity: O(len(S) + len(T))
/// Space Complexity: O(len(T))
class Solution {
public:
    string customSortString(string S, string T) {

        unordered_map<char, int> freq;
        for(char c: T)
            freq[c] ++;

        string res = "";
        for(char c: S){
            int f = freq[c];
            if(f)
                for(int i = 0 ; i < f ; i ++)
                    res += c;
            freq.erase(c);
        }

        for(const pair<char, int>& p: freq){
            int f = p.second;
            if(f)
                for(int i = 0 ; i < f ; i ++)
                    res += p.first;
        }

        return res;
    }
};

int main() {

    cout << Solution().customSortString("cba", "abcd") << endl;

    return 0;
}