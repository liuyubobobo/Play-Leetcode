/// Source : https://leetcode.com/problems/diagonal-traverse/description/
/// Author : liuyubobobo
/// Time   : 2018-06-03

#include <iostream>
#include <vector>

using namespace std;

/// Simulation
/// Time Complexity: O(n * m)
/// Space Complexity: O(1)
class Solution {

private:
    int n, m;

public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {

        vector<int> res;

        n = matrix.size();
        if(n == 0)
            return res;
        m = matrix[0].size();

        int x = 0, y = 0;
        int nextX, nextY;
        bool up = true;
        while(true){
            res.push_back(matrix[x][y]);

            if(up)
                nextX = x - 1, nextY = y + 1;
            else
                nextX = x + 1, nextY = y - 1;

            if(inArea(nextX, nextY))
                x = nextX, y = nextY;
            else if(up){
                if(inArea(x, y + 1))
                    y ++;
                else
                    x ++;
                up = false;
            }
            else{
                if(inArea(x + 1, y))
                    x ++;
                else
                    y ++;
                up = true;
            }

            if(!inArea(x, y))
                break;
        }

        return res;
    }

private:
    bool inArea(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
    print_vec(Solution().findDiagonalOrder(matrix));

    return 0;
}