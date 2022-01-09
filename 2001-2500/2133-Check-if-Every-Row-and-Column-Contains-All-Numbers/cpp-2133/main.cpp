/// Source : https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/
/// Author : liuyubobobo
/// Time   : 2022-01-08

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {

        int n = matrix.size();
        for(int i = 0; i < n; i ++){
            vector<bool> ok(n + 1, false);
            for(int j = 0; j < n; j ++)
                ok[matrix[i][j]] = true;
            for(int k = 1; k <= n; k ++)
                if(!ok[k]) return false;
        }

        for(int j = 0; j < n; j ++){
            vector<bool> ok(n + 1, false);
            for(int i = 0; i < n; i ++)
                ok[matrix[i][j]] = true;
            for(int k = 1; k <= n; k ++)
                if(!ok[k]) return false;
        }

        return true;
    }
};


int main() {

    return 0;
}
