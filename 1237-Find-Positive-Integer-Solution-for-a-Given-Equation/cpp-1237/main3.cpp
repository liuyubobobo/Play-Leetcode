/// Source : https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/
/// Author : liuyubobobo
/// Time   : 2019-11-03

#include <iostream>
#include <vector>

using namespace std;


/// Two Pointers
/// Time Complexity: O(1000)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {

        vector<vector<int>> res;
        for(int x = 1, y = 1000; x <= 1000 && y >= 1;){
            int v = customfunction.f(x, y);
            if(v == z) res.push_back({x ++, y --};
            else if(v < z) y --;
            else x ++;
        }
        return res;
    }
};


int main() {

    return 0;
}