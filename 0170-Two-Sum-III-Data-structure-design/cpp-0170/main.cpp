/// Source : https://leetcode.com/problems/two-sum-iii-data-structure-design/
/// Author : liuyubobobo
/// Time   : 2016-12-03
#include <iostream>
#include <unordered_map>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Using HashMap
/// Time Complexity:  add: O(1) , find: O(n)
/// Space Complexity: O(n)
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

        for( unordered_map<int,int>::iterator iter = numbers.begin() ; iter != numbers.end() ; iter ++ ){
            int num = iter->first;
            if( numbers.find(value - num)  != numbers.end() ){
                if( value - num == num && numbers[num] == 1 )
                    continue;

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

    cout << twoSum.find(4) << endl;
    cout << twoSum.find(7) << endl;

    return 0;
}