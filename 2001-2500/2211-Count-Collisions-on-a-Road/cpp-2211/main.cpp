/// Source : https://leetcode.com/problems/count-collisions-on-a-road/
/// Author : liuyubobobo
/// Time   : 2022-03-19

#include <iostream>
#include <vector>

using namespace std;


/// Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int countCollisions(string directions) {

        int res = 0;
        string stack = "";
        for(char c: directions)
            if(c == 'R') stack += c;
            else if(c == 'L'){
                if(stack.empty()) continue;
                else if(stack.back() == 'R'){
                    res += 2, stack.pop_back();
                    while(!stack.empty() && stack.back() == 'R') res ++, stack.pop_back();
                    stack += 'S';
                }
                else res ++;
            }
            else if(c == 'S'){
                if(stack.empty()) stack += 'S';
                else if(stack.back() == 'R'){
                    while(!stack.empty() && stack.back() == 'R') res ++, stack.pop_back();
                    stack += 'S';
                }
            }
        return res;
    }
};


int main() {

    cout << Solution().countCollisions("RLRSLL") << '\n';
    // 5

    cout << Solution().countCollisions("LLRR") << '\n';
    // 0

    cout << Solution().countCollisions("SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR") << '\n';
    // 20

    return 0;
}
