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

/// We can use 7 * (rand7() - 1) + rand7() - 1 to genearte a "rand7()"-based number
/// This number will range from 0 to 48 union-distrubutionally
/// Then, we can use this number to generate rand10() :)
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
    }
};


int main() {

    return 0;
}