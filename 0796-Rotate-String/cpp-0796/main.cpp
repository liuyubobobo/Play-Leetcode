/// Source : https://leetcode.com/problems/rotate-string/description/
/// Author : liuyubobobo
/// Time   : 2018-03-10

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/// Brute Force
/// Time Complexity: O(N^2)
/// Space Complexity: O(N)
class Solution {
public:
    bool rotateString(string A, string B) {

        string cur = A;
        for(int i = 0 ; i < A.size() ; i ++){
            if(cur == B)
                return true;
            cur = cur.substr(1) + cur[0];
        }

        return false;
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