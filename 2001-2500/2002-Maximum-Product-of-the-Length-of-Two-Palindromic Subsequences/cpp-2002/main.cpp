/// Source : https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/
/// Author : liuyubobobo
/// Time   : 2021-09-11

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(2^n * 3^n)
/// Space Complexity: O(2^n)
class Solution {
public:
    int maxProduct(string s) {

        int n = s.size();
        vector<bool> table(1 << n, false);
        vector<int> len(1 << n, 0);
        for(int state = 1; state < (1 << n); state ++)
            calc(s, state, n, table, len);

        int res = 0;
        for(int state = 1; state + 1 < (1 << n); state ++)
            if(table[state]){
                int u = (1 << n) - 1 - state;
                for (int s = u; s; s = (s - 1) & u)
                    if(table[s]) res = max(res, len[state] * len[s]);
            }
        return res;
    }

private:
    void calc(const string& s, int state, int n,
              vector<bool>& table, vector<int>& len){

        string t = "";
        for(int i = 0; i < n; i ++)
            if(state & (1 << i)) t += s[i];

        len[state] = t.size();

        bool is_pal = true;
        for(int i = 0, j = t.size() - 1; i < j; i ++, j --)
            if(t[i] != t[j]){
                is_pal = false;
                break;
            }
        table[state] = is_pal;
    }
};


int main() {

    cout << Solution().maxProduct("leetcodecom") << endl;
    // 9

    cout << Solution().maxProduct("bb") << endl;
    // 1

    cout << Solution().maxProduct("accbcaxxcxx") << endl;
    // 25

    return 0;
}
