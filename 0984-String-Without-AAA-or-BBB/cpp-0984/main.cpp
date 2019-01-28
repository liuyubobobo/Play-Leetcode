/// Source : https://leetcode.com/problems/string-without-aaa-or-bbb/
/// Author : liuyubobobo
/// Time   : 2019-01-26

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(A + B)
/// Space Complexity: O(1)
class Solution {
public:
    string strWithout3a3b(int A, int B) {

        if(A > B)
            return get_str(A - B, "a", B, "ab");
        return get_str(B - A, "b", A, "ba");
    }

private:
    string get_str(int k1, const string& s1, int k2, const string& s2){
        string res = "";
        while(k1 -- && k2 --) res += s1 + s2;
        while(k2 --) res += s2;
        while(k1 --) res += s1;
        return res;
    }
};


int main() {

    return 0;
}