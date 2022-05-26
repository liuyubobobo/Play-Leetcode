/// Source : https://leetcode.cn/problems/find-closest-lcci/
/// Author : liuyubobobo
/// Time   : 2022-05-26

#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {

        vector<int> pos1, pos2;
        for(int i = 0; i < words.size(); i ++)
            if(words[i] == word1) pos1.push_back(i);
            else if(words[i] == word2) pos2.push_back(i);

        if(pos2.size() > pos1.size()) swap(pos1, pos2);

        int res = INT_MAX;
        for(int p: pos2){
            auto iter = lower_bound(pos1.begin(), pos1.end(), p);
            if(iter != pos1.end()) res = min(res, *iter - p);
            if(iter != pos1.begin()){
                iter --;
                res = min(res, p - *iter);
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
