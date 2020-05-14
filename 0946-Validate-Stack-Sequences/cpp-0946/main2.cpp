/// Source : https://leetcode.com/problems/validate-stack-sequences/
/// Author : liuyubobobo
/// Time   : 2018-11-25

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;


/// Using a stack to simulation
/// Greedy Thinking is used when deal with popped elements
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        stack<int> stack;
        int i = 0;
        for(int e: pushed){
            stack.push(e);
            while(i < popped.size() && !stack.empty() && popped[i] == stack.top()){
                stack.pop();
                i ++;
            }
        }
        return i == popped.size();
    }
};


int main() {

    return 0;
}