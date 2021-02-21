/// Source : https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
/// Author : liuyubobobo
/// Time   : 2021-02-21

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> minOperations(string boxes) {

        int left = 0, left_move = 0, right = 0, right_move = 0;
        for(int i = 0; i < boxes.size(); i ++)
            if(boxes[i] == '1') right ++, right_move += i;

        vector<int> res(boxes.size(), 0);
        for(int i = 0; i < boxes.size(); i ++){
            res[i] = left_move + right_move;
            right -= boxes[i] == '1';
            left += boxes[i] == '1';
            right_move -= right;
            left_move += left;
        }
        return res;
    }
};


int main() {

    return 0;
}
