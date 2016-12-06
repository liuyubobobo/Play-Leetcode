/// Source : https://leetcode.com/problems/4sum-ii/
/// Author : liuyubobobo
/// Time   : 2016-12-06


#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/************************************************************************************************
 *
 * Given four lists A, B, C, D of integer values,
 * compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
 *
 * To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500.
 * All integers are in the range of -2^28 to 2^28 - 1
 * and the result is guaranteed to be at most 2^31 - 1.
 *
 * Example:
 *
 * Input:
 * A = [ 1, 2]
 * B = [-2,-1]
 * C = [-1, 2]
 * D = [ 0, 2]
 *
 * Output:
 * 2
 *
 * Explanation:
 * The two tuples are:
 * 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 ************************************************************************************************/


/// Solution
/***********************************************************************************************
 * Make two hashtable,
 * one for all the pairs ( a , b ) where a in A and b in B
 * another one for the pairs ( c , d ) where c in C and d in D
 * for every pair ( a , b ) , find ( c , d ) which makes a + b + c + d == 0
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 ************************************************************************************************/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

        unordered_map<int,int> hashtable1;
        unordered_map<int,int> hashtable2;

        for( int i = 0 ; i < A.size() ; i ++ )
            for( int j = 0 ; j < B.size() ; j ++ )
                hashtable1[A[i]+B[j]] += 1;

        for( int i = 0 ; i < C.size() ; i ++ )
            for( int j = 0 ; j < D.size() ; j ++ )
                hashtable2[C[i]+D[j]] += 1;

        int res = 0;
        for( unordered_map<int,int>::iterator iter = hashtable1.begin() ; iter != hashtable1.end() ; iter ++ )
            if( hashtable2.find(-(iter->first)) != hashtable2.end() )
                res += iter->second * hashtable2[-(iter->first)];

        return res;
    }
};

int main() {

    int a[] = {1, 2};
    int b[] = {-2, -1};
    int c[] = {-1, 2};
    int d[] = {0, 2};
    vector<int> a_vec = vector<int>( a , a + sizeof(a)/sizeof(int));
    vector<int> b_vec = vector<int>( b , b + sizeof(b)/sizeof(int));
    vector<int> c_vec = vector<int>( c , c + sizeof(c)/sizeof(int));
    vector<int> d_vec = vector<int>( d , d + sizeof(d)/sizeof(int));

    cout<<Solution().fourSumCount( a_vec, b_vec, c_vec, d_vec )<<endl;

    return 0;
}