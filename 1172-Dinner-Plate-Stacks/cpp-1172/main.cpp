/// Source : https://leetcode.com/problems/dinner-plate-stacks/
/// Author : liuyubobobo
/// Time   : 2019-08-25

#include <iostream>
#include <stack>
#include <vector>
#include <set>

using namespace std;


/// Using TreeSet
/// Time Complexity: init: O(1)
///                  push: O(|stacks|)
///                  pop: O(|stacks|)
/// Space Complexity: O(num_of_elements + |stacks|)
class DinnerPlates {

private:
    int C;
    vector<stack<int>> stacks;
    set<int> nonFullStack, nonEmptyStack;

public:
    DinnerPlates(int capacity): C(capacity){}

    void push(int val) {
        if(nonFullStack.size()){
            int index = *nonFullStack.begin();
            stacks[index].push(val);
            if(stacks[index].size() == C) nonFullStack.erase(index);
            nonEmptyStack.insert(index);
        }
        else{
            if(stacks.empty() || stacks.back().size() == C)
                stacks.push_back(stack<int>());
            stacks.back().push(val);
            nonEmptyStack.insert(stacks.size() - 1);
        }
    }

    int pop() {

        if(nonEmptyStack.size() == 0) return -1;
        int index = *nonEmptyStack.rbegin();
        int ret = stacks[index].top();
        stacks[index].pop();
        nonFullStack.insert(index);
        if(!stacks[index].size()) nonEmptyStack.erase(index);
        return ret;
    }

    int popAtStack(int index) {
        if(index < 0 || index >= stacks.size()) return -1;
        if(!stacks[index].size()) return -1;
        int ret = stacks[index].top();
        stacks[index].pop();
        nonFullStack.insert(index);
        if(!stacks[index].size()) nonEmptyStack.erase(index);
        return ret;
    }
};


int main() {

    return 0;
}