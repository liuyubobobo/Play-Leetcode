/// Source : https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
/// Author : liuyubobobo
/// Time   : 2021-03-11

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Split and using slots
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool isValidSerialization(string preorder) {

        int slots = 1;
        for(int start = 0, i = 1; i <= preorder.size(); i ++)
            if(i == preorder.size() || preorder[i] == ','){
                int cur = 0;
                if(preorder[start] != '#')
                    cur = 1;

                slots --;
                if(slots < 0) return false;
                if(cur) slots += 2;

                start = i + 1;
                i = start;
            }
        return slots == 0;
    }
};


int main() {

    cout << Solution().isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    // true

    cout << Solution().isValidSerialization("1,#") << endl;
    // false

    cout << Solution().isValidSerialization("9,#,#,1") << endl;
    // false

    cout << Solution().isValidSerialization("9,3,4,#,#,1,#,#,#,2,#,6,#,#") << endl;
    // false

    return 0;
}
