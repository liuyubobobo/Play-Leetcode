/// Source : https://leetcode.com/problems/binary-prefix-divisible-by-5/
/// Author : liuyubobobo
/// Time   : 2019-03-30

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {

        int n = A.size();
        vector<bool> res;

        int a = 0;
        for(int e: A){
            a = a * 2 + e;
            res.push_back(a % 5 == 0);
            a %= 10;
        }
        return res;
    }
};


int main() {

    return 0;
}