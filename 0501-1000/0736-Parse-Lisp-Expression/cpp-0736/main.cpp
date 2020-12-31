/// Source : https://leetcode.com/problems/parse-lisp-expression/description/
/// Author : liuyubobobo
/// Time   : 2017-11-27

#include <iostream>
#include <string>
#include <unordered_map>
#include <cassert>

/// Parsing
/// Time Complexity: O(n)
/// Space Complexity: O(n)
using namespace std;

class Solution {

public:
    int evaluate(string expression) {

        int end;
        int res = evaluate(expression, 0, end, unordered_map<string, int>());
        assert(end == expression.size());

        return res;
    }

private:
    int evaluate(const string& expression, int start, int& end,
                 const unordered_map<string, int>& table){

        if(expression[start] == '-' || expression[start] == '+' || isdigit(expression[start])){
            end = nextNonDigit(expression, start + 1);
            return stoi(expression.substr(start, end - start));
        }

        if(expression[start] != '('){
            end = nextNonLetter(expression, start + 1);
            string var = expression.substr(start, end - start);
            assert(table.find(var) != table.end());
            return table.find(var)->second;
        }

        assert(expression[start] == '(');

        // add
        if(expression[start + 1] == 'a'){

            assert(expression[start + 2] == 'd');
            assert(expression[start + 3] == 'd');
            assert(expression[start + 4] == ' ');

            int end1;
            int e1 = evaluate(expression, start + 5, end1, table);
            assert(expression[end1] == ' ');

            int end2;
            int e2 = evaluate(expression, end1 + 1, end2, table);
            assert(expression[end2] == ')');

            end = end2 + 1;
            return e1 + e2;
        }

        // mult
        if(expression[start + 1] == 'm'){

            assert(expression[start + 2] == 'u');
            assert(expression[start + 3] == 'l');
            assert(expression[start + 4] == 't');
            assert(expression[start + 5] == ' ');

            int end1;
            int e1 = evaluate(expression, start + 6, end1, table);
            assert(expression[end1] == ' ');

            int end2;
            int e2 = evaluate(expression, end1 + 1, end2, table);
            assert(expression[end2] == ')');

            end = end2 + 1;
            return e1 * e2;
        }

        // let
        assert(expression[start + 1] == 'l');
        assert(expression[start + 2] == 'e');
        assert(expression[start + 3] == 't');
        assert(expression[start + 4] == ' ');

        unordered_map<string, int> newTable(table.begin(), table.end());

        int newStart = start + 5;
        while(true){
            if(expression[newStart] == '(' || expression[newStart] == '-' ||
                    isdigit(expression[newStart])){
                int inner_end;
                int res = evaluate(expression, newStart, inner_end, newTable);
                end = inner_end + 1;
                return res;
            }

            int end1 = nextNonLetter(expression, newStart);
            string var = expression.substr(newStart, end1 - newStart);

            if(expression[end1] == ')'){
                int inner_end;
                int res = evaluate(expression, newStart, inner_end, newTable);
                assert(end1 == inner_end);
                end = inner_end + 1;
                return res;
            }

            assert(expression[end1] == ' ');

            int end2;
            int inner_res = evaluate(expression, end1 + 1, end2, newTable);
            assert(expression[end2] == ' ');

            newTable[var] = inner_res;
            newStart = end2 + 1;
        }

        assert(false);
    }

    int nextNonDigit(const string& expression, int start){
        for(int i = start; ; i ++)
            if(!isdigit(expression[i]))
                return i;
        assert(false);
        return expression.size();
    }

    int nextNonLetter(const string& expression, int start){
        for(int i = start; ; i ++)
            if(!isdigit(expression[i]) && !isalpha(expression[i]))
                return i;
        assert(false);
        return expression.size();
    }
};

int main() {

    cout << Solution().evaluate("(add 1 2)") << endl;
    // 3

    cout << Solution().evaluate("(mult 3 (add 2 3))") << endl;
    // 15

    cout << Solution().evaluate("(let x 2 (mult x 5))") << endl;
    // 10

    cout << Solution().evaluate("(let x 2 (mult x (let x 3 y 4 (add x y))))") << endl;
    // 14

    cout << Solution().evaluate("(let x 3 x 2 x)") << endl;
    // 2

    cout << Solution().evaluate("(let x 1 y 2 x (add x y) (add x y))") << endl;
    // 5

    cout << Solution().evaluate("(let x 2 (add (let x 3 (let x 4 x)) x))") << endl;
    // 6

    cout << Solution().evaluate("(let a1 3 b2 (add a1 1) b2)") << endl;
    // 4

    cout << Solution().evaluate("(let x 7 -12)") << endl;
    // -12

    return 0;
}