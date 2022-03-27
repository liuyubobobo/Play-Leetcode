/// Source : https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/
/// Author : liuyubobobo
/// Time   : 2022-03-26

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minDeletion(vector<int>& nums) {

        vector<int> v;
        int res = 0;
        for(int e: nums)
            if(v.size() % 2 == 0) v.push_back(e);
            else if(e == v.back()) res ++;
            else v.push_back(e);

        if(v.size() % 2 == 1) res ++;
        return res;
    }
};


int main() {

    return 0;
}
