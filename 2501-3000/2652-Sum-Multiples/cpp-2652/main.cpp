/// Source : https://leetcode.com/problems/sum-multiples/description/
/// Author : liuyubobobo
/// Time   : 2023-04-23

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int sumOfMultiples(int n) {

        int sum = 0;
        for(int i = 1; i <= n; i ++)
            if(i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
                sum += i;
        return sum;
    }
};


int main() {

    return 0;
}
