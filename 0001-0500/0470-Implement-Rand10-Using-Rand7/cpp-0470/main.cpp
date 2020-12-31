/// Source : https://leetcode.com/problems/implement-rand10-using-rand7/description/
/// Author : liuyubobobo
/// Time   : 2018-07-16

#include <iostream>
#include <cassert>

using namespace std;

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
int rand7(){
    return rand() % 7 + 1;
}

/// Rejection Sampling
/// The accurate expectation for calling number of rand7() can be seen here:
/// https://leetcode.com/problems/implement-rand10-using-rand7/solution/
///
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int rand10() {
        do{
            int randNum = 7 * (rand7() - 1) + rand7() - 1;
            if(randNum <= 39)
                return randNum % 10 + 1;
        }while(true);

        assert(false);
        return -1;
    }
};


int main() {

    return 0;
}