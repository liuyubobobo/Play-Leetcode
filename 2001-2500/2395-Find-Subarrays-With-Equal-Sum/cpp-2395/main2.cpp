/// Source : https://leetcode.com/problems/find-subarrays-with-equal-sum/
/// Author : liuyubobobo
/// Time   : 2022-09-03

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using MultiSet
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {

        int n = nums.size();
        multiset<int> s;
        for(int start = 0; start + 1 < n; start ++)
            s.insert(nums[start] + nums[start + 1]);

        for(int start = 0; start + 1 < n; start ++){
            int t = nums[start] + nums[start + 1];
            s.erase(s.find(t));
            if(s.count(t)) return true;
        }
        return false;
    }
};


int main() {


    return 0;
}
