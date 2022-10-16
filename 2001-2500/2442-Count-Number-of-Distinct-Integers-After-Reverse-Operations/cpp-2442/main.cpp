/// Source : https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/
/// Author : liuyubobobo
/// Time   : 2022-10-15

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


/// Simulation
/// Time Complexity: O(nlog(max_nums))
/// Space Complexity: O(n)
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {

        set<int> s(nums.begin(), nums.end());
        for(int e: nums){
            string e_str = to_string(e);
            reverse(e_str.begin(), e_str.end());
            s.insert(atoi(e_str.c_str()));
        }
        return s.size();
    }
};


int main() {

    return 0;
}
