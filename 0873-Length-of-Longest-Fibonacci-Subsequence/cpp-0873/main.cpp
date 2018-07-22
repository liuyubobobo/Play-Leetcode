/// Source : https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/
/// Author : liuyubobobo
/// Time   : 2018-07-21

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Brute Force iterate the first 2 elements in the fibonacci sequence
/// Since the number will grow exponentially, there will be at most 43 items to check
/// Time Complexity: O(n^2*log(maxA))
/// Space Complexity: O(A)
class Solution {

public:
    int lenLongestFibSubseq(vector<int>& A) {

        unordered_set<int> nums;
        for(int a: A)
            nums.insert(a);

        int res = 2;
        for(int i = 0 ; i < A.size() ; i ++)
            for(int j = i + 1; j < A.size() ; j ++){
                int len = 2;
                int a = A[i], b = A[j];
                while(true){
                    int next = a + b;
                    if(next > 1e9)
                        break;
                    if(nums.find(next) == nums.end())
                        break;

                    a = b, b = next, len ++;
                }
                res = max(res, len);
            }
        return res > 2 ? res : 0;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << Solution().lenLongestFibSubseq(nums1) << endl;
    // 5

    vector<int> nums2 = {1, 3, 7, 11, 12, 14, 18};
    cout << Solution().lenLongestFibSubseq(nums2) << endl;
    // 3

    vector<int> nums3 = {2, 4, 5, 6, 7, 8, 11, 13, 14, 15, 21, 22, 34};
    cout << Solution().lenLongestFibSubseq(nums3) << endl;
    // 5

    return 0;
}