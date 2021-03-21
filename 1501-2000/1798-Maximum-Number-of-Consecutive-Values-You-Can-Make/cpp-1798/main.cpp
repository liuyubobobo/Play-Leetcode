/// Source : https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/
/// Author : liuyubobobo
/// Time   : 2021-03-21

#include <iostream>
#include <vector>

using namespace std;


/// Sorting and Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {

        sort(coins.begin(), coins.end());

        int cur = 0;
        for(int e: coins)
            if(e <= cur + 1) cur += e;
            else break;
        return cur + 1;
    }
};


int main() {

    return 0;
}
