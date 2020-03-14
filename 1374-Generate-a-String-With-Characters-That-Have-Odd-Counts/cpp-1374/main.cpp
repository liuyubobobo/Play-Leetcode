/// Source : https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
/// Author : liuyubobobo
/// Time   : 2020-03-07

#include <iostream>

using namespace std;


/// Mathematics
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string generateTheString(int n) {

        if(n % 2) return string(n, 'a');
        return string(1, 'a') + string(n - 1, 'b');
    }
};


int main() {

    return 0;
}
