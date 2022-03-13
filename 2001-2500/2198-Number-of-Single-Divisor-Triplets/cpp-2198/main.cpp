/// Source : https://leetcode.com/problems/number-of-single-divisor-triplets/
/// Author : liuyubobobo
/// Time   : 2022-03-12

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(maxv^3)
/// Space Complexity: O(maxv)
class Solution {
public:
    long long singleDivisorTriplet(vector<int>& nums) {

        int maxv = 0;
        vector<long long> f(101, 0);
        for(int num: nums){
            f[num] ++;
            maxv = max(maxv, num);
        }

        long long res = 0ll;
        for(int t1 = 1; t1 <= maxv; t1 ++) if(f[t1])
            for(int t2 = t1 + 1; t2 <= maxv; t2 ++) if(f[t2])
                for(int t3 = t2 + 1; t3 <= maxv; t3 ++) if(f[t3]){
                    bool a = (t1 + t2 + t3) % t1;
                    bool b = (t1 + t2 + t3) % t2;
                    bool c = (t1 + t2 + t3) % t3;
                    if(a + b + c == 2)
                        res += f[t1] * f[t2] * f[t3] * 6;
                }

        for(int t1 = 1; t1 <= maxv; t1 ++) if(f[t1])
            for(int t2 = t1 + 1; t2 <= maxv; t2 ++) if(f[t2]){
                if(f[t1] >= 2 && (t1 * 2 + t2) % t1 && (t1 * 2 + t2) % t2 == 0)
                    res += f[t1] * (f[t1] - 1) / 2 * f[t2] * 6;
                if(f[t2] >= 2 && (t1 + t2 * 2) % t2 && (t1 + t2 * 2) % t1 == 0)
                    res += f[t2] * (f[t2] - 1) / 2 * f[t1] * 6;
            }
        return res;
    }
};


int main() {

    vector<int> nums1 = {4,6,7,3,2};
    cout << Solution().singleDivisorTriplet(nums1) << '\n';
    // 12

    vector<int> nums2 = {1,2,2};
    cout << Solution().singleDivisorTriplet(nums2) << '\n';
    // 6

    vector<int> nums3 = {1,1,1};
    cout << Solution().singleDivisorTriplet(nums3) << '\n';
    // 0

    vector<int> nums4 = {71,2,88,93,15,88,69};
    cout << Solution().singleDivisorTriplet(nums4) << '\n';
    // 48

    return 0;
}
