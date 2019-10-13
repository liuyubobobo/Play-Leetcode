/// Source : https://leetcode.com/problems/maximum-equal-frequency/
/// Author : liuyubobobo
/// Time   : 2019-10-12

#include <iostream>
#include <vector>

using namespace std;


/// Using Arraay to record freq and the freq of freq number
/// And make the logic more concise
/// Time Complexity: O(|nums|)
/// Space Complexity: O(|nums|)
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {

        if(nums.size() <= 3) return nums.size();

        vector<int> freq(*max_element(nums.begin(), nums.end()) + 1, 0);
        vector<int> freqnum(nums.size() + 1, 0);

        int res = 0;
        for(int i = 0; i < nums.size(); i ++){
            int o_f = freq[nums[i]];
            if(o_f) freqnum[o_f]--;
            freq[nums[i]] ++;

            int new_f = freq[nums[i]];
            freqnum[new_f] ++;

            if(freqnum[new_f] * new_f == i + 1 && i + 1 < nums.size())
                res = i + 2;
            else{
                int left = i + 1 - new_f * freqnum[new_f];
                if((left == new_f + 1 || left == 1) && freqnum[left] == 1)
                    res = i + 1;
            }
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {2,2,1,1,5,3,3,5};
    cout << Solution().maxEqualFreq(nums1) << endl;
    // 7

    vector<int> nums2 = {1,1,1,2,2,2,3,3,3,4,4,4,5};
    cout << Solution().maxEqualFreq(nums2) << endl;
    // 13

    vector<int> nums3 = {1,1,1,2,2,2};
    cout << Solution().maxEqualFreq(nums3) << endl;
    // 5

    vector<int> nums4 = {10,2,8,9,3,8,1,5,2,3,7,6};
    cout << Solution().maxEqualFreq(nums4) << endl;
    // 8

    vector<int> nums5 = {1,2,3,4,5,6,7,8,9};
    cout << Solution().maxEqualFreq(nums5) << endl;
    // 9

    vector<int> nums6 = {1,1,1,1,1,1};
    cout << Solution().maxEqualFreq(nums6) << endl;
    // 6

    vector<int> nums7 = {2,2,1,1,5,3,3,5};
    cout << Solution().maxEqualFreq(nums7) << endl;
    // 7

    return 0;
}