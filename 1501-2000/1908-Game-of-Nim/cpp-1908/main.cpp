/// Source : https://leetcode.com/problems/game-of-nim/
/// Author : liuyubobobo
/// Time   : 2021-06-26

#include <iostream>
#include <vector>

using namespace std;


/// Nim
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool nimGame(vector<int>& piles) {

        int x = 0;
        for(int e: piles) x ^= e;
        return x != 0;
    }
};


int main() {

    return 0;
}
