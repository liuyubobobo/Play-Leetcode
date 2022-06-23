/// Source : https://leetcode.cn/contest/sf-tech/problems/8oimK4/
/// Author : liuyubobobo
/// Time   : 2022-06-23

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Compelxity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int findMaxCI(vector<int>& nums) {

        int n = nums.size();
        int res = 0;
        for(int start = 0, i = 1; i <= n; i ++)
            if(i == n || nums[i] <= nums[i - 1]){
                res = max(res, i - start);
                start = i;
                i = start;
            }
        return res;
    }
};


int main() {

    return 0;
}
