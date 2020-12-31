/// Source : https://leetcode.com/problems/lonely-pixel-i/
/// Author : liuyubobobo
/// Time   : 2020-10-16

#include <iostream>
#include <vector>

using namespace std;


/// Two Passes
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {

        int R = picture.size(), C = picture[0].size();
        vector<int> rows(R, 0), cols(C, 0);
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(picture[i][j] == 'B') rows[i] ++, cols[j] ++;

        int res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(picture[i][j] == 'B' && rows[i] == 1 && cols[j] == 1)
                    res ++;
        return res;
    }
};


int main() {

    return 0;
}
