/// Source : https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/
/// Author : liuyubobobo
/// Time   : 2021-03-06

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {

        long long sum = 0ll;
        for(const int num: nums) sum += (long long)num;

        if(sum == (long long)goal) return 0;
        return solve(abs(goal - sum), (long long)limit);
    }

private:
    long long solve(long long sum, long long limit){
        long long res = sum / limit;
        if(sum % limit != 0)
            res += 1ll;
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, -1, 1};
    cout << Solution().minElements(nums1, 3, -4) << endl;
    // 2

    vector<int> nums2 = {1, -10, 9, 1};
    cout << Solution().minElements(nums2, 100, 0) << endl;
    // 1

    return 0;
}
