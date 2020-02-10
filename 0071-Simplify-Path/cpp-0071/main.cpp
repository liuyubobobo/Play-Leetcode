/// Source : https://leetcode.com/problems/simplify-path/
/// Author : liuyubobobo
/// Time   : 2019-02-10

#include <iostream>
#include <vector>

using namespace std;


/// Using Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string simplifyPath(string path) {

        vector<string> stack;
        for(int start = 1, i = 1; i <= path.size(); i ++)
            if(i == path.size() || path[i] == '/'){
                string f = path.substr(start, i - start);
                if(f.size()){
                    if(f == ".."){
                        if(stack.size()) stack.pop_back();
                    }
                    else if(f != ".") stack.push_back(f);
                }
                start = i + 1;
            }

        string res = "";
        for(string e: stack)
            res += "/" + e;
        return res == "" ? "/" : res;
    }
};


int main() {

    return 0;
}
