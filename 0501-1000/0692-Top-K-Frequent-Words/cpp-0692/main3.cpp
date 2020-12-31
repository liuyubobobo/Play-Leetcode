/// Source : https://leetcode.com/problems/top-k-frequent-words/description/
/// Author : liuyubobobo
/// Time   : 2017-11-04

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

/// Using Priority Quee
/// Time Complexity: O(nlogk)
/// Space Complexity: O(n + k)
class Compare{
public:
    bool operator()(const pair<int, string>& a, const pair<int, string> &b){
        if(a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> freq;
        for(string word: words)
            if(freq.find(word) != freq.end())
                freq[word] ++;
            else
                freq[word] = 1;

        priority_queue<pair<int, string>,
                vector<pair<int, string>>,
                Compare> pq;

        for(unordered_map<string, int>::iterator iter = freq.begin();
            iter != freq.end() ; iter ++){

            pair<int, string> p = make_pair(iter->second, iter->first);
            if(pq.size() < k)
                pq.push(p);
            else if(Compare().operator()(p, pq.top())){
                pq.pop();
                pq.push(p);
            }
        }

        vector<string> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
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