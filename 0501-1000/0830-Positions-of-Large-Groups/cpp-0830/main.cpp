/// Source : https://leetcode.com/problems/positions-of-large-groups/
/// Author : liuyubobobo
/// Time   : 2020-01-04

#include <iostream>
#include <vector>

using namespace std;


/// Split
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {

        vector<vector<int>> res;
        for(int start = 0, i = start + 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] != s[start]){

                if(i - start >= 3) res.push_back({start, i - 1});
                start = i;
                i = start;
            }
        return res;
    }
};


int main() {

    return 0;
}
