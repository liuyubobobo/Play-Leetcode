#include <iostream>
#include <vector>
#include <string>

using namespace std;

/// Problem
/***************************************************************************************
 * In the computer world,
 * use restricted resource you have to generate maximum benefit is what we always want to pursue.
 *
 * For now, suppose you are a dominator of m 0s and n 1s respectively.
 * On the other hand, there is an array with strings consisting of only 0s and 1s.
 *
 * Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s.
 * Each 0 and 1 can be used at most once.
 *
 * Note:
 * The given numbers of 0s and 1s will both not exceed 100
 * The size of given string array won't exceed 600.
 *
 * Example 1:
 * Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 * Output: 4
 * Explanation:
 * This are totally 4 strings can be formed by the using of 5 0s and 3 1s,
 * which are “10,”0001”,”1”,”0”
 *
 * Example 2:
 * Input: Array = {"10", "0", "1"}, m = 1, n = 1
 * Output: 2
 *
 * Explanation: You could form "10", but then you'd have nothing left.
 * Better form "0" and "1".
 ***************************************************************************************/


/// Solution
/**************************************************************************************
 * 0-1 backsack problem
 * Recursion Implimentation
 *
 * Time Complexity: O(sizeof(array)*m*n)
 * Space Complexity: O(sizeof(array)*m*n)
 *
 * Memory Limit Exceeded
 **************************************************************************************/

class Solution {

private:
    vector<int> mcost, ncost;
    vector<vector<vector<int>>> dp;

public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        for( int i = 0 ; i < strs.size() ; i ++ ){
            mcost.push_back(0);
            ncost.push_back(0);
            for( int j = 0 ; j < strs[i].size() ; j ++ )
                if( strs[i][j] == '0' )
                    mcost[i] ++;
                else
                    ncost[i] ++;
        }

        for( int i = 0 ; i < strs.size() ; i ++ ){
            vector<vector<int>> t;
            for( int j = 0 ; j <= m ; j ++ )
                t.push_back( vector<int>( n+1, -1 ) );
            dp.push_back( t );
        }

        return __findMaxForm( strs.size() - 1 , m , n );
    }

private:
    int __findMaxForm( int k , int m , int n ){

        if( k < 0 )
            return 0;

        if( dp[k][m][n] != -1 )
            return dp[k][m][n];

        dp[k][m][n] = __findMaxForm( k-1 , m , n );
        if( m >= mcost[k] && n >= ncost[k] )
            dp[k][m][n] = max( 1 + __findMaxForm( k-1 , m - mcost[k] , n - ncost[k] ),
                               dp[k][m][n] );

        return dp[k][m][n];
    }
};

int main() {

    vector<string> vec1;
    vec1.push_back("10");
    vec1.push_back("0001");
    vec1.push_back("111001");
    vec1.push_back("1");
    vec1.push_back("0");
    int m1 = 5;
    int n1 = 3;
    cout<<Solution().findMaxForm(vec1, m1, n1)<<endl;

    cout<<endl;

    vector<string> vec2;
    vec2.push_back("10");
    vec2.push_back("0");
    vec2.push_back("1");
    int m2 = 1;
    int n2 = 1;
    cout<<Solution().findMaxForm(vec2, m2, n2)<<endl;

    return 0;
}