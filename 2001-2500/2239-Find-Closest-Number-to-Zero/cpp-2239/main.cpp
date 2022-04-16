/// Source : https://leetcode.com/problems/find-closest-number-to-zero/
/// Author : liuyubobobo
/// Time   : 2022-04-16

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// Linear Search
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {

        int best = INT_MAX, res = 0;
        for(int e: nums){
            if(abs(e) < best) res = e, best = abs(e);
            else if(abs(e) == best) res = max(res, e);
        }
        return res;
    }
};


int main() {

    return 0;
}
