/// Source : https://leetcode.com/problems/k-th-smallest-prime-fraction/description/
/// Author : liuyubobobo
/// Time   : 2018-03-10

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Binary Search
/// Time Complexity: O(len(A)^2*logW)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {

        sort(A.begin(), A.end());
        double l = 0.0, r = 1.0;
        while(l <= r){
            double mid = (l + r) / 2.0;
            vector<int> res = under(A, mid);
            // cout << mid << " " << res[0] << " " << res[1] << " " << res[2] << endl;
            if(res[0] == K)
                return {res[1], res[2]};

            if(res[0] < K)
                l = mid;
            else
                r = mid;
        }

        assert(false);
        return {};
    }

private:
    // return {count, num, denom}
    vector<int> under(const vector<int>& A, double x){
        int res = 0;
        double max_frac = 0.0;
        int num, denom;
        for(int i = 0 ; i < A.size() ; i ++)
            for(int j = i + 1 ; j < A.size() ; j ++){
                double frac = (double)A[i] / A[j];
                if(frac <= x){
                    res ++;
                    if(frac > max_frac){
                        max_frac = frac;
                        num = A[i];
                        denom = A[j];
                    }
                }
            }

        return {res, num, denom};
    }
};

void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> A1 = {1, 2, 3, 5};
    print_vec(Solution().kthSmallestPrimeFraction(A1, 3));

    vector<int> A2 = {1, 7};
    print_vec(Solution().kthSmallestPrimeFraction(A2, 1));

    return 0;
}