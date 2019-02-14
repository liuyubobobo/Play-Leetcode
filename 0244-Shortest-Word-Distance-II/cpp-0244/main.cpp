/// Source : https://leetcode.com/problems/shortest-word-distance-ii/
/// Author : liuyubobobo
/// Time   : 2019-02-13

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Search in two sorted index array
/// Time Complexity: init: O(n)
///                  search: O(n)
/// Space Complexity: O(n)
class WordDistance {

private:
    unordered_map<string, vector<int>> pos;

public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); i++)
            pos[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {

        vector<int>& vec1 = pos[word1];
        vector<int>& vec2 = pos[word2];

        int i1 = 0, i2 = 0;
        int res = abs(vec1[i1] - vec2[i2]);
        while(i1 < vec1.size() && i2 < vec2.size()){
            res = min(res, abs(vec1[i1] - vec2[i2]));
            if(vec1[i1] < vec2[i2]) i1 ++;
            else i2 ++;
        }

        return res;
    }
};


int main() {

    return 0;
}