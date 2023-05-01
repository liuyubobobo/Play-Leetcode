/// Source : https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/
/// Author : liuyubobobo
/// Time   : 2023-04-30

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        set<int> Aset;
        vector<int> res(A.size());
        for (int i = 0; i < A.size(); i++) {
            Aset.insert(A[i]);
            int cnt = 0;
            for(int j = 0; j <= i; j ++)
                cnt += Aset.count(B[j]);
            res[i] = cnt;
        }
        return res;
    }
};


int main() {

    return 0;
}
