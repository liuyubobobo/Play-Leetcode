/// Source : https://leetcode.com/problems/basic-calculator/description/
/// Author : liuyubobobo
/// Time   : 2018-09-03
/// Updated: 2022-11-20

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Two Stacks
/// Shunting-Yard Algorithms: https://en.wikipedia.org/wiki/Shunting-yard_algorithm
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int calculate(string s2) {

        string s;
        for(char c: s2) if(c != ' ') s += c;

        int n = s.size();
        vector<int> right(n, -1);
        vector<int> left;
        for(int i = 0; i < n; i ++) {
            if (s[i] == '(') left.push_back(i);
            else if (s[i] == ')') right[left.back()] = i, left.pop_back();
        }

        return parse(s, 0, n - 1, right);
    }

private:
    int parse(const string& s, int l, int r, const vector<int>& right){

        vector<int> nums;
        vector<char> ops;

        for(int i = l; i <= r; ){
            if(s[i] == '+' || s[i] == '-'){
                ops.push_back(s[i++]);
                if(nums.empty()) nums.push_back(0);
            }
            else if(s[i] == '('){
                nums.push_back(parse(s, i + 1, right[i] - 1, right));
                cal(nums, ops);
                i = right[i] + 1;
            }
            else{
                int j = i, num = 0;
                for(; j <= r && isdigit(s[j]); j ++)
                    num = num * 10 + (s[j] - '0');

                nums.push_back(num);
                cal(nums, ops);
                i = j;
            }
        }

        assert(nums.size() == 1);
        return nums.back();
    }

    void cal(vector<int>& nums, vector<char>& ops){

        if(!ops.empty() && (ops.back() == '+' || ops.back() == '-')){

            int second = nums.back();
            nums.pop_back();

            int first = nums.empty() ? 0 : nums.back();
            if(!nums.empty()) nums.pop_back();

            nums.push_back(ops.back() == '+' ? (first + second) : (first - second));
            ops.pop_back();
        }
    }
};


int main() {

    cout << Solution().calculate("1 + 1") << endl; // 2
    cout << Solution().calculate(" 2-1 + 2 ") << endl; // 3
    cout << Solution().calculate("(1+(4+5+2)-3)+(6+8)") << endl; // 23
    cout << Solution().calculate("-2+ 1") << endl; // -1
    cout << Solution().calculate("1-(-2)") << endl; // 3
    cout << Solution().calculate("-(3+(4+5))") << endl; // -12

    return 0;
}