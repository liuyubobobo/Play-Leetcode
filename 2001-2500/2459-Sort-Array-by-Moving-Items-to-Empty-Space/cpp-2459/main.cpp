/// Source : https://leetcode.com/problems/sort-array-by-moving-items-to-empty-space/description/
/// Author : liuyubobobo
/// Time   : 2023-01-09

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int sortArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> target(n);
        for(int i = 0; i < n; i ++) target[i] = i;

        int res = solve(n, nums, target);

        for(int i = 0; i < n; i ++) target[i] = i + 1;
        target.back() = 0;
        res = min(res, solve(n, nums, target));

        return res;
    }

private:
    int solve(int n, const vector<int>& nums, const vector<int>& target){

        vector<int> pos(n);
        for(int i = 0; i < n; i ++) pos[target[i]] = i;

        vector<bool> visited(n, false);
        int res = 0;
        for(int i = 0; i < n; i ++){
            if(visited[i]) continue;

            int cur = i, len = 0;
            bool contain_zero = false;
            while(!visited[cur]){
                len ++;
                visited[cur] = true;

                if(nums[cur] == 0) contain_zero = true;
                cur = pos[nums[cur]];
            }

            if(len == 1) continue;

            if(contain_zero) res += len - 1;
            else res += len + 1;
        }
        return res;
    }
};


int main() {

    return 0;
}
