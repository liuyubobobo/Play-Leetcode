/// Source : https://leetcode.com/problems/find-the-original-array-of-prefix-xor/
/// Author : liuyubobobo
/// Time   : 2022-10-08

#include <iostream>
#include <vector>

using namespace std;


/// Bitwise
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {

        int n = pref.size();
        vector<int> res(n, pref[0]);
        for(int i = 1; i < n; i ++) res[i] = pref[i] ^ pref[i - 1];
        return res;
    }
};


int main() {

    return 0;
}
