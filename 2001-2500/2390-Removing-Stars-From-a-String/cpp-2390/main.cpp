/// Source : https://leetcode.com/problems/removing-stars-from-a-string/
/// Author : liuyubobobo
/// Time   : 2022-08-27

#include <iostream>
#include <vector>

using namespace std;


/// Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string removeStars(string s) {

        string res = "";
        for(char c: s){
            if(c != '*') res += c;
            else if(!res.empty()) res.pop_back();
        }
        return res;
    }
};


int main() {

    return 0;
}
