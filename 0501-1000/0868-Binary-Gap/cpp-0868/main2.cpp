/// Source : https://leetcode.com/problems/binary-gap/description/
/// Author : liuyubobobo
/// Time   : 2018-07-14

#include <iostream>

using namespace std;


/// One Pass without store all the 'a''s index
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int binaryGap(int N) {

        int last = -1;
        int res = 0, index = 0;
        while(N){
            int bit = N & 1;
            if(bit){
                if(last != -1)
                    res = max(res, index - last);
                last = index;
            }

            index ++;
            N >>= 1;
        }

        return res;
    }
};


int main() {

    cout << Solution().binaryGap(22) << endl;
    cout << Solution().binaryGap(5) << endl;
    cout << Solution().binaryGap(6) << endl;
    cout << Solution().binaryGap(8) << endl;

    return 0;
}