/// Source : https://leetcode.com/problems/finding-the-users-active-minutes/
/// Author : liuyubobobo
/// Time   : 2021-04-03

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/// Using HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {

        unordered_map<int, unordered_set<int>> f;
        for(const vector<int>& v: logs)
            f[v[0]].insert(v[1]);

        vector<int> res(k, 0);
        for(const pair<int, unordered_set<int>>& p: f){
            if(p.second.size() - 1 < res.size())
                res[p.second.size() - 1] ++;
        }
        return res;
    }
};


int main() {

    return 0;
}
