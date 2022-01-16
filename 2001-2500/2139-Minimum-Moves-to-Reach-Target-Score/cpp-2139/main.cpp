/// Source : https://leetcode.com/problems/minimum-moves-to-reach-target-score/
/// Author : liuyubobobo
/// Time   : 2022-01-15

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Greedy
/// Time Complexity: O(min(log(taarget), maxDoubles))
/// Space Complexity: O(1)
class Solution {
public:
    int minMoves(int target, int maxDoubles) {

        if(maxDoubles == 0) return target - 1;

        int res = 0, cur = target;
        while(maxDoubles && cur != 1){
            if(cur & 1) cur --, res ++;
            else cur >>= 1, res ++, maxDoubles --;
        }
        res += (cur - 1);
        return res;
    }
};


int main() {

    cout << Solution().minMoves(5, 0) << endl;
    // 4

    cout << Solution().minMoves(19, 2) << endl;
    // 7

    cout << Solution().minMoves(10, 4) << endl;
    // 4

    cout << Solution().minMoves(4, 4) << endl;
    // 2

    return 0;
}
