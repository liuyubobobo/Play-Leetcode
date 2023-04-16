/// Source : https://leetcode.com/problems/minimum-additions-to-make-valid-string/description/
/// Author : liuyubobobo
/// Time   : 2023-04-15

#include <iostream>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int addMinimum(string word) {

        int n = word.size(), next = 0, index = 0, res = 0;
        while(index < n) {
            int cur = word[index] - 'a';
            if(next == cur)
                index ++;
            else res ++;
            next = (next + 1) % 3;
        }

        while(next != 0) res ++, next = (next + 1) % 3;
        return res;
    }
};

int main() {

    return 0;
}
