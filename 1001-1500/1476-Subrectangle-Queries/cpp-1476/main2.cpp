/// Source : https://leetcode.com/problems/subrectangle-queries/
/// Author : liuyubobobo
/// Time   : 2020-06-13

#include <iostream>
#include <vector>

using namespace std;


/// Using History
/// Time Complexity: init: O(n^2)
///                  update: (O(1))
///                  get: O(k)
/// Space Complexity: O(n^2)
class SubrectangleQueries {

private:
    vector<vector<int>> rectangle;
    vector<vector<int>> history;

public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : rectangle(rectangle) {}

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        history.push_back({row1, col1, row2, col2, newValue});
    }

    int getValue(int row, int col) {

        for(int i = history.size() - 1; i >= 0; i --)
            if(history[i][0] <= row && row <= history[i][2] &&
               history[i][1] <= col && col <= history[i][3])
                return history[i][4];
        return rectangle[row][col];
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
