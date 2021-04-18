/// Source : https://leetcode.com/problems/check-if-the-sentence-is-pangram/
/// Author : liuyubobobo
/// Time   : 2021-04-17

#include <iostream>
#include <vector>

using namespace std;


/// Hash Map
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool checkIfPangram(string sentence) {

        vector<int> f(26, 0);
        for(char c: sentence)
            f[c - 'a'] ++;

        for(int e: f)
            if(!e) return false;
        return true;
    }
};


int main() {

    return 0;
}
