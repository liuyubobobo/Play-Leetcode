/// Source : https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
/// Author : liuyubobobo
/// Time   : 2021-11-06

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Binary Search
/// Time Complexity: O(m * log(sum(quantities)))
/// Space Compelxity: O(1)
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {

        long long sum = accumulate(quantities.begin(), quantities.end(), 0ll);

        long long l = 1, r = sum;
        while(l < r){
            long long m = (l + r) / 2;
            if(ok(n, quantities, m)) r = m;
            else l = m + 1;
        }
        return l;
    }

private:
    bool ok(int n, const vector<int>& q, long long x){

        int cur = 0;
        for(int e: q)
            cur += e / x + !!(e % x);
        return cur <= n;
    }
};


int main() {

    vector<int> q1 = {11, 6};
    cout << Solution().minimizedMaximum(6, q1) << endl;
    // 3

    vector<int> q2 = {15, 10, 10};
    cout << Solution().minimizedMaximum(7, q2) << endl;
    // 5

    vector<int> q3 = {100000};
    cout << Solution().minimizedMaximum(1, q3) << endl;
    // 100000

    vector<int> q4 = {24,18,12,6,3,24,5,19,10,20,2,18,27,3,13,22,11,16,19,13};
    cout << Solution().minimizedMaximum(26, q4) << endl;
    // 19

    return 0;
}
