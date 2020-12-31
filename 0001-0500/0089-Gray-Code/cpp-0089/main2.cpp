/// Source : https://leetcode.com/problems/gray-code/
/// Author : liuyubobobo
/// Time   : 2019-11-05

#include <iostream>
#include <vector>

using namespace std;


/// Recurrence
/// Time Complexity: O(2^n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> grayCode(int n) {

        vector<int> res = {0};
        for(int i = 0; i < n; i ++){
            for(int j = res.size() - 1; j >= 0; j --)
                res.push_back((1 << i) + res[j]);
        }
        return res;
    }
};


int main() {

    return 0;
}