/// Source : https://leetcode.com/contest/warm-up-contest/problems/longest-absolute-file-path/
/// Author : liuyubobobo
/// Time   : 2017-10-19

#include <iostream>
#include <stack>
#include <cctype>
#include <cassert>
#include <string>

using namespace std;

// Using stack to simulate the dfs process
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int lengthLongestPath(string input) {

        //cout << input << endl;

        int res = 0;
        int curLength = 0;
        stack<string> dir;

        int start = 0;
        for(int i = 1 ; i <= input.size() ; ){
            if(i == input.size() || input[i] == '\n'){

                string curStr = input.substr(start, i-start);
                //cout << "cur str: " << curStr << endl;

                int j = start;
                while(input[j] == '\t')
                    j ++;
                string curDir = curStr.substr(j-start);
                int curDepth = j - start;

                if(curDepth < dir.size()){
                    assert(dir.size() >= (dir.size() - curDepth));

                    int pop_time = dir.size() - curDepth;
                    for(int k = 0 ; k < pop_time ; k ++){
                        curLength -= dir.top().size();
                        dir.pop();
                    }
                }
                else
                    assert(curDepth == dir.size());

                dir.push(curDir);
                curLength += curDir.size();

                if(curDir.find(".") != string::npos){
                    assert(dir.size() >= 1);
                    res = max(res, curLength + (int)dir.size() - 1);
                }

                start = i+1;
                i = start + 1;
            }
            else
                i ++;
        }

        return res;
    }
};

int main() {

    cout << Solution().lengthLongestPath(
            "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext") << endl;

    cout << Solution().lengthLongestPath(
            "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") << endl;

    cout << Solution().lengthLongestPath(
            "a\n\tb1\n\t\tf1.txt\n\taaaaa\n\t\tf2.txt") << endl;

    return 0;
}