/// Source : https://leetcode.com/problems/array-nesting/
/// Author : liuyubobobo
/// Time   : 2021-09-01

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int arrayNesting(vector<int>& nums) {

        int n = nums.size();
        vector<bool> visited(n, false);
        int res = 0;
        for(int i = 0; i < n; i ++)
            if(!visited[i]){
                int cur = nums[i], len = 1;
                visited[i] = true;
                while(cur != i){
                    cur = nums[cur], len ++;
                    visited[cur] = true;
                }
                res = max(res, len);
            }
        return res;
    }
};


int main() {

    return 0;
}
