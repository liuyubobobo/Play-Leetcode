/// Source : https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/
/// Author : liuyubobobo
/// Time   : 2023-01-14

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Compelxity: O(nlog(max_num))
/// Space Complexity: O(1)
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {

        int sum1 = 0, sum2 = 0;
        for(int num: nums){
            sum1 += num;
            while(num) sum2 += num % 10, num /= 10;
        }
        return abs(sum1 - sum2);
    }
};


int main() {

    return 0;
}
