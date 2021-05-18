/// Source : https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/
/// Author : liuyubobobo
/// Time   : 2021-05-15

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Compelxity: O(|s|)
/// Space Complexity: O(|s|)
class Solution {
public:
    int minSwaps(string s) {

        int n = s.size();

        string a = "";
        for(int i = 0; i < n; i ++)
            a += ('0' + (i % 2));
        int ares = solve(s, a);

        string b = "";
        for(int i = 0; i < n; i ++)
            b += ('0' + (1 - i % 2));
        int bres = solve(s, b);

        int res = min(ares, bres);
        return res == INT_MAX ? -1 : res;
    }

private:
    int solve(const string& s, const string& t){

        int one = 0, zero = 0;
        for(int i = 0; i < s.size(); i ++)
            if(s[i] != t[i]){
                if(s[i] == '1') one ++;
                else zero ++;
            }

        return one == zero ? one : INT_MAX;
    }
};


int main() {

    cout << Solution().minSwaps("111000") << endl;
    // 1

    cout << Solution().minSwaps("010") << endl;
    // 0

    cout << Solution().minSwaps("1110") << endl;
    // -1

    return 0;
}
