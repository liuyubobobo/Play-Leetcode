/// Source : https://leetcode.com/problems/binary-subarrays-with-sum/
/// Author : liuyubobobo
/// Time   : 2018-10-29

#include <iostream>
#include <vector>

using namespace std;


/// Using all 1's index
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {

        if(A.size() == 0)
            return S == 0;

        vector<int> ones = {-1};
        for(int i = 0; i < A.size(); i ++)
            if(A[i] == 1)
                ones.push_back(i);
        ones.push_back(A.size());

        int res = 0;
        if(S == 0){
            for(int i = 1; i < ones.size(); i ++){
                int n = ones[i] - ones[i - 1] - 1;
                res += n + n * (n - 1) / 2;
            }
            return res;
        }

        for(int i = 1; i + S < ones.size(); i ++){
            int l = ones[i] - ones[i - 1];
            int r = ones[i + S] - ones[i + S - 1];
            res += l * r;
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