/// Source : https://leetcode.com/problems/color-the-triangle-red/description/
/// Author : liuyubobobo
/// Time   : 2023-05-02

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> colorRed(int n) {

        vector<vector<int>> res;
        for(int i = n; i >= 1; i -= 4){
            if(i < 4){
                res.push_back({1, 1});
                for(int j = 2; j <= i; j ++) res.push_back({j, 1}), res.push_back({j, 2 * j - 1});
            }
            else{
                for(int j = 1; j <= 2 * i - 1; j += 2) res.push_back({i, j});
                res.push_back({i - 1, 2});
                for(int j = 3; j <= 2 * (i - 2) - 1; j += 2) res.push_back({i - 2, j});
                res.push_back({i - 3, 1});
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
