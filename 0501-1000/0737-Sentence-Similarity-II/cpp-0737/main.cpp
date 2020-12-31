/// Source : https://leetcode.com/problems/sentence-similarity-ii/description/
/// Author : liuyubobobo
/// Time   : 2017-11-26

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Using DFS
/// Time Complexity: O(len(words)^2)
/// Space Complexity: O(len(words)^2)
class Solution {

public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2,
                                vector<pair<string, string>> pairs) {

        if(words1.size() != words2.size())
            return false;

        if(words1.size() == 0)
            return true;

        unordered_map<string, int> wordIndex = createWordIndex(pairs);
        vector<unordered_set<int>> g = createGraph(wordIndex, pairs);

        vector<int> flag(wordIndex.size(), -1);
        int index = 0;
        for(int i = 0 ; i < wordIndex.size() ; i ++)
            if(flag[i] == -1)
                dfs(g, i, index ++, flag);

        for(int i = 0 ; i < words1.size() ; i ++){
            if(words1[i] == words2[i])
                continue;

            if(wordIndex.find(words1[i]) == wordIndex.end() ||
                    wordIndex.find(words2[i]) == wordIndex.end())
                return false;

            if(flag[wordIndex[words1[i]]] != flag[wordIndex[words2[i]]])
                return false;
        }

        return true;
    }

private:

    void dfs(const vector<unordered_set<int>>& g, int v, int index,
             vector<int>& flag){

        flag[v] = index;
        for(int w: g[v])
            if(flag[w] == -1)
                dfs(g, w, index, flag);
    }

    vector<unordered_set<int>> createGraph(
            const unordered_map<string, int>& wordIndex,
            const vector<pair<string, string>>& pairs){

        vector<unordered_set<int>> g(wordIndex.size(), unordered_set<int>());
        for(pair<string, string> p: pairs){
            int i1 = wordIndex.at(p.first);
            int i2 = wordIndex.at(p.second);
            g[i1].insert(i2);
            g[i2].insert(i1);
        }

        return g;
    }

    unordered_map<string, int> createWordIndex(const vector<pair<string, string>>& pairs){

        unordered_map<string, int> wordIndex;
        int index = 0;
        for(pair<string, string> p: pairs){
            if(wordIndex.find(p.first) == wordIndex.end())
                wordIndex.insert(make_pair(p.first, index ++));
            if(wordIndex.find(p.second) == wordIndex.end())
                wordIndex.insert(make_pair(p.second, index ++));
        }
        return wordIndex;
    }
};


void printBool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    vector<string> words1_a = {"great", "acting", "skills"};
    vector<string> words2_a = {"fine", "drama", "talent"};

    vector<pair<string, string>> pairs_a;
    pairs_a.push_back(make_pair("great", "good"));
    pairs_a.push_back(make_pair("fine", "good"));
    pairs_a.push_back(make_pair("acting", "drama"));
    pairs_a.push_back(make_pair("skills", "talent"));

    printBool(Solution().areSentencesSimilarTwo(words1_a, words2_a, pairs_a));
    // True

    // ---

    vector<string> words1_b = {"an", "extraordinary", "meal"};
    vector<string> words2_b = {"one", "delicious", "dinner"};

    vector<pair<string, string>> pairs_b;
    pairs_b.push_back(make_pair("great", "good"));
    pairs_b.push_back(make_pair("extraordinary", "good"));
    pairs_b.push_back(make_pair("well", "good"));
    pairs_b.push_back(make_pair("wonderful", "good"));
    pairs_b.push_back(make_pair("excellent", "good"));
    pairs_b.push_back(make_pair("fine", "good"));
    pairs_b.push_back(make_pair("nice", "good"));
    pairs_b.push_back(make_pair("any", "one"));
    pairs_b.push_back(make_pair("some", "one"));
    pairs_b.push_back(make_pair("unique", "one"));
    pairs_b.push_back(make_pair("the", "one"));
    pairs_b.push_back(make_pair("an", "one"));
    pairs_b.push_back(make_pair("single", "one"));
    pairs_b.push_back(make_pair("a", "one"));
    pairs_b.push_back(make_pair("truck", "car"));
    pairs_b.push_back(make_pair("wagon", "car"));
    pairs_b.push_back(make_pair("automobile", "car"));
    pairs_b.push_back(make_pair("auto", "car"));
    pairs_b.push_back(make_pair("vehicle", "car"));
    pairs_b.push_back(make_pair("entertain", "have"));
    pairs_b.push_back(make_pair("drink", "have"));
    pairs_b.push_back(make_pair("eat", "have"));
    pairs_b.push_back(make_pair("take", "have"));
    pairs_b.push_back(make_pair("fruits", "meal"));
    pairs_b.push_back(make_pair("brunch", "meal"));
    pairs_b.push_back(make_pair("breakfast", "meal"));
    pairs_b.push_back(make_pair("food", "meal"));
    pairs_b.push_back(make_pair("dinner", "meal"));
    pairs_b.push_back(make_pair("super", "meal"));
    pairs_b.push_back(make_pair("lunch", "meal"));
    pairs_b.push_back(make_pair("possess", "own"));
    pairs_b.push_back(make_pair("keep", "own"));
    pairs_b.push_back(make_pair("have", "own"));
    pairs_b.push_back(make_pair("extremely", "very"));
    pairs_b.push_back(make_pair("actually", "very"));
    pairs_b.push_back(make_pair("really", "very"));
    pairs_b.push_back(make_pair("super", "very"));

    printBool(Solution().areSentencesSimilarTwo(words1_b, words2_b, pairs_b));
    //False

    return 0;
}