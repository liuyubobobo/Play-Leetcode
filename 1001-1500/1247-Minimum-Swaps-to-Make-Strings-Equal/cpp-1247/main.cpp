/// Source : https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/description/
/// Author : liuyubobobo
/// Time   : 2023-02-24

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumSwap(string s1, string s2) {

        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        for(char c: s1) if(c == 'x') x1 ++; else y1 ++;
        for(char c: s2) if(c == 'x') x2 ++; else y2 ++;

        if((x1 + x2) & 1) return -1;
        if((y1 + y2) & 1) return -1;

        int xy = 0, yx = 0;
        for(int i = 0; i < s1.size(); i ++){
            if(s1[i] == 'x' && s2[i] == 'y') xy ++;
            if(s1[i] == 'y' && s2[i] == 'x') yx ++;
        }

        int res = 0;
        res += xy / 2; xy %= 2;
        res += yx / 2; yx %= 2;
        if(xy){
            assert(yx);
            res += 2;
        }
        return res;
    }
};


int main() {

    return 0;
}
