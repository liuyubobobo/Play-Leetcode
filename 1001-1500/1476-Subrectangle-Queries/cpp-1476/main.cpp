/// Source : https://leetcode.com/problems/subrectangle-queries/
/// Author : liuyubobobo
/// Time   : 2020-06-13

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: init: O(n^2)
///                  update: (O(n^2))
///                  get: O(1)
/// Space Complexity: O(n^2)
class SubrectangleQueries {

private:
    vector<vector<int>> rec;

public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : rec(rectangle) {}

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {

        for(int i = row1; i <= row2; i ++)
            for(int j = col1; j <= col2; j ++)
                rec[i][j] = newValue;
    }

    int getValue(int row, int col) {
        return rec[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */


int main() {

    return 0;
}
