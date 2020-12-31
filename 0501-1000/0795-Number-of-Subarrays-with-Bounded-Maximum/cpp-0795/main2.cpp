/// Source : https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/
/// Author : liuyubobobo
/// Time   : 2018-03-05

#include <iostream>
#include <vector>

using namespace std;


/// Counting
/// Using function count to calculate the subarray numbers of maximum <= bound
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {

        return count(A, R) - count(A, L - 1);
    }

private:
    int count(const vector<int>& nums, int bound){

        int res = 0;
        int cur = 0;
        for(int num: nums)
            if(num <= bound){
                cur ++;
                res += cur;
            }
            else
                cur = 0;
        return res;
    }
};

int main() {

//    vector<int> A1 = {2, 1, 4, 3};
//    cout << Solution().numSubarrayBoundedMax(A1, 2, 3) << endl;

    vector<int> A2 = {2, 9, 2, 5, 6};
    cout << Solution().numSubarrayBoundedMax(A2, 2, 8) << endl;

    return 0;
}