/// Source : https://leetcode.com/problems/find-smallest-common-element-in-all-rows/
/// Author : liuyubobobo
/// Time   : 2019-09-21

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Brute Force Count
/// Time Complexity: O(m * n)
/// Space Complexity: O(max(value))
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {

        vector<int> cnt(10001, 0);
        for(int i = 0; i < mat.size(); i ++)
            for(int j = 0; j < mat[i].size(); j ++){
                cnt[mat[i][j]] ++;
                if(cnt[mat[i][j]] == mat.size()) return mat[i][j];
            }
        return -1;
    }
};


int main() {

    return 0;
}