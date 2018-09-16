/// Source : https://leetcode.com/problems/sort-array-by-parity/solution/
/// Author : liuyubobobo
/// Time   : 2018-09-15

#include <iostream>
#include <vector>

using namespace std;


/// Rearrange in place
/// Time Complexity : O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {

        for(int i = 0; i < A.size(); i ++)
            if(A[i] % 2){
                int j = nextEven(A, i + 1);
                if(j < A.size())
                    swap(A[i], A[j]);
            }
        return A;
    }

private:
    int nextEven(const vector<int>& A, int start){

        for(int i = start; i < A.size(); i ++)
            if(A[i] % 2 == 0)
                return i;
        return A.size();
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums {3, 1, 2, 4};
    print_vec(Solution().sortArrayByParity(nums));

    return 0;
}