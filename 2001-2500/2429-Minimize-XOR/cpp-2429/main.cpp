/// Source : https://leetcode.com/problems/minimize-xor/
/// Author : liuyubobobo
/// Time   : 2022-10-01

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(log(num1) + log(num2))
/// Space Complexity: O(1)
class Solution {
public:
    int minimizeXor(int num1, int num2) {

        int one_cnt = __builtin_popcount(num2);

        int D = get_len(num1), res = 0;
        for(int p = D - 1; p >= 0 && one_cnt; p --)
            if((num1 >> p) & 1) one_cnt --, res += (1 << p);

        for(int p = 0; p <= 30 && one_cnt; p ++)
            if(((num1 >> p) & 1) == 0) one_cnt --, res += (1 << p);

        return res;
    }

private:
    int get_len(int x){
        int res = 0;
        while(x){
            res ++, x >>= 1;
        }
        return res;
    }
};


int main() {

    cout << Solution().minimizeXor(3, 5) << '\n';
    // 3

    cout << Solution().minimizeXor(1, 12) << '\n';
    // 3

    cout << Solution().minimizeXor(91, 18) << '\n';
    // 80

    return 0;
}
