/// Source : https://leetcode.com/problems/plus-one/description/
/// Author : liuyubobobo
/// Time   : 2018-06-03

#include <iostream>
#include <vector>

using namespace std;

/// Ad Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        digits[digits.size() - 1] ++;
        for(int i = digits.size() - 1 ; i >= 1 ; i --)
            if(digits[i] == 10){
                digits[i] = 0;
                digits[i - 1] ++;
            }

        if(digits[0] == 10){
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};


int main() {

    return 0;
}