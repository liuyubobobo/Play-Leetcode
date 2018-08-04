/// Source : https://leetcode.com/problems/stone-game/description/
/// Author : liuyubobobo
/// Time   : 2018-08-03

#include <iostream>
#include <vector>

using namespace std;


/// Mathematic, the answer will always be true!
/// Since the player can technically take all the stones from even-index piles,
/// or take all the stones from odd-index piles
/// One of the two strategy must win:)
///
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};


void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    vector<int> piles1 = {5, 3, 4, 5};
    print_bool(Solution().stoneGame(piles1));

    return 0;
}