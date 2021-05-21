/// Source : https://leetcode.com/problems/chalkboard-xor-game/
/// Author : liuyubobobo
/// Time   : 2021-05-21

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool xorGame(vector<int>& nums) {

        if(nums.size() % 2 == 0) return true;

        int x = 0;
        for(int e: nums) x ^= e;
        return x == 0;
    }
};


int main() {

    return 0;
}
