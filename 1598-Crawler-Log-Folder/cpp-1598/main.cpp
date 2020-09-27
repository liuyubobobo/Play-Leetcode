/// Source : https://leetcode.com/problems/crawler-log-folder/
/// Author : liuyubobobo
/// Time   : 2020-09-26

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Using Stack
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minOperations(vector<string>& logs) {

        int stack = 0;
        for(const string& log: logs){
            if(log == "./") continue;
            else if(log == "../") stack = max(0, stack - 1);
            else stack ++;
        }
        return stack;
    }
};


int main() {

    vector<string> logs1 = {"d1/","d2/","../","d21/","./"};
    cout << Solution().minOperations(logs1) << endl;
    // 2

    vector<string> logs2 = {"d1/","d2/","./","d3/","../","d31/"};
    cout << Solution().minOperations(logs2) << endl;
    // 3

    vector<string> logs3 = {"d1/","../","../","../"};
    cout << Solution().minOperations(logs3) << endl;
    // 0

    return 0;
}
