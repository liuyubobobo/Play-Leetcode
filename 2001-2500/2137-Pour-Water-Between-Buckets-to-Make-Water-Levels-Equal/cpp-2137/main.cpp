/// Source : https://leetcode.com/problems/pour-water-between-buckets-to-make-water-levels-equal/
/// Author : liuyubobobo
/// Time   : 2022-01-13

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlog(MAX_RANGE))
/// Space Complexity: O(n)
class Solution {

private:
    const double eps = 1e-6;

public:
    double equalizeWater(vector<int>& buckets, int loss) {

        int n = buckets.size();

        vector<double> B(n);
        for(int i = 0; i < n; i ++) B[i] = buckets[i];
        sort(B.begin(), B.end());

        double p = 1.0 - (double)loss / 100.0;

        double l = B[0], r = accumulate(B.begin(), B.end(), 0.0) / n;
        while(!eq(l, r)){
            double m = (l + r) / 2;
            if(ok(n, B, m, p)) l = m;
            else r = m;
        }
        return l;
    }

private:
    bool ok(int n, vector<double> B, double t, double p){

        for(int i = 0, j = 0; i < n;)
            if(B[i] < t){
                while(j < n && B[j] <= t) j ++;
                if(j == n) return false;

                double need = t - B[i];
                double can_pour = (B[j] - t) * p;
                if(need >= can_pour){
                    B[i] += can_pour;
                    B[j] = t;
                    if(B[i] >= t) i ++;
                }
                else{
                    B[i] = t;
                    B[j] -= need / p;
                    i ++;
                }
            }
            else i ++;
        return true;
    }

    bool eq(double a, double b){
        return abs(a - b) <= eps;
    }
};

int main() {

    vector<int> bucket1 = {1, 2, 7};
    cout << Solution().equalizeWater(bucket1, 80) << endl;
    // 2.0

    vector<int> bucket2 = {2, 4, 6};
    cout << Solution().equalizeWater(bucket2, 50) << endl;
    // 3.5

    vector<int> bucket3 = {3, 3, 3, 3};
    cout << Solution().equalizeWater(bucket3, 40) << endl;
    // 3

    return 0;
}
