/// Source : https://leetcode.com/problems/fizz-buzz/description/
/// Author : liuyubobobo
/// Time   : 2018-09-23

#include <iostream>
#include <vector>

using namespace std;


/// Using String Concatenation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<string> fizzBuzz(int n) {

        vector<string> ret;
        for(int i = 1; i <= n; i ++){
            string s = "";
            if(i % 3 == 0)
                s += "Fizz";
            if(i % 5 == 0)
                s += "Buzz";

            if(s == "")
                s = to_string(i);

            ret.push_back(s);
        }
        return ret;
    }
};


int main() {

    return 0;
}