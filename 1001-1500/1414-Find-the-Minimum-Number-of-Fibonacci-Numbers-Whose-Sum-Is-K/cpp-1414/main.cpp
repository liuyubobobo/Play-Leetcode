/// Source : https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
/// Author : liuyubobobo
/// Time   : 2020-04-18

#include <iostream>
#include <set>

using namespace std;


/// Greedy
/// Time Complexity: O(logk^2)
/// Space Complexity: O(logk)
class Solution {
public:
    int findMinFibonacciNumbers(int k) {

        int a = 1, b = 1, c;
        set<int> fibs = {1};
        while(a + b <= 1e9){
            c = a + b;
            fibs.insert(c);
            a = b, b = c;
        }

        int res = 0;
        while(k){
            set<int>::iterator iter = fibs.lower_bound(k);
            if(!(iter != fibs.end() && *iter == k)) iter --;
            res ++;
            k -= *iter;
        }
        return res;
    }
};


int main() {

    cout << Solution().findMinFibonacciNumbers(7) << endl;
    // 2

    return 0;
}
