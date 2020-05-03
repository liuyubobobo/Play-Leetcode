/// Source : https://leetcode.com/problems/destination-city/
/// Author : liuyubobobo
/// Time   : 2020-05-03

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


/// Calculate outdegree
/// Time Complexity:O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {

        unordered_map<string, int> g;
        for(vector<string>& path: paths)
            g[path[0]] ++, g[path[1]];

        for(const pair<string, int>& p: g)
            if(p.second == 0) return p.first;
        return "";
    }
};


int main() {

    return 0;
}
