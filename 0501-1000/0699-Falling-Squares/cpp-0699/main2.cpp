/// Source : https://leetcode.com/contest/leetcode-weekly-contest-54/problems/falling-squares/
/// Author : liuyubobobo
/// Time   : 2017-10-28
/// Uopdted: 2022-05-25

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cassert>

using namespace std;


/// Coordinates compression and simulation
/// Time Complexity: O(len(position)^2)
/// Space Complexity: O(len(position))
class Solution {

public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {

        int n = positions.size();
        set<int> unique_pos;
        for(const vector<int>& position: positions){
            unique_pos.insert(position[0]);
            unique_pos.insert(position[0] + position[1] - 1);
        }

        map<int, int> indexes;  // pos -> index
        vector<int> pos;        // index -> pos
        for(int p: unique_pos){
            indexes[p] = pos.size();
            pos.push_back(p);
        }

        assert(indexes.size() == pos.size());
        vector<int> heights(indexes.size(), 0);
        vector<int> res;
        for(const vector<int>& position: positions){

            int startIndex = indexes[position[0]];
            int rightBound = position[0] + position[1] - 1;

            int best = 0;
            for(int i = startIndex ; i < pos.size() && pos[i] <= rightBound ; i ++)
                best = max(best, heights[i]);

            for(int i = startIndex ; i < pos.size() && pos[i] <= rightBound ; i ++)
                heights[i] = best + position[1];

            best = 0;
            for(int i = 0 ; i < heights.size() ; i ++)
                best = max(best, heights[i]);

            res.push_back(best);
        }

        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec) cout << e << ' '; cout << '\n';
}

int main() {

    vector<vector<int>> va = {{1, 2}, {2, 3}, {6, 1}};
    vector<int> res1 = Solution().fallingSquares(va);
    print_vec(res1);

    vector<vector<int>> vb = {{100, 100}, {200, 100}};
    vector<int> res2 = Solution().fallingSquares(vb);
    print_vec(res2);

    return 0;
}