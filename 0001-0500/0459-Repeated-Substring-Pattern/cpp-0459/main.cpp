/// Source : https://leetcode.com/problems/repeated-substring-pattern/description/
/// Author : liuyubobobo
/// Time   : 2023-08-21

#include <iostream>

using namespace std;


/// Brute Force
/// Time Complexity: O(sqrt(n) * n)
/// Space Complexity: O(n)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        int n = s.size();
        if(n == 1) return false;
        for(int i = 1; i * i <= n; i ++){
            if(n % i) continue;

            if(ok(n, s, i)) return true;

            if(i * i == n || i == 1) continue;
            if(ok(n, s, n / i)) return true;
        }
        return false;
    }

private:
    bool ok(int n, const string& s, int len){
        string subs = s.substr(0, len);
        for(int i = len; i <= n - len; i += len)
            if(s.substr(i, len) != subs) return false;
        return true;
    }
};


int main() {

    return 0;
}
