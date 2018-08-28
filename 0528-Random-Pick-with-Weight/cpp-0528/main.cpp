/// Source : https://leetcode.com/problems/random-pick-with-weight/description/
/// Author : liuyubobobo
/// Time   : 2018-08-28

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Pre-Sum and Binary Search
/// Time Complexity: init: O(n)
///                  pickIndex: O(logn)
/// Space Complexity: O(n)
class Solution {

private:
    vector<int> sum;

public:
    Solution(vector<int> w) {
        sum.clear();
        sum.push_back(0);
        for(int e: w)
            sum.push_back(sum.back() + e);
    }

    int pickIndex() {

        int randNum = rand() % sum.back();
        int index = lower_bound(sum.begin(), sum.end(), randNum) - sum.begin();
        if(sum[index] != randNum)
            index --;
        return index;
    }
};


int main() {

    return 0;
}