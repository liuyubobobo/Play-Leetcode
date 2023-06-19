/// Source : https://leetcode.com/problems/neither-minimum-nor-maximum/description/
/// Author : liuyubobobo
/// Time   : 2023-06-19

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Set
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {

        set<int> s(nums.begin(), nums.end());
        if(s.size() <= 2) return -1;

        auto iter = s.begin();
        iter ++;
        return *iter;
    }
};


int main() {

    return 0;
}
