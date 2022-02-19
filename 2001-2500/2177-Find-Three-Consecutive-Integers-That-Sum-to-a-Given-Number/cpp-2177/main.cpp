/// Source : https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/
/// Author : liuyubobobo
/// Time   : 2022-02-19

#include <iostream>
#include <vector>

using namespace std;


/// Math
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    vector<long long> sumOfThree(long long num) {

        if(num % 3ll) return {};
        return {num / 3 - 1, num / 3, num / 3 + 1};
    }
};


int main() {

    return 0;
}
