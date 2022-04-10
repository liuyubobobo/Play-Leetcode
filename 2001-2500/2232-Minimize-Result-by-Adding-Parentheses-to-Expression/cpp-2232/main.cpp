/// Source : https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/
/// Author : liuyubobobo
/// Time   : 2022-04-10

#include <iostream>

using namespace std;


/// Brute Force
/// Time Complexity: O(|exp|^2)
/// Space Complexity: O(|exp|)
class Solution {
public:
    string minimizeResult(string expression) {

        int add_pos = expression.find('+');
        string a = expression.substr(0, add_pos), b = expression.substr(add_pos + 1);

        long long best_exp_res = LONG_LONG_MAX;
        string best_exp = "";
        for(int l_len = 0; l_len < a.size(); l_len ++)
            for(int r_len = 1; r_len <= b.size(); r_len ++){
                long long l1 = l_len == 0 ? 1ll : atoll(a.substr(0, l_len).c_str());
                long long l2 = atoll(a.substr(l_len).c_str());
                long long r1 = atoll(b.substr(0, r_len).c_str());
                long long r2 = r_len == b.size() ? 1ll : atoll(b.substr(r_len).c_str());

                long long tres = l1 * (l2 + r1) * r2;
//                cout << l1 << ' ' << l2 << ' ' << r1 << ' ' << r2 << ' ' << tres << '\n';
                if(tres < best_exp_res){
                    string exp = a.substr(0, l_len);
                    exp += "(";
                    exp += a.substr(l_len);
                    exp += "+";
                    exp += b.substr(0, r_len);
                    exp += ")";
                    exp += b.substr(r_len);

                    best_exp = exp;
                    best_exp_res = tres;
                }
            }
        return best_exp;
    }
};


int main() {

    cout << Solution().minimizeResult("247+38") << '\n';
    // 2(47+38)

    cout << Solution().minimizeResult("12+34") << '\n';
    // 1(2+3)4

    cout << Solution().minimizeResult("999+999") << '\n';
    // (999+999)

    return 0;
}
