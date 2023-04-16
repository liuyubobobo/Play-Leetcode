/// Source : https://leetcode.com/problems/row-with-maximum-ones/description/
/// Author : liuyubobobo
/// Time   : 2023-04-15

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int max_ones = -1, res = -1;
        for(int i = 0; i < mat.size(); i ++){
            int ones = count(mat[i].begin(), mat[i].end(), 1);
            if(ones > max_ones) max_ones = ones, res = i;
        }
        return {res, max_ones};
    }
};


int main() {

    return 0;
}
