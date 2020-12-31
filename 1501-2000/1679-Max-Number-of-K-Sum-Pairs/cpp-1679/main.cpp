/// Source : https://leetcode.com/problems/max-number-of-k-sum-pairs/
/// Author : liuyubobobo
/// Time   : 2020-12-05

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/// Using HashMap - Two Pass
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        unordered_map<int, int> f;
        unordered_set<int> set;

        for(int e: nums){
            f[e] ++;
            set.insert(e);
        }

        int res = 0;
        for(int e: set)
            if(f.count(k - e)){
                if(e != k - e){
                    res += min(f[e], f[k - e]);
                    f.erase(e), f.erase(k - e);
                }
                else{
                    res += f[e] / 2;
                    f.erase(e);
                }
            }
        return res;
    }
};

int main() {

    vector<int> nums1 = {1, 2, 3, 4};
    cout << Solution().maxOperations(nums1, 5) << endl;
    // 2

    vector<int> nums2 = {3,1,3,4,3};
    cout << Solution().maxOperations(nums2, 6) << endl;
    // 1

    return 0;
}