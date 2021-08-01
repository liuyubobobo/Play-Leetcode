/// Source : https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/
/// Author : liuyubobobo
/// Time   : 2021-07-31

#include <iostream>

using namespace std;


/// Mathematics + Binary Search
/// Time Complexity: O(log(sqrt(n)))
/// Space Complexity: O(1)
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {

        long long l = 0, r = 100000;
        while(l < r){
            long long mid = (l + r) / 2ll;
            if(2ll * mid * (mid + 1ll) * (2ll * mid + 1) >= neededApples)
                r = mid;
            else
                l = mid + 1ll;
        }
        return l * 8ll;
    }
};


int main() {

    cout << Solution().minimumPerimeter(1) << endl;
    // 8

    cout << Solution().minimumPerimeter(13) << endl;
    // 16

    cout << Solution().minimumPerimeter(1e9) << endl;
    // 5040

    cout << Solution().minimumPerimeter(1e15) << endl;

    return 0;
}
