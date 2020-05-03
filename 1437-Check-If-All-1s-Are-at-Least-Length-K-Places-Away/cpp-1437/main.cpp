/// Source : https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        for(int start = -1, i = 0; i < nums.size(); i ++)
            if(nums[i] == 1){
                if(start >= 0 && i - start - 1 < k) return false;
                start = i;
            }
        return true;
    }
};


int main() {

    return 0;
}
