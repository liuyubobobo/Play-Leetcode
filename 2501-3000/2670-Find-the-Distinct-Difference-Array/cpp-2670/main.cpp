/// Source : https://leetcode.com/problems/find-the-distinct-difference-array/
/// Author : liuyubobobo
/// Time   : 2023-05-06

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> pre(n), suf(n + 1, 0);
        set<int> s;
        for(int i = 0; i < n; i ++){
            s.insert(nums[i]);
            pre[i] = s.size();
        }

        s.clear();
        for(int i = n - 1; i >= 0; i --){
            s.insert(nums[i]);
            suf[i] = s.size();
        }

        vector<int> res(n);
        for(int i = 0; i < n; i ++) res[i] = pre[i] - suf[i + 1];
        return res;
    }
};


int main() {

    return 0;
}
