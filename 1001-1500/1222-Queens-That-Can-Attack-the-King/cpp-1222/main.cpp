/// Source : https://leetcode.com/problems/queens-that-can-attack-the-king/
/// Author : liuyubobobo
/// Time   : 2019-10-12

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using Set
/// Time Complexity: O(64)
/// Space Complexity: O(queens)
class Solution {

private:
    const int dirs[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},
                            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {

        vector<vector<int>> res;
        set<vector<int>> set(queens.begin(), queens.end());
        for(int d = 0; d < 8; d ++){
            int x = king[0], y = king[1];
            for(int l = 1; l <= 8; l ++){
                if(set.count({x + l * dirs[d][0], y + l * dirs[d][1]})){
                    res.push_back({x + l * dirs[d][0], y + l * dirs[d][1]});
                    break;
                }
            }
        }
        return res;
    }
};


int main() {

    return 0;
}