/// Source : https://leetcode.com/problems/goal-parser-interpretation/
/// Author : liuyubobobo
/// Time   : 2020-12-05

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string interpret(string command) {

        string res = "";
        for(int i = 0; i < command.size(); i ++)
            if(command[i] == 'G') res += 'G';
            else if(command[i + 1] == ')') res += 'o', i ++;
            else res += "al", i += 3;
        return res;
    }
};


int main() {

    cout << Solution().interpret("G()()()()(al)") << endl;
    // Gooooal

    cout << Solution().interpret("(al)G(al)()()G") << endl;
    // alGalooG

    return 0;
}
