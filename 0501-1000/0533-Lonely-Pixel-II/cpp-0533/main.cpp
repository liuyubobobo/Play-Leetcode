/// Source : https://leetcode.com/problems/lonely-pixel-ii/
/// Author : liuyubobobo
/// Time   : 2020-10-16

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^4)
/// Space Complexity: O(n)
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {

        int R = picture.size(), C = picture[0].size();
        vector<int> rows(R, 0), cols(C, 0);
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(picture[i][j] == 'B') rows[i] ++, cols[j] ++;

        int res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(ok(picture, i, j, rows, cols, N)) res ++;
        return res;
    }

private:
    bool ok(const vector<vector<char>>& picture, int x, int y,
            const vector<int>& rows, const vector<int>& cols, int N){

        if(picture[x][y] != 'B' ) return false;
        if(rows[x] != N) return false;
        if(cols[y] != N) return false;

        for(int i = 0; i < picture.size(); i ++)
            if(picture[i][y] == 'B' && picture[i] != picture[x]) return false;
        return true;
    }
};


int main() {

    return 0;
}
