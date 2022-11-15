/// Source : https://leetcode.com/problems/global-and-local-inversions/
/// Author : liuyubobobo
/// Time   : 2022-11-15

#include <iostream>
#include <vector>

using namespace std;


/// Merge Sort
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {

        vector<int> A_copy(A.begin(), A.end());
        long long global_inverse_count = globalInversionCount(A_copy);

        long long local_inverse_count = 0;
        for(int i = 1 ; i < A.size() ; i ++)
            if(A[i-1] > A[i])
                local_inverse_count ++;

        return global_inverse_count == local_inverse_count;
    }

private:
    int globalInversionCount(vector<int>& vec){

        return globalInversionCount(vec, 0, vec.size()-1);
    }

    long long globalInversionCount(vector<int>& vec, int l, int r){

        if( l >= r )
            return 0;

        int mid = l + (r-l)/2;

        long long res1 = globalInversionCount(vec, l, mid);
        long long res2 = globalInversionCount(vec, mid + 1, r);

        return res1 + res2 + merge(vec, l, mid, r);
    }

    long long merge(vector<int>& vec, int l, int mid, int r){

        vector<int> aux;
        for(int i = l ; i <= r ; i ++ )
            aux.push_back(vec[i]);

        long long res = 0;
        int j = l, k = mid + 1;
        for( int i = l ; i <= r ; i ++ ){
            if( j > mid ){
                vec[i] = aux[k-l];
                k ++;
            }
            else if( k > r ){
                vec[i] = aux[j-l];
                j ++;
            }
            else if( aux[j-l] <= aux[k-l] ){
                vec[i] = aux[j-l];
                j ++;
            }
            else{
                vec[i] = aux[k-l];
                k ++;
                res += (mid - j + 1);
            }
        }

        return res;
    }
};


int main() {

    return 0;
}
