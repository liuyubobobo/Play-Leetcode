/// Source : https://leetcode.com/problems/max-stack/description/
/// Author : liuyubobobo
/// Time   : 2017-11-28

#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

/// Using two stacks
/// We have one regular stack for push, pop and top operations
/// We have another stack for getMin operations, which named minStack
/// minStack will store the current min value in the stack
///
/// Time Complexity: push: O(1)
///                  pop:  O(1)
///                  top:  O(1)
///                  getMin: O(1)
/// Space Complexity: O(n)
class MinStack {

private:
    stack<int> normalStack;
    stack<int> minStack;

public:
    /** initialize your data structure here. */
    MinStack() {
        while(!normalStack.empty())
            normalStack.pop();

        while(!minStack.empty())
            minStack.pop();
    }

    void push(int x) {
        normalStack.push(x);
        if(minStack.empty())
            minStack.push(x);
        else
            minStack.push(min(minStack.top(), x));
    }

    int pop() {

        assert(normalStack.size() > 0);

        int v = normalStack.top();
        normalStack.pop();
        minStack.pop();

        return v;
    }

    int top() {
        assert(normalStack.size() > 0);
        return normalStack.top();
    }

    int getMin() {
        assert(normalStack.size() > 0);
        return minStack.top();
    }
};


int main() {

    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // -> -3
    minStack.pop();
    cout << minStack.top() << endl;    // -> 0
    cout << minStack.getMin() << endl; // -> -2

    return 0;
}