/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : liuyubobobo
/// Time   : 2019-03-23

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Multiplication Simulation
/// Time Complexity: O(K)
/// Space Complexity: O(1)
class Solution {
public:
    int smallestRepunitDivByK(int K) {

        if(K % 2 == 0 || K % 5 == 0) return -1;

        int r = 0;
        for(int len = 1; len <= K; len ++){
            r = (r * 10 + 1) % K;
            if(r == 0) return len;
        }
        return -1;
    }
};


int main() {

    cout << Solution().smallestRepunitDivByK(3) << endl;

    return 0;
}