/// Source : https://leetcode.com/problems/get-maximum-in-generated-array/
/// Author : liuyubobobo
/// Time   : 2020-11-07

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n / 2)
/// Space Complexity: O(n)
class Solution {
public:
    int getMaximumGenerated(int n) {

        if(n == 0) return 0;

        vector<int> arr(n + 1, 0);
        arr[1] = 1;
        int res = arr[1];
        for(int i = 1; 2 * i - 1 <= n; i ++){
            arr[2 * i - 1] = arr[i - 1] + arr[i], res = max(res, arr[2 * i - 1]);
            if(2 * i <= n) arr[2 * i] = arr[i];
        }
//        for(int e: arr) cout << e << " "; cout << endl;
        return res;
    }
};


int main() {

    cout << Solution().getMaximumGenerated(7) << endl;
    // 3

    cout << Solution().getMaximumGenerated(2) << endl;
    // 1

    cout << Solution().getMaximumGenerated(3) << endl;
    // 2

    cout << Solution().getMaximumGenerated(0) << endl;
    // 0

    cout << Solution().getMaximumGenerated(1) << endl;
    // 1

    cout << Solution().getMaximumGenerated(4) << endl;
    // 2

    return 0;
}
