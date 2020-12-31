/// Source : https://leetcode.com/problems/24-game/
/// Author : liuyubobobo
/// Time   : 2020-03-02

#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;


/// Brute Force
/// Time Complexity: O(4! * 4^3 * 3)
/// Space Complexity: O(1)
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        do{
            if(ok(nums[0], nums[1], nums[2], nums[3])) return true;
        }while(next_permutation(nums.begin(), nums.end()));

        return false;
    }

private:
    bool ok(int a, int b, int c, int d){

        vector<char> ops = {'+', '-', '*', '/'};
        for(char op1: ops)
            for(char op2: ops)
                for(char op3: ops){
                    try{
                        if(equals(op(op(op(a, b, op1), c, op2), d, op3), 24.0)) return true;
                    }catch(invalid_argument& e){}

                    try{
                        if(equals(op(op(a, b, op1), op(c, d, op3), op2), 24.0)) return true;
                    }catch(invalid_argument& e){}

                    try{
                        if(equals(op(op(a, op(b, c, op2), op1), d, op3), 24.0)) return true;
                    }catch(invalid_argument& e){}

                    try{
                        if(equals(op(a, op(op(b, c, op2), d, op3), op1), 24.0)) return true;
                    }catch(invalid_argument& e){}

                    try{
                        if(equals(op(a, op(b, op(c, d, op3), op2), op1), 24.0)) return true;
                    }catch(invalid_argument& e){}
                }
        return false;
    }

    double op(double a, double b, char op){
        if(op == '+') return a + b;
        if(op == '-') return a - b;
        if(op == '*') return a * b;
        if(equals(b, 0.0)) throw invalid_argument("error");
        return a / b;
    }

    bool equals(double a, double b){
        return abs(a - b) <= 1e-6;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 1, 2};
    cout << Solution().judgePoint24(nums1) << endl;
    // 0

    return 0;
}
