/// Source : https://leetcode.com/problems/number-of-days-in-a-month/
/// Author : liuyubobobo
/// Time   : 2019-07-13

#include <iostream>
#include <unordered_set>

using namespace std;


/// Simulation
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int numberOfDays(int Y, int M) {

        unordered_set<int> thirtyone = {1, 3, 5, 7, 8, 10, 12};
        if(thirtyone.count(M)) return 31;
        if(M == 2) return isLeapYear(Y) ? 29 : 28;
        return 30;
    }

private:
    bool isLeapYear(int Y){
        return (!(Y % 4) && (Y % 100)) || !(Y % 400);
    }
};


int main() {

    return 0;
}