/// Source : https://leetcode.com/problems/fizz-buzz/description/
/// Author : liuyubobobo
/// Time   : 2018-09-23

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<string> fizzBuzz(int n) {

        vector<string> ret;
        for(int i = 1; i <= n; i ++)
            if(i % 15 == 0)
                ret.push_back("FizzBuzz");
            else if(i % 3 == 0)
                ret.push_back("Fizz");
            else if(i % 5 == 0)
                ret.push_back("Buzz");
            else
                ret.push_back(to_string(i));
        return ret;
    }
};


int main() {

    return 0;
}