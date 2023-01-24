/// Source : https://leetcode.com/problems/check-if-point-is-reachable/description/
/// Author : liuyubobobo
/// Time   : 2023-01-24

#include <iostream>
#include <vector>

using namespace std;


/// Math
/// Time Complexity: O(log(max(targetX, targetY)))
/// Space Complexity: O(log(max(targetX, targetY)))
class Solution {
public:
    bool isReachable(int targetX, int targetY) {

        int g = gcd(targetX, targetY);
        return (g & (g - 1)) == 0;
    }

private:
    int gcd(int a, int b){
        if(a > b) swap(a, b);
        if (a == 0) return b;
        return gcd(b % a, a);
    }
};


int main() {

    cout << Solution().isReachable(6, 9) << '\n';
    return 0;
}
