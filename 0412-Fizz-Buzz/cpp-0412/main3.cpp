/// Source : https://leetcode.com/problems/fizz-buzz/description/
/// Author : liuyubobobo
/// Time   : 2018-09-23

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map to make the logic more clear
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<string> fizzBuzz(int n) {

        map<int, string> map = {{3, "Fizz"}, {5, "Buzz"}};

        vector<string> ret;
        for(int i = 1; i <= n; i ++){
            string s = "";
            for(const pair<int, string>& p: map)
                if(i % p.first == 0)
                    s += p.second;

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