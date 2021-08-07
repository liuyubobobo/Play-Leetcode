/// Source : https://leetcode.com/problems/circular-array-loop/
/// Author : liuyubobobo
/// Time   : 2021-08-06

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();
        vector<bool> visited(n, false);
        vector<int> dp(n, -1);

        bool positive;
        for(int i = 0; i < nums.size(); i ++)
            if(dp[i] == -1){
                positive = nums[i] > 0;
                visited.assign(n, false);
                visited[i] = true;
                for(int j = ((i + nums[i]) % n + n) % n;;j = ((j + nums[j]) % n + n) % n)
                    if(dp[j] == 0) break;
                    else if(j == ((j + nums[j]) % n + n) % n) break;
                    else if(positive != nums[j] > 0) break;
                    else if(visited[j]) return true;
                    else visited[j] = true;

                dp[i] = 0;
                visited[i] = false;
                for(int j = ((i + nums[i]) % n + n) % n; ;j = ((j + nums[j]) % n + n) % n){
                    if(!visited[j]) break;
                    visited[j] = false;
                    dp[j] = 0;
                }
            }
        return false;
    }
};


int main() {

    vector<int> nums1 = {2, -1, 1, 2, 2};
    cout << Solution().circularArrayLoop(nums1) << endl;
    // true

    vector<int> nums2 = {-1, 2};
    cout << Solution().circularArrayLoop(nums2) << endl;
    // false

    vector<int> nums3 = {-2, 1, -1, -2, -2};
    cout << Solution().circularArrayLoop(nums3) << endl;
    // false

    vector<int> nums4 = {2, -1, 1, -2, -2};
    cout << Solution().circularArrayLoop(nums4) << endl;
    // false

    vector<int> nums5 = {1, 1, 2};
    cout << Solution().circularArrayLoop(nums5) << endl;
    // true

    vector<int> nums6 = {2, 2, 2, 2, 2, 4, 7};
    cout << Solution().circularArrayLoop(nums6) << endl;
    // false

    vector<int> nums7 = {-2, 1, -1, -2, -2};
    cout << Solution().circularArrayLoop(nums7) << endl;
    // false

    vector<int> nums8 = {-2, -3, -9};
    cout << Solution().circularArrayLoop(nums8) << endl;
    // false

    return 0;
}
