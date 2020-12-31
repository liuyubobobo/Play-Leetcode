/// Source : https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
/// Author : liuyubobobo
/// Time   : 2019-08-11

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;


/// Random Algorithm
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {

        int n = A.size();
        while(true){
            int i = rand() % n, j = rand() % n;
            if(i != j && A[i] == A[j]) return A[i];
        }
        assert(false);
        return -1;
    }
};


int main() {

    return 0;
}