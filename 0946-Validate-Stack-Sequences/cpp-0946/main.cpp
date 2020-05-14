/// Source : https://leetcode.com/problems/validate-stack-sequences/
/// Author : liuyubobobo
/// Time   : 2018-11-24

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;


/// Using a stack to simulation
/// and using a HashSet to record every elements
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        unordered_set<int> set;
        stack<int> stack;
        int i = 0;
        for(int e: pushed){
            stack.push(e);
            set.insert(e);

            while(i < popped.size() && !stack.empty() && popped[i] == stack.top()){
                stack.pop();
                set.erase(e);
                i ++;
            }

            if(i < popped.size() && !stack.empty()
               && popped[i] != stack.top() && set.count(popped[i]))
                return false;
        }
        return stack.empty();
    }
};


int main() {

    return 0;
}