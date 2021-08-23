/// Source : https://leetcode.com/problems/find-unique-binary-string/
/// Author : liuyubobobo
/// Time   : 2021-08-21

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        set<int> set;
        for(const string& s: nums) set.insert(to_int(s));

        for(int i = 0; ; i ++)
            if(!set.count(i))
                return to_binary_string(i, nums.size());
        return "";
    }

private:
    string to_binary_string(int x, int len){

        string s(len, ' ');
        for(int i = 0; i < len; i ++)
            s[len - 1 - i] = ('0' + x % 2), x /= 2;
        return s;
    }

    int to_int(const string& s){
        int res = 0;
        for(char c: s)
            res = res * 2 + (c - '0');
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
