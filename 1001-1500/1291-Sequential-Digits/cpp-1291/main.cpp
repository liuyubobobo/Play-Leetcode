/// Source : https://leetcode.com/problems/sequential-digits/
/// Author : liuyubobobo
/// Time   : 2022-01-22

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int> res;
        for(int start = 1; start < 9; start ++){
            long long cur = 0;
            for(int d = start; d <= 9 && cur <= high; d ++){
                cur = cur * 10 + d;
                if(cur >= low && cur <= high) res.push_back(cur);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};


int main() {

    return 0;
}
