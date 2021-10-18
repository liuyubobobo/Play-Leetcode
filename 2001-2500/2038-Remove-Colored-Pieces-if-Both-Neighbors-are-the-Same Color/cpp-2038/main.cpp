/// Source : https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
/// Author : liuyubobobo
/// Time   : 2021-10-17

#include <iostream>

using namespace std;


/// String Split
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool winnerOfGame(string colors) {

        int a = 0, b = 0;
        for(int start = 0, i = 1; i <= colors.size(); i ++)
            if(i == colors.size() || colors[i] != colors[start]){
                int len = i - start;
                if(len >= 3){
                    if(colors[start] == 'A') a += len - 2;
                    else b += len - 2;
                }
                start = i;
            }

        return a >= b + 1;
    }
};


int main() {

    return 0;
}
