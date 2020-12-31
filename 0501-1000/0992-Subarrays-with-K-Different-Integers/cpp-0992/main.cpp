/// Source : https://leetcode.com/problems/subarrays-with-k-different-integers/
/// Author : liuyubobobo
/// Time   : 2019-02-13

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {

        unordered_map<int, int> set_left, set_right;
        int left = 0, right = 0, res = 0;
        for(int e: A){
            set_left[e] ++;
            set_right[e] ++;

            while(set_left.size() > K){
                set_left[A[left]] --;
                if(set_left[A[left]] == 0)
                    set_left.erase(A[left]);
                left ++;
            }

            while(set_right.size() >= K){
                set_right[A[right]] --;
                if(set_right[A[right]] == 0)
                    set_right.erase(A[right]);
                right ++;
            }

            res += right - left;
        }
        return res;
    }
};


int main() {

    vector<int> A1 = {1,2,1,2,3};
    int K1 = 2;
    cout << Solution().subarraysWithKDistinct(A1, K1) << endl;
    // 7

    vector<int> A2 = {1,2,1,3,4};
    int K2 = 3;
    cout << Solution().subarraysWithKDistinct(A2, K2) << endl;
    // 3

    return 0;
}