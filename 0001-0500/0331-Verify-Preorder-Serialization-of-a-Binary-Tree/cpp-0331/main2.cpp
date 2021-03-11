/// Source : https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
/// Author : liuyubobobo
/// Time   : 2021-03-11

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Using slots
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool isValidSerialization(string preorder) {

        vector<int> data;
        for(int start = 0, i = 1; i <= preorder.size(); i ++)
            if(i == preorder.size() || preorder[i] == ','){
                if(preorder[start] == '#')
                    data.push_back(-1);
                else
                    data.push_back(atoi(preorder.substr(start, i - start).c_str()));

                start = i + 1;
                i = start;
            }

        int slots = 1;
        for(int e: data){
            slots --;
            if(slots < 0) return false;

            if(e != -1) slots += 2;

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
