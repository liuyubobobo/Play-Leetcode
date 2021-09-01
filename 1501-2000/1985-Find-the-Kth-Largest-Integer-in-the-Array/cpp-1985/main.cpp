/// Source : https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/
/// Author : liuyubobobo
/// Time   : 2021-08-28

#include <iostream>
#include <vector>

using namespace std;


/// Adding leading 0 and sort
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {

        int maxlen = 0;
        for(const string& num: nums) maxlen = max(maxlen, (int)num.size());

        for(string& num: nums) num = string(maxlen - num.size(), '0') + num;

        sort(nums.begin(), nums.end(), greater<string>());

        string res = nums[k - 1];
        while(res.size() > 1 && res[0] == '0') res = res.substr(1);
        return res;
    }
};


int main() {

    vector<string> nums1 = {"3","6","7","10"};
    cout << Solution().kthLargestNumber(nums1, 4) << endl;
    // 3

    vector<string> nums2 = {"2","21","12","1"};
    cout << Solution().kthLargestNumber(nums2, 3) << endl;
    // 2

    vector<string> nums3 = {"0","0"};
    cout << Solution().kthLargestNumber(nums3, 2) << endl;
    // 0

    vector<string> nums4 = {"623986800","3","887298","695","794","6888794705","269409","59930972","723091307","726368","8028385786","378585"};
    cout << Solution().kthLargestNumber(nums4, 11) << endl;
    // 695

    return 0;
}
