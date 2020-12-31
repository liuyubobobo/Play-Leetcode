/// Source : https://leetcode.com/problems/fibonacci-number/
/// Author : liuyubobobo
/// Time   : 2019-01-09

#include <iostream>
#include <vector>

using namespace std;


/// Binets Method
/// | F(n+1) F(n)   | = | 1 1 |^n
/// | F(n)   F(n-1) |   | 1 0 |
///
/// Time Complexity: O(logn)
/// Space Complexity: O(logn)
class Solution {
public:
    int fib(int N) {

        if(N <= 1) return N;

        vector<vector<int>> base = {{1, 1},
                                    {1, 0}};
        return matrix_pow(base, N - 1)[0][0];
    }

private:
    vector<vector<int>> matrix_pow(const vector<vector<int>> &m, int n) {

        if (n == 1)
            return m;

        vector<vector<int>> t = matrix_pow(m, n / 2);
        vector<vector<int>> res = matrix_multiply(t, t);
        if (n % 2)
            return matrix_multiply(res, m);
        return res;
    }

    vector<vector<int>> matrix_multiply(const vector<vector<int>> &m1,
                                        const vector<vector<int>> &m2) {

        vector<vector<int>> res(2, vector<int>(2, 0));
        res[0][0] = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
        res[0][1] = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];
        res[1][0] = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
        res[1][1] = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];
        return res;
    }
};


int main() {

    return 0;
}