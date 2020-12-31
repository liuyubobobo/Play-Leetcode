/// Source : https://leetcode.com/problems/sort-array-by-increasing-frequency/
/// Author : liuyubobobo
/// Time   : 2020-10-31

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        unordered_map<int, int> f;
        for(int e: nums) f[e] ++;

        sort(nums.begin(), nums.end(), [&](int a, int b){
           if(f[a] != f[b]) return f[a] < f[b];
           return a > b;
        });
        return nums;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums1 = {1, 1, 2, 2, 2, 3};
    print_vec(Solution().frequencySort(nums1));
    // 3 1 1 2 2 2

    vector<int> nums2 = {2,3,1,3,2};
    print_vec(Solution().frequencySort(nums2));
    // 1,3,3,2,2

    return 0;
}
