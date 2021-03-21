/// Source : https://leetcode.com/problems/second-largest-digit-in-a-string/
/// Author : liuyubobobo
/// Time   : 2021-03-21

#include <iostream>
#include <set>

using namespace std;


/// Only the first two largest number recorded
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int secondHighest(string s) {

        int a = -1, b = -1;
        for(char c: s)
            if(isdigit(c)){
                int t = c - '0';
                if(t > a) b = a, a = t;
                else if(t != a && t > b) b = t;
            }
        return b;
    }
};


int main() {

    cout << Solution().secondHighest("ck077") << endl;
    // 0

    return 0;
}
