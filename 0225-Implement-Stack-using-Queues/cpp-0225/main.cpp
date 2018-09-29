/// Source : https://leetcode.com/problems/implement-stack-using-queues/description/
/// Author : liuyubobobo
/// Time   : 2018-09-29

#include <iostream>
#include <queue>

using namespace std;


/// Naive Implementation
/// Time Complexity: init: O(1)
///                  push: O(1)
///                  pop: O(n)
///                  top: O(n)
///                  empty: O(1)
/// Space Complexity: O(n)
class MyStack {

private:
    queue<int> q;

public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {

        assert(!empty());

        queue<int> q2;
        while(q.size() > 1){
            q2.push(q.front());
            q.pop();
        }

        int ret = q.front();
        q.pop();

        while(!q2.empty()){
            q.push(q2.front());
            q2.pop();
        }

        return ret;
    }

    /** Get the top element. */
    int top() {

        assert(!empty());

        queue<int> q2;
        while(q.size() > 1){
            q2.push(q.front());
            q.pop();
        }

        int ret = q.front();
        q2.push(ret);
        q.pop();

        while(!q2.empty()){
            q.push(q2.front());
            q2.pop();
        }

        return ret;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};


int main() {

    return 0;
}