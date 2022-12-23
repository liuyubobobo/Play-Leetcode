/// Source : https://leetcode.com/problems/number-of-subarrays-having-even-product/description/
/// Author : liuyubobobo
/// Time   : 2022-12-22

#include <iostream>
#include <vector>

using namespace std;


/// Mono Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long evenProduct(vector<int>& nums) {

        int n = nums.size();
        vector<int> next_even(n, n), stack;

        for(int i = 0; i < n; i ++){
            stack.push_back(i);
            if(nums[i] % 2 == 0){
                while(!stack.empty()){
                    next_even[stack.back()] = i;
                    stack.pop_back();
                }
            }
        }

        long long res = 0;
        for(int l = 0; l < n; l ++)
            res += n - next_even[l];
        return res;
    }
};


int main() {

    return 0;
}
