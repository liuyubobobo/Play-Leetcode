/// Source : https://leetcode.com/problems/sort-array-by-parity/solution/
/// Author : liuyubobobo
/// Time   : 2018-09-15

#include <iostream>
#include <vector>

using namespace std;


/// Two Pass
/// Time Complexity : O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {

        vector<int> ret;
        for(int a: A)
            if(a % 2 == 0)
                ret.push_back(a);
        for(int a: A)
            if(a % 2)
                ret.push_back(a);
        return ret;
    }
};


int main() {

    return 0;
}