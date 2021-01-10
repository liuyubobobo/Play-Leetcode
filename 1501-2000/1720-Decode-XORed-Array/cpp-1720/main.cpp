/// Source : https://leetcode.com/problems/decode-xored-array/
/// Author : liuyubobobo
/// Time   : 2021-01-09

#include <iostream>
#include <vector>

using namespace std;


/// Xor
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {

        vector<int> res(encoded.size() + 1, first);
        for(int i = 1; i < res.size(); i ++)
            res[i] = res[i - 1] ^ encoded[i - 1];
        return res;
    }
};


int main() {

    return 0;
}
