/// Source : https://leetcode.com/problems/split-array-into-consecutive-subsequences/
/// Author : liuyubobobo
/// Time   : 2020-12-03

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool isPossible(vector<int>& nums) {

        unordered_map<int, int> left;
        for(int e: nums) left[e] ++;

        unordered_map<int, int> ending;
        for(int e: nums)
            if(left[e]){
                if(ending[e - 1] > 0){
                    ending[e - 1] --;
                    ending[e] ++;
                    left[e] --;
                }
                else{
                    if(!left[e + 1] || !left[e + 2]) return false;
                    left[e] --, left[e + 1] --, left[e + 2] --;
                    ending[e + 2] ++;
                }
            }
        return true;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3, 3, 4, 5};
    cout << Solution().isPossible(nums1) << endl;
    // 1

    vector<int> nums2 = {1,2,3,3,4,4,5,5};
    cout << Solution().isPossible(nums2) << endl;
    // 1

    vector<int> nums3 = {1,2,3,4,4,5};
    cout << Solution().isPossible(nums3) << endl;
    // 0

    return 0;
}
