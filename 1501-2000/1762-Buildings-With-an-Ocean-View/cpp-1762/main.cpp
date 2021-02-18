/// Source : https://leetcode.com/problems/buildings-with-an-ocean-view/
/// Author : liuyubobobo
/// Time   : 2021-02-18

#include <iostream>
#include <vector>

using namespace std;


/// Mono Stack
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {

        vector<int> res = {(int)heights.size() - 1};
        for(int i = heights.size() - 2; i >= 0; i --)
            if(heights[i] > heights[res.back()]) res.push_back(i);

        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {

    return 0;
}
