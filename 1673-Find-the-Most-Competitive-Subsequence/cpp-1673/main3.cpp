/// Source : https://leetcode.com/problems/find-the-most-competitive-subsequence/
/// Author : liuyubobobo
/// Time   : 2020-11-30

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using TreeSet
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {

        set<pair<int, int>> tree;

        int n = nums.size();
        for(int i = 0; i < n - k; i ++)
            tree.insert({nums[i], i});

        vector<int> res(k);
        int l = 0, r = n - k;
        for(int i = 0; i < k; i ++){

            tree.insert({nums[r], r});
            r ++;

            while(!tree.empty() && tree.begin()->second < l) tree.erase(tree.begin());

            assert(!tree.empty());
            res[i] = tree.begin()->first;
            l = tree.begin()->second + 1;
            tree.erase(tree.begin());
        }
        return res;
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