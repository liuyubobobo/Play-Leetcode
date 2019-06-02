/// Source : https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/
/// Author : liuyubobobo
/// Time   : 2019-06-02

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map to record all the patterns
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {

        map<vector<int>, int> flip;
        for(vector<int>& row: matrix){

            if(!row[0])
                flip[row] ++;
            else{
                for(int& c: row)
                    c = 1 - c;
                flip[row] ++;
            }
        }

        int res = 0;
        for(const pair<vector<int>, int>& p: flip)
            res = max(res, p.second);
        return res;
    }
};


int main() {

    vector<vector<int>> matrix1 = {{0, 1}, {1, 1}};
    cout << Solution().maxEqualRowsAfterFlips(matrix1) << endl;

    return 0;
}