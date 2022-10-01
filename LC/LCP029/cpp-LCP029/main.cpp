/// Source : https://leetcode-cn.com/problems/SNJvJP/
/// Author : liuyubobobo
/// Time   : 2021-04-04

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Mathematics
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int orchestraLayout(int num, int xPos, int yPos) {

        if(num % 2 && xPos == num / 2 && yPos == num / 2){
            int res = num % 9 * num % 9 % 9;
            if(res == 0) res = 9;
            return res;
        }

        int top = xPos, bottom = num - xPos - 1, left = yPos, right = num - yPos - 1;
        int side = min(min(top, bottom), min(left, right));

        int total = (long long)(num - side) * 4ll * (long long)side % 9ll;

        xPos -= side, yPos -= side;
        int edge = num - side * 2;

        if(xPos == 0){
            int res = (total + yPos + 1) % 9;
            if(res == 0) res = 9;
            return res;
        }

        if(yPos == num - 2 * side - 1){
            int res = ((total + edge) % 9 + xPos) % 9;
            if(res == 0) res = 9;
            return res;
        }

        if(xPos == num - 2 * side - 1){
            int res = (total + edge) % 9;
            res = (res + edge - 1) % 9;
            res = (res + edge - 1 - yPos) % 9;
            if(res == 0) res = 9;
            return res;
        }

        assert(yPos == 0);
        int res = (total + edge) % 9;
        res = (res + edge - 1) % 9;
        res = (res + edge - 1) % 9;
        res = (res + edge - 1 - xPos) % 9;
        if(res == 0) res = 9;
        return res;
    }
};


int main() {

    cout << Solution().orchestraLayout(3, 0, 2) << endl;
    // 3

    cout << Solution().orchestraLayout(4, 1, 2) << endl;
    // 5

    cout << Solution().orchestraLayout(7, 1, 1) << endl;
    // 7

    int side = 7;
    for(int i = 0; i < side; i ++){
        for(int j = 0; j < side; j ++)
            cout << Solution().orchestraLayout(side, i, j) << " ";
        cout << endl;
    }
    return 0;
}
