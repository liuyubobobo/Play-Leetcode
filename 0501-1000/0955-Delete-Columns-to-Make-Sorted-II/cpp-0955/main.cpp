/// Source : https://leetcode.com/problems/delete-columns-to-make-sorted-ii/
/// Author : liuyubobobo
/// Time   : 2018-12-12

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Greedy
/// Time Complexity: O(m * m * n)
/// Space Complexity: O(m * n)
class Solution {

public:
    int minDeletionSize(vector<string>& A) {

        int m = A.size(), n = A[0].size(), res = 0;
        vector<string> cur(m);
        for(int j = 0; j < n; j ++){

            vector<string> cur2 = cur;
            for(int i = 0; i < m; i ++)
                cur2[i] += A[i][j];

            if(!is_sort(cur2))
                res ++;
            else
                cur = cur2;
        }
        return res;
    }

private:
    bool is_sort(const vector<string>& s){
        for(int i = 1; i < s.size(); i ++)
            if(s[i - 1] > s[i])
                return false;
        return true;
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