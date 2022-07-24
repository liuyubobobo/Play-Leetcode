/// Source : https://leetcode.com/problems/first-letter-to-appear-twice/
/// Author : liuyubobobo
/// Time   : 2022-07-23

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    char repeatedCharacter(string s) {

        vector<int> f(26, 0);
        for(char c: s){
            f[c - 'a'] ++;
            if(f[c - 'a'] == 2) return c;
        }
        return 'a';
    }
};


int main() {

    return 0;
}
