/// Source : https://leetcode.com/problems/implement-queue-using-stacks/description/
/// Author : liuyubobobo
/// Time   : 2018-09-14

#include <iostream>
#include <stack>

using namespace std;

/// Two Stacks
/// All the elements store in the two stacks all together
///
/// Time Complexity: push: O(1)
///                  pop:  O(1) in average
///                  peek: O(1)
///                  empty: O(1)
///
/// Space Complexity: O(n)
class MyQueue {

private:
    stack<int> s1, s2;
    int front;

public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        if(s1.empty())
            front = x;
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int ret = s2.top();
        s2.pop();
        return ret;
    }

    /** Get the front element. */
    int peek() {
        if(!s2.empty())
            return s2.top();
        return front;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};


int main() {

    return 0;
}