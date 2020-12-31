/// Source : https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
/// Author : liuyubobobo
/// Time   : 2020-04-24

#include <iostream>

using namespace std;


/// Binary Search
/// Time Complexity: O(m * log(m * n))
/// Space Complexity: O(1)
class Solution {
public:
    int findKthNumber(int m, int n, int k) {

        int l = 1, r = m * n + 1;
        while(l < r){
            int mid = (l + r) / 2;
            int rank = get(mid, m, n);
            if(rank < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }

private:
    int get(int x, int m, int n){

        int res = 0;
        for(int i = 1; i <= m; i ++)
            res += min(x / i, n);
        return res;
    }
};


int main() {

    cout << Solution().findKthNumber(3, 3, 5) << endl;
    // 3

    cout << Solution().findKthNumber(2, 3, 6) << endl;
    // 6

    cout << Solution().findKthNumber(42, 34, 401) << endl;
    // 126

    return 0;
}
