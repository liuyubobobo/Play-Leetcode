/// Source : https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
/// Author : liuyubobobo
/// Time   : 2021-09-18

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {

        int x = 0;
        for(const string& op: operations)
            if(op[1] == '+') x ++;
            else x --;
        return x;
    }
};


int main() {

    return 0;
}
