/// Source : https://leetcode.com/problems/three-equal-parts/
/// Author : liuyubobobo
/// Time   : 2018-10-20

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Ad-Hoc
/// The three parts must contain equal number of ones :-)
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {

        int n = A.size();

        int sum = accumulate(A.begin(), A.end(), 0);
        if(sum == 0)
            return {0, n - 1};

        if(sum % 3)
            return {-1, -1};

        int k = sum / 3;
        int j = n - 1, t = 0;
        for(; j >= 0; j --){
            t += (A[j] == 1);
            if(t == k)
                break;
        }

        int i = 0;
        for(;i < n; i ++)
            if(A[i]) break;

        for(int jj = j; jj < n; i ++, jj ++)
            if(A[i] != A[jj])
                return {-1, -1};

        for(k = i; k < n; k ++)
            if(A[k]) break;

        for(int jj = j; jj < n; k ++, jj ++)
            if(A[k] != A[jj])
                return {-1, -1};

        return {i - 1, k};
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> A1 = {1,0,1,0,1};
    print_vec(Solution().threeEqualParts(A1));
    // 0 3

    vector<int> A2 = {1,1,0,1,1};
    print_vec(Solution().threeEqualParts(A2));
    // -1 -1

    return 0;
}