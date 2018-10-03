/// Source : https://leetcode.com/problems/count-and-say/description/
/// Author : liuyubobobo
/// Time   : 2018-10-03

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(n * 2^n)
/// Space Complexity: O(2^n)
class Solution {
public:
    string countAndSay(int n) {

        string s = "1";
        if(n == 1)
            return s;

        for(int i = 2; i <= n; i ++)
            s = next(s);
        return s;
    }

private:
    string next(const string& s){

        string ret = "";
        int start = 0;
        for(int i = start + 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] != s[start]){
                ret += to_string(i - start) + s[start];
                start = i;
            }
        return ret;
    }
};


int main() {

    cout << Solution().countAndSay(1) << endl;
    cout << Solution().countAndSay(2) << endl;
    cout << Solution().countAndSay(3) << endl;
    cout << Solution().countAndSay(4) << endl;
    cout << Solution().countAndSay(5) << endl;
    cout << Solution().countAndSay(30) << endl;

    return 0;
}