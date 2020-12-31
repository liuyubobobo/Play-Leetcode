/// Source : https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
/// Author : liuyubobobo
/// Time   : 2020-05-30

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {

        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return target == arr;
    }
};


int main() {

    return 0;
}
