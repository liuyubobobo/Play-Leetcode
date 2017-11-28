/// Source : https://leetcode.com/problems/max-stack/description/
/// Author : liuyubobobo
/// Time   : 2017-11-27

#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

/// Using two stacks
/// We have one regular stack for push, pop and top operations
/// We have another stack for peekMax and popMax operations, which named maxStack
/// maxStack will store the current max value in the stack
/// for popMax, we will find the max value in the stack in O(n) time
///
/// Time Complexity: push: O(1)
///                  pop:  O(1)
///                  top:  O(1)
///                  peekMax: O(1)
///                  popMax:  O(n)
/// Space Complexity: O(n)
class MaxStack {

private:
    stack<int> normalStack;
    stack<int> maxStack;

public:
    /** initialize your data structure here. */
    MaxStack() {
        while(!normalStack.empty())
            normalStack.pop();

        while(!maxStack.empty())
            maxStack.pop();
    }

    void push(int x) {
        normalStack.push(x);
        if(maxStack.empty())
            maxStack.push(x);
        else
            maxStack.push(max(maxStack.top(), x));
    }

    int pop() {

        assert(normalStack.size() > 0);

        int v = normalStack.top();
        normalStack.pop();
        maxStack.pop();

        return v;
    }

    int top() {
        assert(normalStack.size() > 0);
        return normalStack.top();
    }

    int peekMax() {
        assert(normalStack.size() > 0);
        return maxStack.top();
    }

    int popMax() {

        assert(normalStack.size() > 0);

        int maxValue = peekMax();
        stack<int> tstack;

        while(true){
            int value = pop();

            if(value == maxValue)
                break;

            tstack.push(value);
        }

        while(!tstack.empty()){
            push(tstack.top());
            tstack.pop();
        }

        return maxValue;
    }
};

int main() {

    MaxStack stack;
    stack.push(5);
    stack.push(1);
    stack.push(5);
    cout << stack.top() << endl;     // -> 5
    cout << stack.popMax() << endl;  // -> 5
    cout << stack.top() << endl;     // -> 1
    cout << stack.peekMax() << endl; // -> 5
    cout << stack.pop() << endl;     // -> 1
    cout << stack.top() << endl;     // -> 5

    return 0;
}