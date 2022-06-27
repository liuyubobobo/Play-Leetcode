/// Source : https://leetcode.com/problems/maximum-score-of-spliced-array/
/// Author : liuyubobobo
/// Time   : 2022-06-25

#include <iostream>
#include <vector>

using namespace std;


/// Math
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();

        vector<int> presum1(n + 1, 0), presum2(n + 1, 0);
        for(int i = 0; i < n; i ++){
            presum1[i + 1] = presum1[i] + nums1[i];
            presum2[i + 1] = presum2[i] + nums2[i];
        }

        vector<int> presum12(n + 1, 0), presum21(n + 1, 0);
        for(int i = 0; i <= n; i ++){
            presum12[i] = presum1[i] - presum2[i];
            presum21[i] = presum2[i] - presum1[i];
        }

        int max12 = 0, max21 = 0, res = max(presum1.back(), presum2.back());
        for(int i = 0; i < n; i ++){
            res = max(res, presum1.back() + presum21[i + 1] + max12);
            res = max(res, presum2.back() + presum12[i + 1] + max21);
            max12 = max(max12, presum12[i + 1]);
            max21 = max(max21, presum21[i + 1]);
        }
        return res;
    }
};


int main() {

    return 0;
}
