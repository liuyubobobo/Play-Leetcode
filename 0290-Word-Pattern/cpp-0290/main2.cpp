/// Source : https://leetcode.com/problems/word-pattern/description/
/// Author : liuyubobobo
/// Time   : 2018-07-03

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


/// HashMap to record the position of each character in pattern and word in str
/// TimeComplexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    bool wordPattern(string pattern, string str) {

        vector<string> words = split(str);
        if(pattern.size() != words.size())
            return false;

        unordered_map<char, int> map1;
        unordered_map<string, int> map2;
        for(int i = 0 ; i < pattern.size() ; i++){
            unordered_map<char, int>::iterator iter1 = map1.find(pattern[i]);
            unordered_map<string, int>::iterator iter2 = map2.find(words[i]);

            int i1 = (iter1 == map1.end() ? -1 : map1[pattern[i]]);
            int i2 = (iter2 == map2.end() ? -1 : map2[words[i]]);

            if(i1 != i2)
                return false;

            map1[pattern[i]] = i;
            map2[words[i]] = i;
        }

        return true;
    }

private:
    vector<string> split(const string& s){

        vector<string> res;
        int start = 0;
        for(int i = start + 1 ; i <= s.size() ; )
            if(i == s.size() || s[i] == ' '){
                res.push_back(s.substr(start, i - start));
                start = i + 1;
                i = start + 1;
            }
            else
                i ++;
        return res;
    }
};


void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    string pattern1 = "abba";
    string str1 = "dog cat cat dog";
    print_bool(Solution().wordPattern(pattern1, str1));

    string pattern2 = "abba";
    string str2 = "dog cat cat fish";
    print_bool(Solution().wordPattern(pattern2, str2));

    string pattern3 = "aaaa";
    string str3 = "dog cat cat dog";
    print_bool(Solution().wordPattern(pattern3, str3));

    string pattern4 = "abba";
    string str4 = "dog dog dog dog";
    print_bool(Solution().wordPattern(pattern4, str4));

    return 0;
}