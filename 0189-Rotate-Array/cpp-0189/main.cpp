/// Source : https://leetcode.com/problems/rotate-array/description/
/// Author : liuyubobobo
/// Time   : 2018-08-10

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/// Using Queue
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        queue<int> q;
        while(k -- && !nums.empty())
            q.push(nums.back()), nums.pop_back();
        for(int i = 0 ; i <= k ; i ++)
            q.push(q.front()), q.pop();

        while(!q.empty())
            nums.insert(nums.begin(), q.front()), q.pop();
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

    vector<int> nums2 = {1, 2};
    Solution().rotate(nums2, 3);
    print_vec(nums2);

    return 0;
}