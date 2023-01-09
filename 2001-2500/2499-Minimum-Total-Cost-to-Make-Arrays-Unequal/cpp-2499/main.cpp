/// Source : https://leetcode.com/problems/minimum-total-cost-to-make-arrays-unequal/description/
/// Author : liuyubobobo
/// Time   : 2023-01-09

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();

        map<int, int> f;
        int total = 0;
        long long res = 0;
        for(int i = 0; i < n; i ++)
            if(nums1[i] == nums2[i]) f[nums1[i]] ++, total ++, res += i;

        int maxf = 0, maxf_value;
        for(const pair<int, int>& p: f)
            if(p.second > maxf) maxf = p.second, maxf_value = p.first;

        for(int i = 0; i < n && maxf > total / 2; i ++)
            if(nums1[i] != nums2[i] && nums1[i] != maxf_value && nums2[i] != maxf_value)
                res += i, total ++;

        return  maxf > total / 2 ? -1 : res;
    }
};


int main() {

    return 0;
}
