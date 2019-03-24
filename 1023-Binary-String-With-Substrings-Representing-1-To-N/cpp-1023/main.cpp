/// Source : https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/
/// Author : liuyubobobo
/// Time   : 2019-03-23

#include <iostream>

using namespace std;


/// Brute Force
/// Time Complexity: O(|S|^2)
/// Space Complexity: O(logN)
class Solution {
public:
    bool queryString(string S, int N) {

        int n = S.size();
        for(int i = N; i >= 1; i --){

            string s = get_binary_string(i);
            if(S.find(s) == string::npos)
                return false;
        }
        return true;
    }

private:
    string get_binary_string(int x){

        string ret = "";
        while(x){
            ret += ('0' + x % 2);
            x /= 2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};


int main() {

    return 0;
}