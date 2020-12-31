/// Source : https://leetcode.com/problems/rotate-array/description/
/// Author : liuyubobobo
/// Time   : 2018-08-10

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/// Using Queue and rotate the elements in original nums
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        queue<int> q;
        int kk = k;
        for(int i = (int)nums.size() - 1; i >= 0 && kk --; i --)
            q.push(nums[i]);
        for(int i = q.size() ; i < kk ; i ++)
            q.push(q.front()), q.pop();

        for(int i = (int)nums.size() - k - 1; i >= 0; i --)
            nums[i + k] = nums[i];

        while(!q.empty()){
            k --;
            if(k < 0)
                k += nums.size();
            k %= nums.size();
            nums[k] = q.front();
            q.pop();
        }
        return;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    Solution().rotate(nums1, 3);
    print_vec(nums1);
    // 5 6 7 1 2 3 4

    vector<int> nums2 = {1, 2};
    Solution().rotate(nums2, 3);
    print_vec(nums2);
    // 2 1

    vector<int> nums3 = {1, 2};
    Solution().rotate(nums3, 2);
    print_vec(nums3);
    // 1 2

    return 0;
}