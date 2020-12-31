/// Source : https://leetcode.com/problems/implement-rand10-using-rand7/description/
/// Author : liuyubobobo
/// Time   : 2018-08-05

#include <iostream>
#include <cassert>

using namespace std;

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
int rand7(){
    return rand() % 7 + 1;
}

/// Rejection Sampling improved
/// Utilizing out-of-range-samples
/// The accurate expectation for calling number of rand7() can be seen here:
/// https://leetcode.com/problems/implement-rand10-using-rand7/solution/
///
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int rand10() {
        int a = -1, b = rand7(), M = 7;
        do{
            a = b;
            b = rand7();
            int randNum = 7 * (a - 1) + b - 1;
            int largest = 7 * (M - 1) + 7 - 1;
            M = largest % 10 + 1;
            if(randNum < largest - largest % 10)
                return randNum % 10 + 1;
            b = randNum % 10 + 1;
        }while(true);

        assert(false);
        return -1;
    }
};


int main() {

    return 0;
}