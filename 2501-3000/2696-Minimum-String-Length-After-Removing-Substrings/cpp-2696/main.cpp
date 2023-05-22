/// Source : https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/
/// Author : liuyubobobo
/// Time   : 2023-05-21

#include <iostream>
#include <string>

using namespace std;


/// Brute Force
/// Time Complexity: O(|s|^2)
/// Space Complexity: O(|s|)
class Solution {
public:
    int minLength(string s) {

        while(true){
            bool flag = false;
            if(s.find("AB") != string::npos)
                s.replace(s.find("AB"), 2, ""), flag = true;
            if(s.find("CD") != string::npos)
                s.replace(s.find("CD"), 2, ""), flag = true;
            if(!flag) break;
        }
        return s.size();
    }
};


int main() {

    return 0;
}
