/// Source : https://leetcode.com/problems/play-with-chips/
/// Author : liuyubobobo
/// Time   : 2019-10-05

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {

        int odd = 0, even = 0;
        for(int e: chips)
            if(e % 2) odd ++;
            else even ++;
        return min(odd, even);
    }
};


int main() {

    vector<int> chip1 = {1, 2, 3};
    cout << Solution().minCostToMoveChips(chip1) << endl;
    // 1

    return 0;
}