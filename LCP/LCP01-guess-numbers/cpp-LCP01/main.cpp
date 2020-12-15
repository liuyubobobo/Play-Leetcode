/// Source : https://leetcode-cn.com/problems/guess-numbers/
/// Author : liuyubobobo
/// Time   : 2020-04-30

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {

        int res = 0;
        for(int i = 0; i < guess.size(); i ++)
            res += guess[i] == answer[i];
        return res;
    }
};


int main() {

    return 0;
}
