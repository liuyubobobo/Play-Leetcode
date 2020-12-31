/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : liuyubobobo
/// Time   : 2019-05-18

#include <iostream>

using namespace std;


/// Using Stack
/// Time Complexity: O(|S|)
/// Space Complexity: O(1)
class Solution {
public:
    string removeDuplicates(string S) {

        string res = "";
        for(char c: S)
            if(!res.size() || res.back() != c)
                res += c;
            else
                res.pop_back();
        return res;
    }
};


int main() {

    return 0;
}