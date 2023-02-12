/// Source : https://leetcode.com/problems/find-the-array-concatenation-value/description/
/// Author : liuyubobobo
/// Time   : 2023-02-11

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(nlog(MAX_NUMS))
/// Space Complexity: O(log(MAX_NUMS))
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {

        int n = nums.size();
        long long res = 0;
        for(int i = 0, j = n - 1; i <= j; i ++, j --){
            if(i == j) res += nums[i];
            else{
                long long a = nums[i], b = nums[j];
                string a_str = to_string(a), b_str = to_string(b);
                res += atoll((a_str + b_str).c_str());
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
