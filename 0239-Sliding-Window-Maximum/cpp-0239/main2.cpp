/// Source : https://leetcode.com/problems/sliding-window-maximum/description/
/// Author : liuyubobobo
/// Time   : 2017-11-22

#include <iostream>
#include <vector>
#include <deque>
#include <cassert>

using namespace std;

/// Using Decreasing Queue
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        if(k == 0 || nums.size() == 0)
            return vector<int>();

        if(k == 1)
            return nums;

        deque<int> q;
        vector<int> res;
        for(int i = 0 ; i < nums.size() ; i ++){

            while(!q.empty() && q.back() < nums[i])
                q.pop_back();
            q.push_back(nums[i]);

            if(i >= k - 1){
                res.push_back(q.front());
                if(q.front() == nums[i - (k - 1)])
                    q.pop_front();
            }
        }

        return res;
    }
};


void printVec(const vector<int>& vec){

    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    printVec(Solution().maxSlidingWindow(nums, k));

    return 0;
}