/// Source : https://leetcode.com/problems/first-bad-version/
/// Author : liuyubobobo
/// Time   : 2021-06-12

#include <iostream>

using namespace std;


/// Binary Search
/// Time Complexity: O(logn)
/// Space Complexity: O(1)

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        int l = 1, r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(isBadVersion(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};


int main() {

    return 0;
}
