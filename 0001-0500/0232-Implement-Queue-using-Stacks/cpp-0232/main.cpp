/// Source : https://leetcode.com/problems/implement-queue-using-stacks/description/
/// Author : liuyubobobo
/// Time   : 2018-09-14

#include <iostream>
#include <stack>

using namespace std;

/// Two Stacks
/// The Queue front is the top of Stack
///
/// Time Complexity: push: O(n)
///                  pop:  O(1)
///                  peek: O(1)
///                  empty: O(1)
///
/// Space Complexity: O(n)
class MyQueue {

private:
    stack<int> s;

public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> s2;
        while(!s.empty()){
            s2.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!s2.empty()){
            s.push(s2.top());
            s2.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {

        int ret = s.top();
        s.pop();

        return ret;
    }

    /** Get the front element. */
    int peek() {
        return s.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};


int main() {

    return 0;
}