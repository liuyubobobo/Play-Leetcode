/// Source : https://leetcode.com/problems/convert-1d-array-into-2d-array/
/// Author : liuyubobobo
/// Time   : 2021-10-02

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(m * n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

        if(original.size() != m * n) return {};

        vector<vector<int>> res(m, vector<int>(n));
        for(int i = 0; i < original.size(); i ++)
            res[i / n][i % n] = original[i];
        return res;
    }
};


int main() {

    return 0;
}
