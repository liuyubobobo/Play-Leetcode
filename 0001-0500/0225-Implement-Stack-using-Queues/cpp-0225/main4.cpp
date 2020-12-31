/// Source : https://leetcode.com/problems/implement-stack-using-queues/description/
/// Author : liuyubobobo
/// Time   : 2018-09-29

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;


/// Using only one queue!
///
/// Time Complexity: init: O(1)
///                  push: O(n)
///                  pop: O(1)
///                  top: O(1)
///                  empty: O(1)
/// Space Complexity: O(n)
class MyStack {

private:
    queue<int> q;
    int sz = 0;

public:
    /** Initialize your data structure here. */
    MyStack(): sz(0) {}

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for(int i = 0; i < sz; i ++){
            int e = q.front();
            q.pop();
            q.push(e);
        }
        sz ++;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {

        assert(!empty());
        int ret = q.front();
        q.pop();
        sz --;
        return ret;
    }

    /** Get the top element. */
    int top() {
        assert(!empty());
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};


int main() {

    return 0;
}