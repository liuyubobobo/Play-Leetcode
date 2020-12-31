/// Source : https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
/// Author : liuyubobobo
/// Time   : 2019-08-11

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;


/// Using HashSet to check repeating
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {

        unordered_set<int> set;
        for(int e: A)
            if(set.count(e)) return e;
            else set.insert(e);
        assert(false);
        return -1;
    }
};


int main() {

    return 0;
}