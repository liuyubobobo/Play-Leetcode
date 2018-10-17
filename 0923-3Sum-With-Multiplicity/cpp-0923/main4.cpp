/// Source : https://leetcode.com/problems/3sum-with-multiplicity/description/
/// Author : liuyubobobo
/// Time   : 2018-10-16

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Three Pointers
/// Based on Two Pointers Algorithm in 2-Sum Problem
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {

private:
    int MOD = 1e9 + 7;

public:
    int threeSumMulti(vector<int>& A, int target) {

        sort(A.begin(), A.end());

        int res = 0;
        for(int i = 0; i < A.size(); i ++){

            int t = target - A[i];
            int j = i + 1, k = A.size() - 1;
            while(j < k){
                if(A[j] + A[k] < t)
                    j ++;
                else if(A[j] + A[k] > t)
                    k --;
                else{
                    if(A[j] != A[k]){
                        int jj = j + 1;
                        for(; jj < A.size() && A[jj] == A[j]; jj ++);

                        int kk = k - 1;
                        for(; kk >= 0 && A[kk] == A[k]; kk --);

                        res = (res + (jj - j) * (k - kk)) % MOD;
                        j = jj;
                        k = kk;
                    }
                    else{
                        res = (res + (k - j + 1) * (k - j) / 2) % MOD;
                        break;
                    }
                }
            }
        }
        return res;
    }
};


int main() {

    vector<int> A1 = {1,1,2,2,3,3,4,4,5,5};
    cout << Solution().threeSumMulti(A1, 8) << endl;
    // 20

    vector<int> A2 = {1,1,2,2,2,2};
    cout << Solution().threeSumMulti(A2, 5) << endl;
    // 12

    vector<int> A3(3000, 0);
    cout << Solution().threeSumMulti(A3, 0) << endl;
    // 495500972

    vector<int> A4 = {2, 1, 3};
    cout << Solution().threeSumMulti(A4, 6) << endl;
    // 1

    vector<int> A5 = {3, 3, 0, 0, 3, 2, 2, 3};
    cout << Solution().threeSumMulti(A5, 6) << endl;
    // 12

    return 0;
}