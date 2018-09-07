/// Source : https://leetcode.com/problems/basic-calculator-iii/description/
/// Author : liuyubobobo
/// Time   : 2018-09-07

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;


/// Two Stacks
/// Shunting-Yard Algorithms: https://en.wikipedia.org/wiki/Shunting-yard_algorithm
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    unordered_set<char> opset = {'+', '-', '*', '/', '(', ')'};

public:
    int calculate(string s) {

        if(s == "")
            return 0;

        vector<int> nums;
        vector<char> ops;

        for(int i = 0; i < s.size(); i ++) {
            if(s[i] == ' ')
                continue;

            if(opset.count(s[i])){
                if(s[i] == ')'){
                    vector<int> tnums = {nums.back()};
                    nums.pop_back();
                    vector<char> tops;
                    while(ops.back() != '('){
                        tnums.push_back(nums.back());
                        nums.pop_back();
                        tops.push_back(ops.back());
                        ops.pop_back();
                    }
                    reverse(tnums.begin(), tnums.end());
                    reverse(tops.begin(), tops.end());
                    nums.push_back(order_calc(tnums, tops));

                    assert(ops.back() == '(');
                    ops.pop_back();
                    if(!ops.empty() && (ops.back() == '*' || ops.back() == '/'))
                        calcTwo(nums, ops);
                    assert(ops.empty() || ops.back() == '+' || ops.back() == '-' || ops.back() == '(');
                }
                else
                    ops.push_back(s[i]);
            }
            else{
                int num = s[i] - '0';
                int j;
                for(j = i + 1; j < s.size() && isdigit(s[j]); j ++)
                    num = num * 10 + (s[j] - '0');
                i = j - 1;

                nums.push_back(num);
                if(!ops.empty() && (ops.back() == '*' || ops.back() == '/'))
                    calcTwo(nums, ops);
            }
        }

        return order_calc(nums, ops);
    }

private:
    void calcTwo(vector<int>& nums, vector<char>& ops){
        assert(nums.size() >= 2);
        int second = nums.back();
        nums.pop_back();
        int first = nums.back();
        nums.pop_back();

        char op = ops.back();
        ops.pop_back();
        nums.push_back(calc(first, second, op));
        return;
    }

    int calc(int a, int b, char op){
        switch(op){
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: assert(false); return -1;
        }
    }

    int order_calc(const vector<int>& nums, const vector<char>& ops){

        assert(nums.size() == ops.size() + 1);
        int res = nums[0];
        for(int i = 0; i < ops.size(); i ++)
            res = calc(res, nums[i + 1], ops[i]);
        return res;
    }
};


int main() {

    cout << Solution().calculate("1 + 1") << endl;
    // 2

    cout << Solution().calculate(" 6-4 / 2 ") << endl;
    // 4

    cout << Solution().calculate("2*(5+5*2)/3+(6/2+8)") << endl;
    // 21

    cout << Solution().calculate("(2+6* 3+5- (3*14/7+2)*5)+3") << endl;
    // -12

    cout << Solution().calculate("((  (  (   1  *  10  )  -(  3 * 8) )   *   3  )   *   1   )") << endl;
    // -42

    cout << Solution().calculate("2-4-(8+2-6+(8+4-(1)+8-10))") << endl;
    // -15

    return 0;
}