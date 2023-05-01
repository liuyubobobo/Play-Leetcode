/// Source : https://leetcode.com/problems/first-completely-painted-row-or-column/description/
/// Author : liuyubobobo
/// Time   : 2023-04-30

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int R = mat.size(), C = mat[0].size();
        vector<pair<int, int>> pos(R * C + 1);
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                pos[mat[i][j]] = {i, j};

        vector<int> rows(R, C), cols(C, R);
        for(int i = 0; i < arr.size(); i ++){
            int r = pos[arr[i]].first, c = pos[arr[i]].second;
            rows[r] --, cols[c] --;
            if(rows[r] == 0 || cols[c] == 0) return i;
        }
        return -1;
    }
};


int main() {




    return 0;
}
