/// Source : https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
/// Author : liuyubobobo
/// Time   : 2022-10-16

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        int n = nums.size();

        vector<bool> ok(n);
        for(int i = 0; i < n; i ++)
            ok[i] = (minK <= nums[i] && nums[i] <= maxK);

        long long res = 0;
        for(int start = 0, i = 1; i <= n; i ++)
            if(i == n || ok[i] != ok[start]){
                if(ok[start])
                    res += solve(nums, start, i, minK, maxK);
                start = i;
            }
        return res;
    }

private:
    long long solve(const vector<int>& nums, int l, int r, int minK, int maxK){

        vector<int> min_indices, max_indices;
        for(int i = l; i < r; i ++){
            if(nums[i] == minK) min_indices.push_back(i);
            if(nums[i] == maxK) max_indices.push_back(i);
        }

        long long res = 0;
        int i = l, min_i = 0, max_i = 0;
        while(i < r && min_i < min_indices.size() && max_i < max_indices.size()){

            int j = max(min_indices[min_i], max_indices[max_i]);
            res += r - j;

            i ++;
            if(min_indices[min_i] < i) min_i ++;
            if(max_indices[max_i] < i) max_i ++;
        }
        return res;
    }
};


int main() {

    return 0;
}
