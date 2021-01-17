/// Source : https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/
/// Author : liuyubobobo
/// Time   : 2021-01-17

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {

        int maxLen = 0, res = 0;
        for(const vector<int>& rec: rectangles){
            int len = min(rec[0], rec[1]);
            if(len > maxLen) maxLen = len, res = 1;
            else if(len == maxLen) res ++;
        }
        return res;
    }
};


int main() {

    return 0;
}
