/// Source : https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/
/// Author : liuyubobobo
/// Time   : 2019-10-26

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(1000 * 1000)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {

        vector<vector<int>> res;
        for(int x = 1; x <= 1000; x ++)
            for(int y = 1; y <= 1000; y ++)
                if(customfunction.f(x, y) == z) res.push_back({x, y});
        return res;
    }
};


int main() {

    return 0;
}