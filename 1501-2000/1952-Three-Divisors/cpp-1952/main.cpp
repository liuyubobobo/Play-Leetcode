/// Source : https://leetcode.com/problems/three-divisors/
/// Author : liuyubobobo
/// Time   : 2021-07-31

#include <iostream>
#include <vector>

using namespace std;


/// Divisor Number
/// Time Complexity: O(sqrt(n))
/// Space Complexity: O(1)
class Solution {
public:
    bool isThree(int n) {

        int cnt = 2;
        for(int i = 2; i * i <= n; i ++)
            if(n % i == 0){
                cnt ++;
                cnt += i * i < n;
            }
        return cnt == 3;
    }
};


int main() {

    return 0;
}
