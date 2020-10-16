/// Source : https://leetcode.com/problems/lonely-pixel-ii/
/// Author : liuyubobobo
/// Time   : 2020-10-16

#include <iostream>
#include <vector>

using namespace std;


/// Pre-calculate row's equality
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {

        int R = picture.size(), C = picture[0].size();
        vector<int> rows(R, 0), cols(C, 0);
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(picture[i][j] == 'B') rows[i] ++, cols[j] ++;

        vector<vector<bool>> same(R, vector<bool>(R, false));
        for(int i = 0; i < R; i ++)
            for(int j = i; j < R; j ++)
                if(picture[i] == picture[j]) same[i][j] = same[j][i] = true;

        int res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(ok(picture, i, j, N, rows, cols, same)) res ++;
        return res;
    }

private:
    bool ok(const vector<vector<char>>& picture, int x, int y, int N,
            const vector<int>& rows, const vector<int>& cols, vector<vector<bool>>& same){

        if(picture[x][y] != 'B' ) return false;
        if(rows[x] != N) return false;
        if(cols[y] != N) return false;

        for(int i = 0; i < picture.size(); i ++)
            if(picture[i][y] == 'B' && !same[i][x]) return false;
        return true;
    }
};


int main() {

    return 0;
}
