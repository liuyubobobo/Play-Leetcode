/// Source : https://leetcode.com/problems/implement-queue-using-stacks/description/
/// Author : liuyubobobo
/// Time   : 2018-05-14

#include <iostream>
#include <stack>

using namespace std;

/// Two Stacks
/// The Queue tail is the top of Stack
///
/// Time Complexity: push: O(1)
///                  pop:  O(n)
///                  peek: O(n)
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
        s.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {

        stack<int> s2;
        while(!s.empty()){
            s2.push(s.top());
            s.pop();
        }

        int ret = s2.top();
        s2.pop();

        while(!s2.empty()){
            s.push(s2.top());
            s2.pop();
        }

        return ret;
    }

    /** Get the front element. */
    int peek() {
        stack<int> s2;
        while(!s.empty()){
            s2.push(s.top());
            s.pop();
        }

        int ret = s2.top();

        while(!s2.empty()){
            s.push(s2.top());
            s2.pop();
        }

        return ret;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};


int main() {

    return 0;
}