/// Source : https://leetcode.com/problems/expression-add-operators/description/
/// Author : liuyubobobo
/// Time   : 2018-09-07

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;


/// Backtracking to split num and eval
/// Evaluate the expression on the fly :)
///
/// Time Complexity: O(3^n)
/// Space Complexity: O(3^n)
class Solution {
public:
    vector<string> addOperators(string num, int target) {

        if(num == "")
            return {};
        vector<string> ret;
        split(num, 0, target, "", ' ', -1, 0ll, ret);
        return ret;
    }

private:
    void split(const string& num, int index, int target, const string& expr,
               char lastop, long long pre, long long res, vector<string>& ret){

        if(index == num.size()){
            if(res == (long long)target)
                ret.push_back(expr);
            return;
        }

        int end = num.size();
        if(num[index] == '0')
            end = index + 1;

        for(int i = index + 1; i <= end; i ++){
            int len = i - index;
            string cur_num_s = num.substr(index, len);
            long long cur = atol(cur_num_s.c_str());

            char next_lastop = ' ';
            long long next_pre = cur;
            long long next_res = res;

            if(expr[expr.size() - 1] == '*' && (lastop == '+' || lastop == '-')){
                assert(pre != -1);
                if(lastop == '+')
                    next_res -= pre, next_res += pre * cur;
                else
                    next_res += pre, next_res -= pre * cur;
                next_pre = pre * cur;
                next_lastop = lastop;
            }
            else if(expr != ""){
                switch(expr[expr.size() - 1]){
                    case '+': next_res += cur; break;
                    case '-': next_res -= cur; break;
                    case '*': next_res *= cur; break;
                    default:assert(false); break;
                }
                next_lastop = expr[expr.size() - 1];
            }
            else
                next_res = cur;

            if(index + len == num.size())
                split(num, index + len, target, expr + cur_num_s,
                      ' ', next_pre, next_res, ret);
            else{
                split(num, index + len, target, expr + cur_num_s + "*",
                      next_lastop, next_pre, next_res, ret);
                split(num, index + len, target, expr + cur_num_s + "+",
                      next_lastop, next_pre, next_res, ret);
                split(num, index + len, target, expr + cur_num_s + "-",
                      next_lastop, next_pre, next_res, ret);
            }
        }
    }
};


void print_vec(const vector<string>& vec){
    cout << "[ ";
    for(const string& e: vec)
        cout << e << " ";
    cout << "]" << endl;
}

int main() {

    string nums1 = "123";
    print_vec(Solution().addOperators(nums1, 6)); //2

    string nums2 = "232";
    print_vec(Solution().addOperators(nums2, 8)); // 2

    string nums3 = "105";
    print_vec(Solution().addOperators(nums3, 5)); // 2

    string nums4 = "00";
    print_vec(Solution().addOperators(nums4, 0)); // 3

    string nums5 = "3456237490";
    print_vec(Solution().addOperators(nums5, 9191)); // 0

    string nums6 = "2147483647";
    print_vec(Solution().addOperators(nums6, 2147483647)); // 1

    string nums7 = "2147483648";
    print_vec(Solution().addOperators(nums7, -2147483648)); // 0

    string nums8 = "123456789";
    print_vec(Solution().addOperators(nums8, 45));

    return 0;
}