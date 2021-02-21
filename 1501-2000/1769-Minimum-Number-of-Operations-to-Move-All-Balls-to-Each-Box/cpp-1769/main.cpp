/// Source : https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
/// Author : liuyubobobo
/// Time   : 2021-02-21

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> minOperations(string boxes) {

        int n = boxes.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                if(boxes[j] == '1') res[i] += abs(i - j);
        return res;
    }
};


int main() {

    return 0;
}
