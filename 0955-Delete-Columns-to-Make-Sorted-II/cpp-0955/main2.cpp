/// Source : https://leetcode.com/problems/delete-columns-to-make-sorted-ii/
/// Author : liuyubobobo
/// Time   : 2018-12-16

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Greedy and check in place
/// Time Complexity: O(m * n)
/// Space Complexity: O(m)
class Solution {

public:
    int minDeletionSize(vector<string>& A) {

        int m = A.size(), n = A[0].size(), res = 0;
        vector<bool> check(m - 1, false);
        for(int j = 0; j < n; j ++){

            bool ok = true;
            for(int i = 1; i < m; i ++)
                if(!check[i - 1] && A[i][j] < A[i - 1][j]){
                    ok = false;
                    break;
                }

            if(ok){
                for(int i = 1; i < m; i ++)
                    if(!check[i - 1] && A[i][j] > A[i - 1][j])
                        check[i - 1] = true;
            }
            else
                res ++;
        }
        return res;
    }
};


int main() {

    vector<string> A1 = {"ca","bb","ac"};
    cout << Solution().minDeletionSize(A1) << endl;
    // 1

    vector<string> A2 = {"xc","yb","za"};
    cout << Solution().minDeletionSize(A2) << endl;
    // 0

    vector<string> A3 = {"zyx","wvu","tsr"};
    cout << Solution().minDeletionSize(A3) << endl;
    // 3

    vector<string> A4 = {"xga","xfb","yfa"};
    cout << Solution().minDeletionSize(A4) << endl;
    //1

    vector<string> A5 = {"bwwdyeyfhc","bchpphbtkh","hmpudwfkpw","lqeoyqkqwe","riobghmpaa","stbheblgao","snlaewujlc","tqlzolljas","twdkexzvfx","wacnnhjdis"};
    cout << Solution().minDeletionSize(A5) << endl;
    //4

    return 0;
}