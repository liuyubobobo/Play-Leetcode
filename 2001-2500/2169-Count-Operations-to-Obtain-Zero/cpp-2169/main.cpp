/// Source : https://leetcode.com/problems/count-operations-to-obtain-zero/
/// Author : liuyubobobo
/// Time   : 2022-02-12

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(max(num1, num2) / min(num1, num2))
/// Space Compelxity: O(1)
class Solution {
public:
    int countOperations(int num1, int num2) {

        int res = 0;
        while(num1 && num2){
            if(num1 >= num2) num1 -= num2;
            else num2 -= num1;
            res ++;
        }
        return res;
    }
};


int main() {

    return 0;
}
