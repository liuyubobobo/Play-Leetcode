/// Source : https://leetcode.com/problems/sentence-similarity/solution/
/// Author : liuyubobobo
/// Time   : 2017-11-25

#include <iostream>
#include <vector>
#include <set>

using namespace std;

/// Using Set
/// Saving Pairs
/// Time Complexity: O(len(pairs) + len(s))
/// Space Complexity: O(len(pairs))
class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>> pairs) {

        if(words1.size() != words2.size())
            return false;

        if(words1.size() == 0)
            return true;

        set<pair<string, string>> similarity;
        for(const vector<string>& p: pairs) {
            similarity.insert(make_pair(p[0], p[1]));
            similarity.insert(make_pair(p[1], p[0]));
        }

        for(int i = 0 ; i < words1.size() ; i ++)
            if(words1[i] != words2[i] && similarity.find(make_pair(words1[i], words2[i])) == similarity.end())
                return false;

        return true;
    }
};


void printBool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    vector<string> words1 = {"great", "acting", "skills"};
    vector<string> words2 = {"fine", "drama", "talent"};

    vector<pair<string, string>> pairs;
    pairs.push_back(make_pair("great", "fine"));
    pairs.push_back(make_pair("acting", "drama"));
    pairs.push_back(make_pair("skills", "talent"));

    printBool(Solution().areSentencesSimilar(words1, words2, pairs));

    return 0;
}