/// Source : https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar/
/// Author : liuyubobobo
/// Time   : 2022-10-22

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {

        vector<int> even_s, odd_s;
        for(int e: nums) if(e & 1) odd_s.push_back(e); else even_s.push_back(e);

        vector<int> even_t, odd_t;
        for(int e: target) if(e & 1) odd_t.push_back(e); else even_t.push_back(e);

        sort(even_s.begin(), even_s.end());
        sort(odd_s.begin(), odd_s.end());
        sort(even_t.begin(), even_t.end());
        sort(odd_t.begin(), odd_t.end());

        assert(even_s.size() == even_t.size() && odd_s.size() == odd_t.size());

        long long add = 0, sub = 0;
        for(int i = 0; i < even_s.size(); i ++){
            if(even_s[i] < even_t[i]) add += (even_t[i] - even_s[i]) / 2;
            else sub += (even_s[i] - even_t[i]) / 2;
        }
        for(int i = 0; i < odd_s.size(); i ++){
            if(odd_s[i] < odd_t[i]) add += (odd_t[i] - odd_s[i]) / 2;
            else sub += (odd_s[i] - odd_t[i]) / 2;
        }
        assert(add == sub);
        return add;
    }
};


int main() {

    vector<int> nums1 = {8, 12, 6}, target1 = {2, 14, 10};
    cout << Solution().makeSimilar(nums1, target1) << '\n';
    // 2

    vector<int> nums2 = {1, 2, 5}, target2 = {4, 1, 3};
    cout << Solution().makeSimilar(nums2, target2) << '\n';
    // 1

    return 0;
}
