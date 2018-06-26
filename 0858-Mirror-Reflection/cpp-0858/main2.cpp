/// Source : https://leetcode.com/problems/mirror-reflection/description/
/// Author : liuyubobobo
/// Time   : 2018-06-23

#include <iostream>
#include <cassert>

using namespace std;

/// Mathematics
/// Time Complexity: O(log(max(p, q)))
/// Space Complexity: O(1)
class Solution {
public:
    int mirrorReflection(int p, int q) {

        int g = gcd(p, q);
        int k = p / g;

        int x = p * k;
        int y = q * k;
        assert(y % p == 0);

        if(isEven(y / p))
            return 0;

        if(isEven(x / p))
            return 2;
        return 1;
    }

private:
    bool isEven(int x){
        return x % 2 == 0;
    }

    int gcd(int a, int b){
        if(a > b)
            swap(a, b);

        if(b % a == 0)
            return a;
        return gcd(b % a, a);
    }
};


int main() {

    cout << Solution().mirrorReflection(2, 1) << endl; // 2
    cout << Solution().mirrorReflection(4, 3) << endl; // 2
    cout << Solution().mirrorReflection(3, 2) << endl; // 0
    cout << Solution().mirrorReflection(3, 1) << endl; // 1

    return 0;
}