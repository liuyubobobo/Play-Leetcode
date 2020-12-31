/// Source : https://leetcode.com/problems/top-k-frequent-words/description/
/// Author : liuyubobobo
/// Time   : 2017-11-05

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cassert>

using namespace std;

/// Sort
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)

class Solution {

private:
    unordered_map<string, int> freq;

public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        freq.clear();
        for(string word: words)
            if(freq.find(word) != freq.end())
                freq[word] ++;
            else
                freq[word] = 1;
        assert(k <= freq.size());

        vector<string> res;
        for(pair<string, int> e: freq)
            res.push_back(e.first);

        sort(res.begin(), res.end(), [this](const string &a, const string &b){
            if(this->freq[a] != this->freq[b])
                return this->freq[a] > this->freq[b];
            return a < b;
        });

        return vector<string>(res.begin(), res.begin() + k);
    }
};


void printVec(const vector<string>& vec){
    for(string str: vec)
        cout << str << " ";
    cout << endl;
}

int main() {

    int k1 = 2;
    vector<string> vec1;
    vec1.push_back("i");
    vec1.push_back("love");
    vec1.push_back("leetcode");
    vec1.push_back("i");
    vec1.push_back("love");
    vec1.push_back("coding");
    printVec(Solution().topKFrequent(vec1, k1));
    // i love

    // ---

    int k2 = 4;
    vector<string> vec2;
    vec2.push_back("the");
    vec2.push_back("day");
    vec2.push_back("is");
    vec2.push_back("sunny");
    vec2.push_back("the");
    vec2.push_back("the");
    vec2.push_back("the");
    vec2.push_back("sunny");
    vec2.push_back("is");
    vec2.push_back("is");
    printVec(Solution().topKFrequent(vec2, k2));
    // the is sunny day

    // ---

    int k3 = 1;
    vector<string> vec3;
    vec3.push_back("i");
    vec3.push_back("love");
    vec3.push_back("leetcode");
    vec3.push_back("i");
    vec3.push_back("love");
    vec3.push_back("coding");
    printVec(Solution().topKFrequent(vec3, k3));
    // i

    return 0;
}