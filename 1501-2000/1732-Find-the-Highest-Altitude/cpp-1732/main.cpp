/// Source : https://leetcode.com/problems/find-the-highest-altitude/
/// Author : liuyubobobo
/// Time   : 2021-01-23

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int cur = 0, res = 0;
        for(int e: gain)
            cur += e, res = max(res, cur);
        return res;
    }
};


int main() {

    return 0;
}
