/// Source : https://leetcode.com/problems/gray-code/
/// Author : liuyubobobo
/// Time   : 2019-11-06

#include <iostream>
#include <vector>

using namespace std;


/// Gray Code Xor Formula
/// Time Complexity: O(2^n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> grayCode(int n) {

        vector<int> res;
        for(int i = 0; i < (1 << n); i ++)
            res.push_back(i ^ (i >> 1));
        return res;
    }
};


int main() {

    return 0;
}