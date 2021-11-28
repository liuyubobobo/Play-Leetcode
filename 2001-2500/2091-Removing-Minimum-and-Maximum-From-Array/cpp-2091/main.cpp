/// Source : https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
/// Author : liuyubobobo
/// Time   : 2021-11-27

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return 1;

        int a = min_element(nums.begin(), nums.end()) - nums.begin();
        int b = max_element(nums.begin(), nums.end()) - nums.begin();
        if(a > b) swap(a, b);

        int res = b + 1;
        res = min(res, n - a);
        res = min(res, a + 1 + n - b);
        return res;
    }
};


int main() {

    return 0;
}
