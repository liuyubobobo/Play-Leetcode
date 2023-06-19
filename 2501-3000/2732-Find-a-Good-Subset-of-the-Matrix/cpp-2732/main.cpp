/// Source : https://leetcode.com/problems/find-a-good-subset-of-the-matrix/description/
/// Author : liuyubobobo
/// Time   : 2023-06-19

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n * 2^b)
/// Space Complexity: O(2^b)
class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size(), b = grid[0].size();

        map<int, int> pattern2index;
        for(int i = 0; i < n; i ++){

            int value = 0;
            for(int j = 0; j < b; j ++)
                if(grid[i][j]) value += (1 << j);

            if(value == 0) return {{i}};

            auto iter = pattern2index.find(value);
            if(iter != pattern2index.end()) return {iter->second, i};

            for(int s = 0; s < (1 << b); s ++)
                if((s & value) == 0) pattern2index[s] = i;
        }
        return {};
    }
};


int main() {

    return 0;
}
