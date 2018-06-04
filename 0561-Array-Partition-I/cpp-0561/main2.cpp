/// Source : https://leetcode.com/problems/array-partition-i/solution/
/// Author : liuyubobobo
/// Time   : 2018-06-04

#include <iostream>
#include <vector>

using namespace std;

/// Using HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {

        int hash[20001];
        memset(hash, 0, sizeof(hash));

        for(int num: nums)
            hash[num + 10000] ++;

        int sum = 0;
        bool minus = false;
        for(int i = 0 ; i <= 20000 ; i ++)
            if(hash[i]){
                if(minus){
                    hash[i] --;
                    minus = false;
                }
                sum += hash[i] / 2 * (i - 10000);
                if(hash[i] % 2){
                    sum += (i - 10000);
                    minus = true;
                }
            }
        return sum;
    }
};


int main() {

    vector<int> nums = {1, 4, 3, 2};
    cout << Solution().arrayPairSum(nums) << endl;

    return 0;
}