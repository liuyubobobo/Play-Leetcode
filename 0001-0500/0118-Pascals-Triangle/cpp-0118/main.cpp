/// Source : https://leetcode.com/problems/pascals-triangle/description/
/// Author : liuyubobobo
/// Time   : 2018-06-03

#include <iostream>
#include <vector>

using namespace std;


/// Simulation (Dynamic Programming)
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> res;
        if(numRows <= 0)
            return res;

        res.push_back({1});
        for(int i = 1 ; i < numRows ; i ++){
            vector<int> row;
            row.push_back(1);
            for(int j = 1 ; j < i ; j ++)
                row.push_back(res[i-1][j-1] + res[i-1][j]);
            row.push_back(1);
            res.push_back(row);
        }
        return res;
    }
};

int main() {

    return 0;
}