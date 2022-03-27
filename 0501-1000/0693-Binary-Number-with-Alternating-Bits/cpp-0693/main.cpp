/// Source : https://leetcode.com/problems/binary-number-with-alternating-bits/
/// Author : liuyubobobo
/// Time   : 2022-03-27

#include <iostream>
#include <vector>

using namespace std;


/// int to binary
/// Time Complexity: O(logn)
/// Space Complexity: O(logn)
class Solution {
public:
    bool hasAlternatingBits(int n) {

        vector<int> binary;
        while(n)
            binary.push_back(n & 1), n >>= 1;

        for(int i = 1; i < binary.size(); i ++)
            if(binary[i] == binary[i - 1]) return false;
        return true;
    }
};


int main() {


    return 0;
}
