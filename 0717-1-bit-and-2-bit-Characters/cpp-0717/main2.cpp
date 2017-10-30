/// Source : https://leetcode.com/problems/1-bit-and-2-bit-characters/description/
/// Author : liuyubobobo
/// Time   : 2017-10-28

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Calculate the number of 1 between the last two 0
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {

        assert(bits.back() == 0);
        int i;
        for(i = bits.size() - 2 ; i >= 0 && bits[i] == 1; i --);

        return (bits.size() - 1 - (i + 1)) % 2 == 0;
    }
};


void printBool(bool res){
    cout << (res ? "true" : "false") << endl;
}

int main() {

    int bits1[] = {1, 0, 0};
    vector<int> vec1(bits1, bits1 + sizeof(bits1)/sizeof(int));
    printBool(Solution().isOneBitCharacter(vec1));

    int bits2[] = {1, 1, 1, 0};
    vector<int> vec2(bits2, bits2 + sizeof(bits2)/sizeof(int));
    printBool(Solution().isOneBitCharacter(vec2));

    return 0;
}