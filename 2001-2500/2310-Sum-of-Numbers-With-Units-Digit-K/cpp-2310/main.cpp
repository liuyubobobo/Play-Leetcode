/// Source : https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/
/// Author : liuyubobobo
/// Time   : 2022-06-18

#include <iostream>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumNumbers(int num, int k) {

        if(num == 0) return 0;

        int cnt = 1;
        for(cnt = 1; cnt <= 10; cnt ++)
            if((cnt * k) % 10 == num % 10)
                break;

        if(cnt == 11 ||cnt * k > num) return -1;
        return cnt;
    }
};


int main() {

    cout << Solution().minimumNumbers(58, 9) << '\n';
    // 2

    cout << Solution().minimumNumbers(37, 2) << '\n';
    // -1

    cout << Solution().minimumNumbers(0, 7) << '\n';
    // 0

    return 0;
}
