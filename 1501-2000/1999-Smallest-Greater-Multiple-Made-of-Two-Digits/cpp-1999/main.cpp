/// Source : https://leetcode.com/problems/smallest-greater-multiple-made-of-two-digits/
/// Author : liuyubobobo
/// Time   : 2021-09-12

#include <iostream>

using namespace std;


/// Brute Force
/// Time Complexity: O(2^(k + 1))
/// Space Complexity: O(1)
class Solution {
public:
    int findInteger(int k, int digit1, int digit2) {

        int res = INT_MAX;
        for(int len = 1; len <= 10 && res == INT_MAX; len ++){
            for(int state = 0; state < (1 << len); state ++){
                string s = generate(len, state, digit1, digit2);
                if(len == 10 && s > "2147483647") continue;
                int num = atoi(s.c_str());
                if(num > k && num % k == 0) res = min(res, num);
            }
        }
        return res == INT_MAX ? -1 : res;
    }

private:
    string generate(int len, int state, int d1, int d2){

        string s(len, ' ');
        for(int i = 0; i < len; i ++){
            s[i] = '0' + (state % 2 ? d1 : d2);
            state /= 2;
        }
        return s;
    }
};


int main() {

    cout << Solution().findInteger(2, 0, 2) << endl;
    // 20

    cout << Solution().findInteger(3, 4, 2) << endl;
    // 24

    cout << Solution().findInteger(2, 0, 0) << endl;
    // -1

    cout << Solution().findInteger(1, 0, 4) << endl;
    // 4

    return 0;
}
