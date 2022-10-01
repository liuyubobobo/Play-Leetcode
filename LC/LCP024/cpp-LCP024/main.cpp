/// Source : https://leetcode-cn.com/problems/5TxKeK/
/// Author : liuyubobobo
/// Time   : 2020-09-21

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Two heaps to maintain the median
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    vector<int> numsGame(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i ++) nums[i] -= i;
        vector<int> res = {0};

        priority_queue<int> leftheap; // left is max heap
        priority_queue<int, vector<int>, greater<int>> rightheap; // right is min heap
        leftheap.push(nums[0]);

        long long leftsum = nums[0], rightsum = 0;
        for(int i = 1; i < nums.size(); i ++){

            leftheap.push(nums[i]); leftsum += nums[i];
            if(leftheap.size() - rightheap.size() == 2){
                int x = leftheap.top();
                leftheap.pop(); leftsum -= x;
                rightheap.push(x); rightsum += x;
            }
            if(leftheap.top() > rightheap.top()){
                int x = leftheap.top(); leftheap.pop(); leftsum -= x;
                int y = rightheap.top(); rightheap.pop(); rightsum -= y;
                leftheap.push(y); leftsum += y;
                rightheap.push(x); rightsum += x;
            }

            long long cur_m = leftheap.top();
            long long op = 0ll;
            op += cur_m * leftheap.size() - leftsum;
            op += rightsum - cur_m * rightheap.size();
            res.push_back(op % MOD);
        }
        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums1 = {3,4,5,1,6,7};
    print_vec(Solution().numsGame(nums1));
    // 0 0 0 5 6 7

    vector<int> nums2 = {1,2,3,4,5};
    print_vec(Solution().numsGame(nums2));
    // 0 0 0 0 0

    vector<int> nums3 = {1,1,1,2,3,4};
    print_vec(Solution().numsGame(nums3));
    // 0 1 2 3 3 3

    return 0;
}
