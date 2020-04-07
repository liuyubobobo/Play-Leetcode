/// Source : https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
/// Author : liuyubobobo
/// Time   : 2020-04-04

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int numSteps(string s) {

        int res = 0;
        while(s != "1"){
            if(s.back() == '1') s = addone(s);
            else s = s.substr(0, s.size() - 1);
            res ++;
        }
        return res;
    }

private:
    string addone(string s){

        reverse(s.begin(), s.end());
        s[0] += 1;
        int carry = 0;
        for(int i = 0; i < s.size(); i ++){
            s[i] += carry;
            if(s[i] == '2') s[i] = '0', carry = 1;
            else carry = 0;
        }

        if(carry) s += '1';
        reverse(s.begin(), s.end());
        return s;
    }
};


int main() {

    cout << Solution().numSteps("1101") << endl;
    // 6

    cout << Solution().numSteps("10") << endl;
    // 1

    return 0;
}
