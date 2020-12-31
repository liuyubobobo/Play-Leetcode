/// Source : https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/
/// Author : liuyubobobo
/// Time   : 2018-03-05

#include <iostream>
#include <vector>

using namespace std;


/// Counting
///
/// Transform vector A into nums, which only includes elements 0, 1, 2
/// which means elements in A: less than L; between L and R (includes); larger than R
/// Then counting how many subarrays in only 01 subarray that include element 1
/// Using all the subarray number for any 01 subarray MINUS
/// all the subarray number for only 0 subarrays
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {

        vector<int> nums;
        for(int a: A)
            if(a < L)
                nums.push_back(0);
            else if(a > R)
                nums.push_back(2);
            else
                nums.push_back(1);

        // print_vec(nums, 0, nums.size());

        int start = start_of_non(2, nums, 0);
        int res = 0;
        for(int i = start + 1 ; i <= nums.size() ; )
            if(i == nums.size() || nums[i] == 2){
                // print_vec(nums, start, i);
                res += count(nums, start, i);
                // cout << "res = " << res << endl;
                start = start_of_non(2, nums, i);
                i = start + 1;
            }
            else
                i ++;
        return res;
    }

private:
    int count(const vector<int>& nums, int l, int r){

        int res = (1 + r - l) * (r - l) / 2;
        int start = start_of_non(1, nums, l);
        for(int i = start + 1 ; i <= r ; )
            if(i == r || nums[i] == 1){
                res -= (1 + i - start) * (i - start) / 2;
                start = start_of_non(1, nums, i);
                i = start + 1;
            }
            else
                i ++;
        return res;
    }

    int start_of_non(int target, const vector<int>& nums, int start){
        for(int i = start ; i < nums.size() ; i ++)
            if(nums[i] != target)
                return i;
        return nums.size();
    }

    void print_vec(const vector<int>& vec, int l, int r){
        for(int i = l ; i < r ; i ++)
            cout << vec[i] << " ";
        cout << endl;
    }
};

int main() {

//    vector<int> A1 = {2, 1, 4, 3};
//    cout << Solution().numSubarrayBoundedMax(A1, 2, 3) << endl;

    vector<int> A2 = {2, 9, 2, 5, 6};
    cout << Solution().numSubarrayBoundedMax(A2, 2, 8) << endl;

    return 0;
}