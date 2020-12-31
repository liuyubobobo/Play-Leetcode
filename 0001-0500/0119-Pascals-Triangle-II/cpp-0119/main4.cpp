/// Source : https://leetcode.com/problems/pascals-triangle-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-08-10

#include <iostream>
#include <vector>

using namespace std;


/// Using Binomial Coefficients Recurrence Relationship
/// Using C(m, n) = (m - n + 1) / n * C(m, n - 1)
///
/// Time Complexity: O(rowIndex)
/// Space Complexity: O(rowIndex)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        for(int i = 1; i <= (rowIndex + 1) / 2; i ++)
            res[i] = res[rowIndex - i] = (long long)(rowIndex - i + 1) * res[i - 1] / i;
        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    for(int i = 0 ; i < 10 ; i ++)
        print_vec(Solution().getRow(i));

    return 0;
}