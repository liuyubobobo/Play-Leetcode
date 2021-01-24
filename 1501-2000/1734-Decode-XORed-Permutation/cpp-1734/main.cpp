/// Source : https://leetcode.com/problems/decode-xored-permutation/
/// Author : liuyubobobo
/// Time   : 2021-01-23

#include <iostream>
#include <vector>

using namespace std;


/// Xor
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {

        int n = encoded.size() + 1;

        int start = 0;
        for(int i = 1; i <= n; i ++) start ^= i;
        for(int i = 1; i < encoded.size(); i += 2)
            start ^= encoded[i];

        vector<int> res = {start};
        for(int code: encoded)
            res.push_back(res.back() ^ code);
        return res;
    }
};


int main() {

    return 0;
}
