/// Source : https://leetcode.com/problems/split-array-with-same-average/description/
/// Author : liuyubobobo
/// Time   : 2018-03-24

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;

/// Dynamic Programming
///
/// Suppose the same average is ave, then ave = sum(A) / len(A)
/// Try how many items B contains from 1 to len(A)/2
/// Suppose B contains i items, then sum(B) = i * ave
/// This sub-problem can be solved by dynamic programming
///
/// Time Complexity: O(len(A) * len(A) * sum(A))
/// Space Complexity: O(len(A) * sum(A))
class Solution {

public:
    bool splitArraySameAverage(vector<int>& A) {

        int m = A.size();
        int sum = accumulate(A.begin(), A.end(), 0);

        for(int i = 1 ; i <= m/2 ; i ++)
            if((sum * i) % m == 0 && ok(A, (sum * i) / m, i))
                return true;

        return false;
    }

private:
    bool ok(const vector<int>& A, int c, int num){

        vector<unordered_set<int>> dp(c + 1, unordered_set<int>());
        dp[0].insert(0);

        for(int a: A)
            for(int i = c ; i >= a ; i --)
                if(dp[i - a].size() != 0)
                    if(a == 0) { // dp[i-a] is dp[i]
                        vector<int> tmp(dp[i].begin(), dp[i].end());
                        for(int i = 0 ; i < tmp.size() ; i ++)
                            tmp[i] ++;
                        for(int e: tmp)
                            dp[i].insert(e);
                    }
                    else{
                        for(int x: dp[i - a])
                            dp[i].insert(x + 1);
                    }
        return dp[c].find(num) != dp[c].end();
    }
};

void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}


int main() {

    vector<int> A1 = {1,2,3,4,5,6,7,8};
    print_bool(Solution().splitArraySameAverage(A1));
    // true

    vector<int> A2 = {3, 1};
    print_bool(Solution().splitArraySameAverage(A2));
    // false

    vector<int> A3 = {18, 10, 5, 3};
    print_bool(Solution().splitArraySameAverage(A3));
    // false

    vector<int> A4 = {2,0,5,6,16,12,15,12,4};
    print_bool(Solution().splitArraySameAverage(A4));
    // true

    return 0;
}