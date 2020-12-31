/// Source : https://leetcode.com/problems/count-of-matches-in-tournament/
/// Author : liuyubobobo
/// Time   : 2020-12-12

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int numberOfMatches(int n) {

        int res = 0;
        while(n > 1){
            if(n % 2){
                res += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            }
            else{
                res += n / 2;
                n /= 2;
            }
        }
        return res;
    }
};


int main() {

    cout << Solution().numberOfMatches(7) << endl;
    // 6

    return 0;
}
