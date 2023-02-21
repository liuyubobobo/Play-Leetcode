/// Source : https://leetcode.com/problems/minimum-impossible-or/description/
/// Author : liuyubobobo
/// Time   : 2023-02-20

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Math
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        for(int i = 0;;i ++){
            auto iter = lower_bound(nums.begin(), nums.end(), 1 << i);
            if(iter == nums.end() || *iter != (1 << i))
                return 1 <<i;
        }
        return -1;
    }
};


int main() {

    return 0;
}
