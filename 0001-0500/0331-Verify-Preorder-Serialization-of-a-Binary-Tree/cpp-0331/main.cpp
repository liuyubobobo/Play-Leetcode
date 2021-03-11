/// Source : https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
/// Author : liuyubobobo
/// Time   : 2021-03-11

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Using Stack to simulate
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

        if(data.size() == 1 && data[0] == -1) return true;

        stack<pair<int, int>> stack;
        for(int i = 0; i < data.size(); i ++){
            int e = data[i];
            if(e == -1){
                if(stack.empty()) return false;
                stack.top().second ++;

                while(!stack.empty() && stack.top().second == 2)
                    stack.pop();
            }
            else{
                if(stack.empty()){
                    if(i) return false;
                }
                else
                    stack.top().second ++;
                stack.push({e, 0});
            }
        }
        return stack.empty();
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
