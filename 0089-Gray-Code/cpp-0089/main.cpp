/// Source : https://leetcode.com/problems/gray-code/
/// Author : liuyubobobo
/// Time   : 2019-11-05

#include <iostream>
#include <vector>

using namespace std;


/// Recursion
/// Time Complexity: O(2^n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> grayCode(int n) {

        if(n == 0) return {0};

        vector<int> res = grayCode(n - 1);
        for(int i = res.size() - 1; i >= 0; i --)
            res.push_back((1 << (n - 1)) + res[i]);
        return res;
    }
};


int main() {

    return 0;
}