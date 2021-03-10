/// Source : https://leetcode.com/problems/basic-calculator/description/
/// Author : liuyubobobo
/// Time   : 2018-09-03
/// Updated: 2021-03-09

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
    int calculate(string s) {

        vector<int> nums;
        vector<char> ops;

        for(int i = 0; i < s.size(); ){
            if(s[i] == '+' || s[i] == '-' || s[i] == '(')
                ops.push_back(s[i++]);
            else if(s[i] == ')'){
                assert(!ops.empty() && ops.back() == '(');
                ops.pop_back();
                i ++;

                cal(nums, ops);
            }
            else if(isdigit(s[i])){

                int num = s[i] - '0';
                int j;
                for(j = i + 1; j < s.size() && isdigit(s[j]); j ++)
                    num = num * 10 + (s[j] - '0');
                i = j;

                nums.push_back(num);
                cal(nums, ops);
            }
            else
                i ++;
        }

        assert(nums.size() == 1);
        return nums.back();
    }

private:
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

    return 0;
}