/// Source : https://leetcode.com/problems/count-integers-with-even-digit-sum/
/// Author : liuyubobobo
/// Time   : 2022-02-19

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int countEven(int num) {

        int res = 0;
        for(int e = 1; e <= num; e ++)
            res += ok(e);
        return res;
    }

private:
    bool ok(int e){
        int res = 0;
        while(e) res += e % 10, e /= 10;
        return res % 2 == 0;
    }
};


int main() {

    cout << Solution().countEven(4) << endl;
    // 2

    cout << Solution().countEven(30) << endl;
    // 14

    return 0;
}
