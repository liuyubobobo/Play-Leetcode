/// Source : https://leetcode.com/problems/calculate-delayed-arrival-time/description/
/// Author : liuyubobobo
/// Time   : 2023-04-23

#include <iostream>

using namespace std;


/// Math
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};


int main() {

    return 0;
}
