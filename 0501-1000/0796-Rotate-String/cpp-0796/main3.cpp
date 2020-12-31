/// Source : https://leetcode.com/problems/rotate-string/description/
/// Author : liuyubobobo
/// Time   : 2018-03-11

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/// Brute Force
/// The easiest implementation:)
///
/// Time Complexity: O(N^2)
/// Space Complexity: O(N)
class Solution {
public:
    bool rotateString(string A, string B) {

        if(A.size() != B.size())
            return false;

        return (A + A).find(B) != string::npos;
    }
};

void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}


int main() {

    string A1 = "abcde";
    string B1 = "cdeab";
    print_bool(Solution().rotateString(A1, B1));

    string A2 = "abcde";
    string B2 = "abced";
    print_bool(Solution().rotateString(A2, B2));

    return 0;
}