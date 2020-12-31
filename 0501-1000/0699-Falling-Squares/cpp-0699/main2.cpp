/// Source : https://leetcode.com/contest/leetcode-weekly-contest-54/problems/falling-squares/
/// Author : liuyubobobo
/// Time   : 2017-10-28

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
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {

        int n = positions.size();
        set<int> unique_pos;
        for(pair<int, int> position: positions){
            unique_pos.insert(position.first);
            unique_pos.insert(position.first + position.second - 1);
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
        for(pair<int, int> position: positions){

            int startIndex = indexes[position.first];
            int rightBound = position.first + position.second - 1;

            int best = 0;
            for(int i = startIndex ; i < pos.size() && pos[i] <= rightBound ; i ++)
                best = max(best, heights[i]);

            for(int i = startIndex ; i < pos.size() && pos[i] <= rightBound ; i ++)
                heights[i] = best + position.second;

            best = 0;
            for(int i = 0 ; i < heights.size() ; i ++)
                best = max(best, heights[i]);

            res.push_back(best);
        }

        return res;
    }

};


void printVec(const vector<int>& vec){

    for(int i = 0 ; i < vec.size() ; i ++)
        cout << vec[i] << ((i == vec.size() - 1) ? '\n' : ' ');
}


int main() {

    vector<pair<int, int>> va;
    va.push_back(make_pair(1, 2));
    va.push_back(make_pair(2, 3));
    va.push_back(make_pair(6, 1));
    vector<int> res1 = Solution().fallingSquares(va);
    printVec(res1);


    vector<pair<int, int>> vb;
    vb.push_back(make_pair(100, 100));
    vb.push_back(make_pair(200, 100));
    vector<int> res2 = Solution().fallingSquares(vb);
    printVec(res2);

    return 0;
}