/// Source : https://leetcode.com/problems/remove-k-digits/
/// Author : liuyubobobo
/// Time   : 2020-05-21

#include <iostream>
#include <stack>

using namespace std;


/// Monotone Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {

        string res = "";
        for(int i = 0; i < num.size(); i ++){
            while(res.size() && res.back() > num[i] && k){
                res.pop_back();
                k --;
            }
            res += num[i];
        }

        while(k) res.pop_back(), k --;

        int start = 0;
        while(start < res.size() && res[start] == '0') start ++;
        res = res.substr(start);

        return res.size() ? res : "0";
    }
};


int main() {

    cout << Solution().removeKdigits("10", 2) << endl;
    // 0

    cout << Solution().removeKdigits("112", 1) << endl;
    // 11

    return 0;
}
