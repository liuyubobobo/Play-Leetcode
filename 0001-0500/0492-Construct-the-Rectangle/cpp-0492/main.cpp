/// Source : https://leetcode.com/problems/construct-the-rectangle/
/// Author : liuyubobobo
/// Time   : 2021-10-22

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Greedy
/// Time Complexity: O(sqrt(area))
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> constructRectangle(int area) {

        for(int i = (int)(sqrt(area) + 1e-6); i >= 1; i --){
            if(area % i == 0) return {area / i, i};
        }
        assert(false);
        return {-1, -1};
    }
};


int main() {

    return 0;
}
