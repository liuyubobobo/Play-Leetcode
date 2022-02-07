/// Source : https://leetcode.com/problems/partition-array-according-to-given-pivot/
/// Author : liuyubobobo
/// Time   : 2022-02-06

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int> pre, middle, post;
        for(int e: nums)
            if(e < pivot) pre.push_back(e);
            else if(e == pivot) middle.push_back(e);
            else post.push_back(e);

        pre.insert(pre.end(), middle.begin(), middle.end());
        pre.insert(pre.end(), post.begin(), post.end());
        return pre;
    }
};


int main() {

    return 0;
}
