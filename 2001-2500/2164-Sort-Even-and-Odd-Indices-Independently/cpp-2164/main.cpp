/// Source : https://leetcode.com/problems/sort-even-and-odd-indices-independently/
/// Author : liuyubobobo
/// Time   : 2021-02-06

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {

        vector<int> odd, even;
        for(int i = 0; i < nums.size(); i ++)
            if(i % 2 == 0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);

        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end());

        vector<int> res;
        for(int k = 0, i = 0, j = 0; k < nums.size(); k ++)
            if(k % 2 == 0) res.push_back(even[i ++]);
            else res.push_back(odd[j ++]);
        return res;
    }
};


int main() {

    return 0;
}
