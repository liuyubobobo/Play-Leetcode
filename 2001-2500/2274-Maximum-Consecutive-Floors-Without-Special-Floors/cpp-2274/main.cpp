/// Source : https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/
/// Author : liuyubobobo
/// Time   : 2022-05-15

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Linear Scan
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {

        special.push_back(top + 1);
        sort(special.begin(), special.end());

        int res = 0;
        for(int cur = bottom, i = 0; i < special.size(); i ++){
            res = max(res, special[i] - cur);
            cur = special[i] + 1;
        }
        return res;
    }
};


int main() {

    return 0;
}
