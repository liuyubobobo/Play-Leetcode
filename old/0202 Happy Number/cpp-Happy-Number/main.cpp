/// Source : https://leetcode.com/problems/happy-number/
/// Author : liuyubobobo
/// Time   : 2017-01-18

#include <iostream>
#include <unordered_set>

using namespace std;

/// Problem
/********************************************************************************************************
 *
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 *
 * Example: 19 is a happy number
 *
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 *
 * Credits:
 * Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.
 ********************************************************************************************************/


/// Solution
/***********************************************************************************************
 * Using HashTable
 *
 * Time Complexity: O(?)
 * Space Complexity: O(?)
 ************************************************************************************************/

class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> record;
        record.insert( n );
        while( n != 1 ){
            n = op(n);
            if( record.find(n) == record.end() )
                record.insert(n);
            else
                return false;
        }

        return true;
    }

private:
    int op(int x){
        int res = 0;
        while( x ){
            int t = x%10;
            res += t*t;
            x /= 10;
        }
        return res;
    }
};

int main() {

    cout << Solution().isHappy(19)<<endl;

    return 0;
}