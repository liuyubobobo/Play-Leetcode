/// Source : https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
/// Author : liuyubobobo
/// Time   : 2022-08-11

#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;


/// Using Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {

        map<int, vector<int>> groups;
        for(int i = 0; i < groupSizes.size(); i ++)
            groups[groupSizes[i]].push_back(i);

        vector<vector<int>> res;
        for(const pair<int, vector<int>>& p: groups){
            int sz = p.first;
            const vector<int>& v = p.second;
            assert(v.size() % sz == 0);

            for(int i = 0; i < v.size(); i += sz)
                res.push_back(vector<int>(v.begin() + i, v.begin() + i + sz));
        }
        return res;
    }
};


int main() {

    return 0;
}
