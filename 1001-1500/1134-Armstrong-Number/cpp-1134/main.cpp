/// Source : https://leetcode.com/problems/armstrong-number/
/// Author : liuyubobobo
/// Time   : 2019-07-25

#include <iostream>
#include <cmath>

using namespace std;


/// Simulation
/// Time Complexity: O(logN)
/// Space Complexity: O(logN)
class Solution {
public:
    bool isArmstrong(int N) {

        int o = N;

        int k = to_string(N).size();
        int sum = 0;
        while(N){
            int d = N % 10;
            N /= 10;
            sum += pow(d, k);
            cout << sum << endl;
        }
        return o == sum;
    }
};


int main() {
    cout << Solution().isArmstrong(153) << endl;
    return 0;
}