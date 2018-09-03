/// Source : https://leetcode.com/problems/basic-calculator-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-09-03

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Two Stacks
/// Shunting-Yard Algorithms: https://en.wikipedia.org/wiki/Shunting-yard_algorithm
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int calculate(string s) {

        vector<int> nums;
        vector<char> ops;
        for(int i = 0; i < s.size() ; ){
            if(isdigit(s[i])){
                int num = s[i] - '0';
                int j;
                for(j = i + 1; j < s.size() && isdigit(s[j]); j ++)
                    num = num * 10 + (s[j] - '0');
                i = j;

                nums.push_back(num);
                if(!ops.empty() && (ops.back() == '*' || ops.back() == '/'))
                    calc(nums, ops);
            }
            else if(s[i] != ' '){
                if((s[i] == '+' || s[i] == '-') && !ops.empty() && (ops.back() == '+' || ops.back() == '-'))
                    calc(nums, ops);
                ops.push_back(s[i++]);
            }
            else
                i ++;
        }
        if(nums.size() != 1){
            assert(nums.size() == 2);
            calc(nums, ops);
        }

        return nums.back();
    }

private:
    void calc(vector<int>& nums, vector<char>& ops){

        assert(nums.size() >= 2);
        int second = nums.back();
        nums.pop_back();
        int first = nums.back();
        nums.pop_back();

        assert(!ops.empty());
        char op = ops.back();
        ops.pop_back();

        switch(op){
            case '+': nums.push_back(first + second); return;
            case '-': nums.push_back(first - second); return;
            case '*': nums.push_back(first * second); return;
            case '/': nums.push_back(first / second); return;
            default: assert(false); return;
        }
    }
};


int main() {

    cout << Solution().calculate("3+2*2") << endl; // 7
    cout << Solution().calculate(" 3/2 ") << endl; // 1
    cout << Solution().calculate(" 3+5 / 2 ") << endl; // 5
    cout << Solution().calculate("42") << endl; // 42
    cout << Solution().calculate("1-1+1") << endl; // 1

    return 0;
}