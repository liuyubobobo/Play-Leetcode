/// Source : https://leetcode.com/problems/1-bit-and-2-bit-characters/description/
/// Author : liuyubobobo
/// Time   : 2017-10-28

#include <iostream>
#include <vector>

using namespace std;

/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {

        int i;
        for(i = 0 ; i < bits.size() ; )
            if(i == bits.size() - 1)
                return true;
            else{
                if(bits[i] == 0)
                    i += 1;
                else
                    i += 2;
            }

        return false;
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