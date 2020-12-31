/// Source : https://leetcode.com/problems/expression-add-operators/description/
/// Author : liuyubobobo
/// Time   : 2018-09-03

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;


/// Backtracking to split num and eval
/// The eval function comes from Leetcode 227
/// https://leetcode.com/problems/basic-calculator-ii/description/
///
/// Time Complexity: O(n*3^n)
/// Space Complexity: O(3^n)
class Solution {
public:
    vector<string> addOperators(string num, int target) {

        if(num == "")
            return {};
        vector<string> ret;
        split(num, 0, target, "", ret);
        return ret;
    }

private:
    void split(const string& num, int index, int target, const string& expr,
               vector<string>& res){

        if(index == num.size()){
            if(calculate(expr) == target)
                res.push_back(expr);
            return;
        }

        int end = num.size();
        if(num[index] == '0')
            end = index + 1;
        for(int i = index; i < end; i ++){
            int len = (i + 1 - index);
            if(index + len == num.size())
                split(num, index + len, target, expr + num.substr(index, len), res);
            else{
                split(num, index + len, target, expr + num.substr(index, len) + "+", res);
                split(num, index + len, target, expr + num.substr(index, len) + "-", res);
                split(num, index + len, target, expr + num.substr(index, len) + "*", res);
            }
        }
    }

    long long calculate(const string& s) {

        vector<long long> nums;
        vector<char> ops;
        for(int i = 0; i < s.size() ; ){
            if(isdigit(s[i])){
                long long num = s[i] - '0';
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

    void calc(vector<long long>& nums, vector<char>& ops){

        assert(nums.size() >= 2);
        long long second = nums.back();
        nums.pop_back();
        long long first = nums.back();
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

    return 0;
}