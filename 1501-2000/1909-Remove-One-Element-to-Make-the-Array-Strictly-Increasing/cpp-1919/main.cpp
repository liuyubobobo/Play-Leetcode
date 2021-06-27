/// Source : https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/
/// Author : liuyubobobo
/// Time   : 2021-06-26

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i ++)
            if(is_sort(nums, i)) return true;

        return false;
    }

private:
    bool is_sort(const vector<int>& nums, int del){

        vector<int> data;
        for(int i = 0; i < nums.size(); i ++)
            if(i != del)
                data.push_back(nums[i]);

        for(int i = 1; i < data.size(); i ++)
            if(data[i] <= data[i - 1]) return false;
        return true;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
