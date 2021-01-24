/// Source : https://leetcode.com/problems/building-boxes/
/// Author : liuyubobobo
/// Time   : 2021-01-23

#include <iostream>

using namespace std;


/// Mathematics
/// Time Complexity: O(sqrt(n))
/// Space Complexity: O(1)
class Solution {
public:
    int minimumBoxes(int n) {

        if(n == 1) return 1;

        int total = 1, res = 1;
        for(int h = 2; h <= n; h ++){

            if(total + 1 == n){ res ++; break;}

            total += 3, res += 2;
            if(total >= n) break;

            for(int x = 3; x <= h; x ++){
                total += x, res ++;
                if(total >= n) break;
            }
            if(total >= n) break;
        }

        return res;
    }
};


int main() {

    cout << Solution().minimumBoxes(3) << endl;
    // 3

    cout << Solution().minimumBoxes(4) << endl;
    // 3

    cout << Solution().minimumBoxes(10) << endl;
    // 6

    cout << Solution().minimumBoxes(11) << endl;
    // 7

    cout << Solution().minimumBoxes(1e9) << endl;
    // 1650467

    return 0;
}
