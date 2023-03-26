/// Source : https://leetcode.com/problems/maximize-greatness-of-an-array/description/
/// Author : liuyubobobo
/// Time   : 2023-03-25

#include <iostream>
#include <set>
#include <vector>

using namespace std;


/// Greedy
/// Time Compelxity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {

        multiset<int> s(nums.begin(), nums.end());

        int res = 0;
        for(int e: nums){
            auto iter = s.upper_bound(e);
            if(iter != s.end()){
                res ++; s.erase(iter);
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
