/// Source : https://leetcode.com/problems/merge-similar-items/
/// Author : liuyubobobo
/// Time   : 2022-08-10

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map
/// Time Complexity: O(|items1| + |items2|)
/// Space Complexity: O(|items1| + |items2|)
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {

        map<int, int> table;
        for(const vector<int>& item: items1){
            int v = item[0], w = item[1];
            table[v] += w;
        }
        for(const vector<int>& item: items2){
            int v = item[0], w = item[1];
            table[v] += w;
        }

        vector<vector<int>> res;
        for(const pair<int, int>& p: table)
            res.push_back({p.first, p.second});
        return res;
    }
};


int main() {

    return 0;
}
