/// Source : https://leetcode.com/problems/rotate-string/description/
/// Author : liuyubobobo
/// Time   : 2018-03-11

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/// Brute Force
/// No more actual space:)
///
/// Time Complexity: O(N^2)
/// Space Complexity: O(1)
class Solution {
public:
    bool rotateString(string A, string B) {

        if(A.size() != B.size())
            return false;

        for(int offset = 0; offset < A.size(); offset ++){
            int i = 0;
            for(i = 0 ; i < B.size() ; i ++)
                if(B[i] != A[(i + offset)%A.size()])
                    break;
            if(i == B.size())
                return true;
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