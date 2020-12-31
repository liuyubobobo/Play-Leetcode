/// Source : https://leetcode.com/problems/the-kth-factor-of-n/
/// Author : liuyubobobo
/// Time   : 2020-06-27

#include <iostream>
#include <vector>

using namespace std;


/// Just calculate all the factors once
/// Time Complexity: O(sqrt(n))
/// Space Complexity: O(1)
class Solution {
public:
    int kthFactor(int n, int k) {

        int i;
        for(i = 1; i * i <= n; i ++)
            if(n % i == 0){
                k --;
                if(!k) return i;
            }

        i--;
        for(i = (i * i == n ? i - 1 : i); i > 0; i --)
            if(n % i == 0){
                k --;
                if(!k) return n / i;
            }

        return -1;
    }
};


int main() {

    cout << Solution().kthFactor(4, 4) << endl;

    return 0;
}
