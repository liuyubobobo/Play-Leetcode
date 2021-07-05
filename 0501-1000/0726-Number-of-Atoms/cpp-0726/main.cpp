/// Source : https://leetcode.com/problems/number-of-atoms/
/// Author : liuyubobobo
/// Time   : 2021-07-03

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cassert>

using namespace std;


/// DFS
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    string countOfAtoms(string formula) {

        int n = formula.size();

        vector<int> right(n, -1);
        stack<int> stack;
        for(int i = 0; i < n; i ++)
            if(formula[i] == '(') stack.push(i);
            else if(formula[i] == ')'){
                assert(!stack.empty());
                right[stack.top()] = i;
                stack.pop();
            }
        assert(stack.empty());

        map<string, int> res = dfs(formula, 0, n - 1, right);

        string ret = "";
        for(const pair<string, int>& p: res){
            ret += p.first;
            if(p.second > 1) ret += to_string(p.second);
        }
        return ret;
    }

    map<string, int> dfs(const string& s, int l, int r, const vector<int>& right){

        if(l > r) return {};

        map<string, int> res;
        for(int i = l; i <= r; ){
            if(s[i] == '('){
                map<string, int> tres = dfs(s, i + 1, right[i] - 1, right);
                i = right[i] + 1;

                int a = 1;
                if(i < s.size() && isdigit(s[i])){
                    int next_non_digit = get_next_non_digit(s, i);
                    a = atoi(s.substr(i, next_non_digit - i).c_str());

                    i = next_non_digit;
                }

                for(const pair<string, int>& p: tres)
                    res[p.first] += p.second * a;
            }
            else{
                int next_pos = get_next_e_char(s, i);
                string e = s.substr(i, next_pos - i);

                i = next_pos;
                if(i < s.size() && isdigit(s[i])){
                    int next_non_digit = get_next_non_digit(s, i);
                    int v = atoi(s.substr(i, next_non_digit - i).c_str());

                    res[e] += v;
                    i = next_non_digit;
                }
                else{
                    res[e] += 1;
                }
            }
        }
        return res;
    }

private:
    int get_next_e_char(const string& s, int start){

        for(int i = start + 1; i < s.size(); i ++)
            if(!islower(s[i])) return i;
        return s.size();
    }

    int get_next_non_digit(const string& s, int start){

        for(int i = start; i < s.size(); i ++)
            if(!isdigit(s[i])) return i;
        return s.size();
    }
};


int main() {

    cout << Solution().countOfAtoms("H2O") << endl;
    // H2O

    cout << Solution().countOfAtoms("Mg(OH)2") << endl;
    // H2MgO2

    cout << Solution().countOfAtoms("K4(ON(SO3)2)2") << endl;
    // K4N2O14S4

    cout << Solution().countOfAtoms("Be32") << endl;
    // Be32

    return 0;
}
