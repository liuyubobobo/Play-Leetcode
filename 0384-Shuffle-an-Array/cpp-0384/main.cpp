/// Source : https://leetcode.com/problems/shuffle-an-array/description/
/// Author : liuyubobobo
/// Time   : 2017-11-10

#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

/// Brute Force Simulation
///
/// Time Complexity: initial: O(n)
///                  reset: O(1)
///                  shuffle: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    vector<int> nums;

public:
    Solution(vector<int> nums) {
        this->nums.clear();
        for(int num: nums)
            this->nums.push_back(num);
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {

        vector<int> package(nums.begin(), nums.end());
        vector<int> res;
        // srand(time(NULL));
        for(int i = 0 ; i < nums.size() ; i ++){
            int pos = rand() % package.size();
            swap(package[pos], package[package.size()-1]);
            res.push_back(package.back());
            package.pop_back();
        }

        return res;
    }
};


void printVec(const vector<int>& vec){
    for(int num: vec)
        cout << num << " ";
    cout << endl;
}

int main() {

    int nums[3] = {1, 2, 3};
    vector<int> vec(nums, nums + 3);
    Solution obj(vec);
    printVec(obj.shuffle());
    printVec(obj.reset());
    printVec(obj.shuffle());

    return 0;
}