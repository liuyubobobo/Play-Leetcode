/// Source : https://leetcode.com/problems/image-overlap/
/// Author : liuyubobobo
/// Time   : 2022-10-26

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^4)
/// Space Complexity: O(n^2)
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        int n = img1.size();
        int m = n * 3;

        vector<vector<int>> back(m, vector<int>(m, 0));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++) back[i + n][j + n] = img1[i][j];

        int res = 0;
        for(int i = 0; i + n <= m; i ++)
            for(int j = 0; j + n <= m; j ++)
                res = max(res, match(back, i, j, img2, n));
        return res;
    }

private:
    int match(const vector<vector<int>>& back, int sx, int sy,
              const vector<vector<int>>& img, int n){

        int res = 0;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                res += (img[i][j] && back[i + sx][j + sy]);
        return res;
    }
};


int main() {

    return 0;
}
