/// Source : https://leetcode.com/problems/third-maximum-number/
/// Author : liuyubobobo
/// Time   : 2019-09-06

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int thirdMax(vector<int>& nums) {

        int count = 0, maxv = INT_MIN;
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        for(int e: nums){
            if(count == 0) a = e, count ++;
            else if(count == 1 && e != a) b = e, count ++;
            else if(count == 2 && e != a && e != b) c = e, count ++;
            else if(count == 3 && e > c && e != a && e != b) c = e;

            if(b < c) swap(b, c);
            if(a < b) swap(a, b);

            maxv = max(maxv, e);
        }
        return count < 3 ? maxv : c;
    }
};


int main() {

    vector<int> nums1 = {3, 2, 1};
    cout << Solution().thirdMax(nums1) << endl;
    // 1

    vector<int> nums2 = {2, 2, 3, 1};
    cout << Solution().thirdMax(nums2) << endl;
    // 1

    vector<int> nums3 = {1, 2};
    cout << Solution().thirdMax(nums3) << endl;
    // 2

    vector<int> nums4 = {1, -2147483648, 2};
    cout << Solution().thirdMax(nums4) << endl;
    // -2147483648

    return 0;
}