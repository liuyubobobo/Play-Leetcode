/// Source : https://leetcode.com/problems/keep-multiplying-found-values-by-two/
/// Author : liuyubobobo
/// Time   : 2022-01-29

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Simulation
/// Time Complexity: O(log(max_num))
/// Space Compexity: O(n)
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {

        unordered_set<int> table(nums.begin(), nums.end());
        while(table.count(original))
            original *= 2;
        return original;
    }
};


int main() {

    return 0;
}
