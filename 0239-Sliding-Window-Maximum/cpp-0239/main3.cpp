/// Source : https://leetcode.com/problems/sliding-window-maximum/description/
/// Author : liuyubobobo
/// Time   : 2020-04-27

#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;


/// Using a map as a priority queue
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        if(k == 0 || nums.size() == 0)
            return vector<int>();

        if(k == 1) return nums;

        map<int, int> window;
        for(int i = 0; i < k - 1; i ++)
            window[nums[i]] ++;

        vector<int> res;
        for(int i = k - 1 ; i < nums.size() ; i ++){

            window[nums[i]] ++;
            res.push_back(window.rbegin()->first);

            window[nums[i - k + 1]] --;
            if(window[nums[i - k + 1]] == 0) window.erase(nums[i - k + 1]);
        }

        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    print_vec(Solution().maxSlidingWindow(nums, 3));
    // 3 3 5 5 6 7

    return 0;
}