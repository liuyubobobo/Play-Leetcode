/// Source : https://leetcode.com/problems/destination-city/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


/// Graph Construction
/// Time Complexity:O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {

        unordered_map<string, vector<string>> g;
        for(vector<string>& path: paths)
            g[path[0]].push_back(path[1]), g[path[1]];

        for(const pair<string, vector<string>>& p: g)
            if(p.second.size() == 0) return p.first;
        return "";
    }
};


int main() {

    return 0;
}
