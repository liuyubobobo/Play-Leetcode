/// Source : https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/
/// Author : liuyubobobo
/// Time   : 2022-07-31

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using Set
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        set<int> s;
        for(int e: nums)
            if(e) s.insert(e);
        return s.size();
    }
};


int main() {

    return 0;
}
