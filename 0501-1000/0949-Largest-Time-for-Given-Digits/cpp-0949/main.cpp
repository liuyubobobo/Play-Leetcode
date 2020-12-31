/// Source : https://leetcode.com/problems/largest-time-for-given-digits/
/// Author : liuyubobobo
/// Time   : 2018-12-01

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Brute Force
/// Time Complexity: O(4!)
/// Space Complexity: O(1)
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {

        sort(A.begin(), A.end());
        string res = "";
        do{
            if(ok(A))
                res = to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
        }while(next_permutation(A.begin(), A.end()));
        return res;
    }

private:
    bool ok(const vector<int>& A){
        int h = A[0] * 10 + A[1];
        int m = A[2] * 10 + A[2];
        return h <= 23 && m <= 59;
    }
};


int main() {

    return 0;
}