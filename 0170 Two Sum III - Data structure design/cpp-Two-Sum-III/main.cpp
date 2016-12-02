/// Source : https://leetcode.com/problems/two-sum-iii-data-structure-design/
/// Author : liuyubobobo
/// Time   : 2016-12-03


#include <iostream>
#include <unordered_map>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/*****************************************************************************************************
 *
 * Design and implement a TwoSum class.
 * It should support the following operations: add and find.
 *
 * add - Add the number to an internal data structure.
 * find - Find if there exists any pair of numbers which sum is equal to the value.
 *
 * For example,
 * add(1); add(3); add(5);
 * find(4) -> true
 * find(7) -> false
 *****************************************************************************************************/


/// Solution
/*******************************************************************************
 * If using array to store all the elements,
 *
 * We can make sure all the elements sorted whenever add a new number,
 * In this case,
 *     add operation : O(n)
 *     find operation : O(n) - Two Pointers
 *
 * We can also sort the array when we need to do the find operation.
 * In this case,
 *     add operation : O(1)
 *     find operation : O(nlogn) + O(n) - Sort + Two Pointers
 *
 *
 * But, the most convenient way to store all the elements is using hashtable
 *
 * Time Complexity:  add: O(1) , find: O(n)
 * Space Complexity: O(n)
 *****************************************************************************/

class TwoSum {

private:
    // The numbers store the number pair represent (number, count of the number)
    unordered_map<int,int> numbers;

public:

    // Add the number to an internal data structure.
    void add(int number) {
        numbers[number] += 1;
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {

        for( auto iter = numbers.begin() ; iter != numbers.end() ; iter ++ ){
            int num = iter->first;
            if( numbers.find(value - num)  != numbers.end() ){
                if( value - num == num && numbers[num] == 1 )
                    continue;

                // value - num == num && numbers[num] >= 2
                // value - num != num
                return true;
            }
        }

        return false;
    }
};

int main() {

    TwoSum twoSum;
    twoSum.add(1);
    twoSum.add(3);
    twoSum.add(5);

    cout<<twoSum.find(4)<<endl;
    cout<<twoSum.find(7)<<endl;

    return 0;
}