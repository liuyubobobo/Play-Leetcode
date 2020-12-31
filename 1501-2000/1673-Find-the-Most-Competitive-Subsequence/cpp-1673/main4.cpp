/// Source : https://leetcode.com/problems/find-the-most-competitive-subsequence/
/// Author : liuyubobobo
/// Time   : 2020-11-30

#include <iostream>
#include <vector>

using namespace std;


/// Mono Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {

        vector<int> stack;
        int remove = nums.size() - k;

        for(int e: nums){
            while(!stack.empty() && remove && stack.back() > e)
                stack.pop_back(), remove --;

            stack.push_back(e);
        }

        while(remove) stack.pop_back(), remove --;
        return stack;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums1 = {3, 5, 2, 6};
    print_vec(Solution().mostCompetitive(nums1, 2));
    // 2 6

    vector<int> nums2 = {2,4,3,3,5,4,9,6};
    print_vec(Solution().mostCompetitive(nums2, 4));
    // 2 3 3 4

    return 0;
}