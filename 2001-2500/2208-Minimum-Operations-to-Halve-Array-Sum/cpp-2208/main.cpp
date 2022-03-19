/// Source : https://leetcode.com/problems/minimum-operations-to-halve-array-sum/
/// Author : liuyubobobo
/// Time   : 2022-03-19

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;


/// Using Priority Queue
/// Time Complexity: O(xlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int halveArray(vector<int>& nums) {

        long long sum = accumulate(nums.begin(), nums.end(), 0ll);
        long double target = sum / 2.0;

        priority_queue<long double> pq;
        for(int e: nums) pq.push(e);

        long double cur = 0;
        int res = 0;
        while(cur < target){
            long double x = pq.top();
            pq.pop();

            cur += x / 2.0;
            res ++;

            pq.push(x / 2.0);
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {5, 19, 8, 1};
    cout << Solution().halveArray(nums1) << '\n';
    // 3

    vector<int> nums2 = {3, 8, 20};
    cout << Solution().halveArray(nums2) << '\n';
    // 3

    return 0;
}
