/// Source : https://leetcode.com/problems/minimum-moves-to-convert-string/
/// Author : liuyubobobo
/// Time   : 2021-10-02

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumMoves(string s) {

        int n = s.size(), res = 0;
        for(int i = 0; i < n; i ++){
            if(s[i] == 'X'){
                res ++;
                s[i] = 'O';
                if(i + 1 < n) s[i + 1] = 'O';
                if(i + 2 < n) s[i + 2] = 'O';
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
