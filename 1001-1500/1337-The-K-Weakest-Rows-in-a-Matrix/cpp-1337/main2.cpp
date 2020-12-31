/// Source : https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
/// Author : liuyubobobo
/// Time   : 2020-02-10

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Scan column by column
/// Time Complexity: O(m * n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        for(int i = 0; i < mat.size(); i ++)
            mat[i].push_back(0);

        vector<int> res;
        vector<bool> visited(mat.size(), false);
        for(int j = 0; j < mat[0].size(); j ++)
            for(int i = 0; i < mat.size(); i ++)
                if(!mat[i][j] && !visited[i]){
                    res.push_back(i), visited[i] = true;
                    if(res.size() == k) return res;
                }
        return res;
    }
};


int main() {

    return 0;
}
