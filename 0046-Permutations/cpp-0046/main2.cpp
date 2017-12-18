/// Source : https://leetcode.com/problems/permutations/description/
/// Author : liuyubobobo
/// Time   : 2017-12-17

#include <iostream>
#include <vector>
using namespace std;

/// Recursive get all the permutations in place
/// Time Complexity: O(n!)
/// Space Complexity: O(n)
class Solution {

private:

    vector<vector<int>> res;

    void generatePermutation(vector<int>& nums, int index){

        if(index == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i = index ; i < nums.size() ; i ++){
            swap(nums[i], nums[index]);
            generatePermutation(nums, index + 1);
            swap(nums[i], nums[index]);
        }

        return;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {

        res.clear();
        if(nums.size() == 0)
            return res;

        generatePermutation(nums, 0);

        return res;
    }
};


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> vec = {1, 2, 3};

    vector<vector<int>> res = Solution().permute(vec);
    for(int i = 0 ; i < res.size() ; i ++)
        printVec(res[i]);

    return 0;
}