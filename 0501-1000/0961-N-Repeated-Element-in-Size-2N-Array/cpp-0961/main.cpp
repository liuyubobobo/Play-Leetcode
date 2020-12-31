/// Source : https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
/// Author : liuyubobobo
/// Time   : 2019-08-11

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;


/// Using HashMap to get the frequency
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {

        unordered_map<int, int> freq;
        for(int e: A){
            freq[e] ++;
            if(freq[e] == A.size() / 2) return e;
        }
        assert(false);
        return -1;
    }
};


int main() {

    return 0;
}