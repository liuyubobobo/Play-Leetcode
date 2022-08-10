/// Source : https://leetcode.com/problems/solve-the-equation/
/// Author : liuyubobobo
/// Time   : 2022-08-10

#include <iostream>
#include <vector>

using namespace std;


/// Parse
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string solveEquation(string equation) {

        char equal_pos = equation.find('=');
        string left = equation.substr(0, equal_pos);
        string right = equation.substr(equal_pos + 1);

        vector<int> l_res = get_res(left);
//        for(int e: l_res) cout << e << ' '; cout << '\n';
        vector<int> r_res = get_res(right);
//        for(int e: r_res) cout << e << ' '; cout << '\n';

        int k = l_res[1] - r_res[1];
        int b = r_res[0] - l_res[0];

        if(k == 0)
            return b == 0 ? "Infinite solutions" : "No solution";

        return "x=" + to_string(b / k);
    }

private:
    vector<int> get_res(const string& s){

        vector<int> res(2, 0);
        for(int start = 0, i = 1; i <= s.size(); i ++)
            if(i == s.size() || (s[i] == '+' || s[i] == '-')){
                string t = s.substr(start, i - start);
                if(t[0] == '+') t = t.substr(1);

                if(t.back() == 'x'){
                    if(t == "x") res[1] += 1;
                    else if(t == "-x") res[1] += -1;
                    else res[1] += atoi(t.substr(0, t.size() - 1).c_str());
                }
                else
                    res[0] += atoi(t.c_str());

                start = i;
            }
        return res;
    }
};


int main() {

    cout << Solution().solveEquation("x+5-3+x=6+x-2") << '\n';
    // x = 2

    cout << Solution().solveEquation("2x=x") << '\n';
    // x = 0

    cout << Solution().solveEquation("-x=-1") << '\n';
    // x = 1

    return 0;
}
