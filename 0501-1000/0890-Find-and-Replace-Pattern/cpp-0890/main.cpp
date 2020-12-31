/// Source : https://leetcode.com/problems/find-and-replace-pattern/
/// Author : liuyubobobo
/// Time   : 2018-08-18

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Two Maps
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

        vector<string> res;
        for(const string& word: words)
            if(ok(word, pattern))
                res.push_back(word);
        return res;
    }

private:
    bool ok(const string& word, const string& pattern){

        if(word.size() != pattern.size())
            return false;

        unordered_map<char, char> match, rmatch;
        for(int i = 0; i < word.size(); i ++)
            if(match.find(word[i]) == match.end()){
                if(rmatch.find(pattern[i]) != rmatch.end())
                    return false;

                match[word[i]] = pattern[i];
                rmatch[pattern[i]] = word[i];
            }
            else{
                if(match[word[i]] != pattern[i])
                    return false;
                if(rmatch.find(pattern[i]) == rmatch.end() ||
                        rmatch[pattern[i]] != word[i])
                    return false;
            }

        return true;
    }
};


void print_vec(const vector<string>& vec){
    for(const string& e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<string> words1 = {"abc","deq","mee","aqq","dkd","ccc"};
    print_vec(Solution().findAndReplacePattern(words1, "abb"));

    return 0;
}