/// Source : https://leetcode.com/problems/replace-words/description/
/// Author : liuyubobobo
/// Time   : 2017-11-06

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

/// Hash Set + Brute Force
/// Time Complexity: O(len(words) * O(w)^2)
/// Space Complexity: O(len(dict))
class Solution {
private:
    unordered_set<string> roots;

public:
    string replaceWords(vector<string>& dict, string sentence) {

        for(string root: dict)
            roots.insert(root);

        vector<string> words = split(sentence, ' ');
//        for(string word: words)
//            cout << word << " ";
//        cout << endl;

        vector<string> res;
        for(string word: words)
            res.push_back(getRoot(word));

        return join(res, ' ');
    }

private:
    string getRoot(const string& word){
        for(int i = 1; i <= word.size() ; i ++)
            if(roots.find(word.substr(0, i)) != roots.end())
                return word.substr(0, i);
        return word;
    }

    vector<string> split(const string& s, char delimiter){

        vector<string> res;
        size_t i = 0;
        while(i < s.size()){
            size_t pos = s.find(delimiter, i);
            if(pos == string::npos){
                res.push_back(s.substr(i));
                break;
            }
            else{
                res.push_back(s.substr(i, pos-i));
                i = pos + 1;
            }
        }
        return res;
    }

    string join(const vector<string>& vec, char delimiter){

        if(vec.size() == 0)
            return "";

        string ret = vec[0];
        for(int i = 1 ; i < vec.size() ; i ++)
            ret += (delimiter + vec[i]);
        return ret;
    }
};

int main() {

    vector<string> dict;
    dict.push_back("cat");
    dict.push_back("bat");
    dict.push_back("rat");

    string sentence = "the cattle was rattled by the battery";

    cout << Solution().replaceWords(dict, sentence) << endl;

    return 0;
}