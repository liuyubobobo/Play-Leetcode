/// Source : https://leetcode.com/problems/find-unique-binary-string/
/// Author : liuyubobobo
/// Time   : 2021-08-23

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Cantor's Diagonalization
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        int n = nums.size();

        string res = "";
        for(int i = 0; i < n; i ++)
            res += nums[i][i] == '0' ? "1" : "0";
        return res;
    }
};


int main() {

    vector<string> nums1 = {"01", "10"};
    cout << Solution().findDifferentBinaryString(nums1) << endl;
    // 11

    vector<string> nums2 = {"00", "01"};
    cout << Solution().findDifferentBinaryString(nums2) << endl;
    // 11

    vector<string> nums3 = {"111", "011", "001"};
    cout << Solution().findDifferentBinaryString(nums3) << endl;
    // 101

    return 0;
}
