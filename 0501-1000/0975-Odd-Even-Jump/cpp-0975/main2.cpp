/// Source : https://leetcode.com/problems/odd-even-jump/
/// Author : liuyubobobo
/// Time   : 2019-01-21

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Dynamic Programming
/// Using C++ STL map(a RBT underlying) to store the next step information :-)
///
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int oddEvenJumps(const vector<int>& A) {

        int n = A.size();

        vector<int> larger(n, -1);
        larger[n - 1] = n - 1;
        set<pair<int, int>> bst1;
        bst1.insert(make_pair(A[n - 1], n - 1));
        for(int i = n - 2; i >= 0; i --){
            set<pair<int, int>>::iterator iter = bst1.upper_bound(make_pair(A[i], i));
            if(iter != bst1.end()) larger[i] = iter->second;
            bst1.insert(make_pair(A[i], i));
        }
//        cout << "larger : ";
//        for(int e: larger)
//            cout << e << " ";
//        cout << endl;

        vector<int> smaller(n, -1);
        smaller[n - 1] = n - 1;
        set<pair<int, int>> bst2;
        bst2.insert(make_pair(-A[n - 1], n - 1));
        for(int i = n - 2; i >= 0; i --){
            set<pair<int, int>>::iterator iter = bst2.upper_bound(make_pair(-A[i], i));
            if(iter != bst2.end()) smaller[i] = iter->second;
            bst2.insert(make_pair(-A[i], i));
        }
//        cout << "smaller : ";
//        for(int e: smaller)
//            cout << e << " ";
//        cout << endl;

        vector<vector<bool>> dp(n, vector<bool>(2, false));
        dp[n - 1][0] = dp[n - 1][1] = true;
        for(int i = n - 2; i >= 0; i --){
            if(larger[i] != -1)
                dp[i][0] = dp[larger[i]][1];
            if(smaller[i] != -1)
                dp[i][1] = dp[smaller[i]][0];
        }

        int res = 0;
        for(int i = 0; i < n; i ++)
            res += dp[i][0];
        return res;
    }
};


int main() {

    vector<int> A1 = {10,13,12,14,15};
    cout << Solution().oddEvenJumps(A1) << endl;
    // 2

    vector<int> A2 = {2,3,1,1,4};
    cout << Solution().oddEvenJumps(A2) << endl;
    // 3

    vector<int> A3 = {5,1,3,4,2};
    cout << Solution().oddEvenJumps(A3) << endl;
    // 3

    return 0;
}