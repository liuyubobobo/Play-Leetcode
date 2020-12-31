/// Source : https://leetcode.com/problems/binary-subarrays-with-sum/
/// Author : liuyubobobo
/// Time   : 2018-10-27

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Two Pointers
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {

        if(A.size() == 0)
            return S == 0;

        if(S == 0)
            return dealZero(A);

        unordered_map<int, int> nextZero;
        int lastOne = -1;
        for(int i = 0; i < A.size(); i ++)
            if(A[i] == 0 && lastOne >= 0)
                nextZero[lastOne] ++;
            else if(A[i] == 1)
                lastOne = i;

        unordered_map<int, int> prevZero;
        lastOne = -1;
        for(int i = A.size() - 1; i >= 0; i --)
            if(A[i] == 0 && lastOne >= 0)
                prevZero[lastOne] ++;
            else if(A[i] == 1)
                lastOne = i;

        int l = 0, r = -1, sum = 0, res = 0;
        while(l < A.size()){
            if(r + 1 < A.size() && sum < S){
                sum += A[++r];
            }
            else
                sum -= A[l++];

            if(sum == S && A[l] && A[r])
                res += (nextZero[r] + 1) * (prevZero[l] + 1);
        }
        return res;
    }

private:
    int dealZero(const vector<int>& A){
        int res = 0, start = 0;
        for(int i = start + 1; i <= A.size(); i ++)
            if(i == A.size() || A[i] != A[start]){
                if(A[start] == 0){
                    int n = i - start;
                    // cout << "n : " << n << endl;
                    res += n + n * (n - 1) / 2;
                }
                start = i;
                i = start;
            }
        return res;
    }
};


int main() {

    vector<int> A1 = {1,0,1,0,1};
    cout << Solution().numSubarraysWithSum(A1, 2) << endl;
    // 4

    vector<int> A2 = {0,0,0,0,0};
    cout << Solution().numSubarraysWithSum(A2, 0) << endl;
    // 15

    vector<int> A3 = {0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0};
    cout << Solution().numSubarraysWithSum(A3, 3) << endl;
    // 48

    return 0;
}