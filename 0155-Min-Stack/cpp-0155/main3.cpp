/// Source : https://leetcode.com/problems/max-stack/description/
/// Author : liuyubobobo
/// Time   : 2017-11-28

#include <iostream>
#include <map>
#include <cassert>
#include <list>
#include <vector>

using namespace std;

/// Using a list to simulate th stack
/// Using a TreeMap to record every node in the list
/// So we can get the min value in the list quickly and erase it easily
/// Since the problen doesn't require popMin operation,
/// we may not see the advantage of this method,
/// But in problem 716, Max Stack, it's different.
/// https://leetcode.com/problems/max-stack/description/
///
/// Time Complexity: push: O(1)
///                  pop:  O(1)
///                  top:  O(1)
///                  peekMax: O(1)
///                  popMax:  O(logn)
/// Space Complexity: O(n)
class MinStack {

private:
    list<int> stack;
    map<int, vector<list<int>::iterator>> record;

public:
    /** initialize your data structure here. */
    MinStack() {
        stack.clear();
        record.clear();
    }

    void push(int x) {
        stack.push_back(x);

        list<int>::iterator iter = stack.begin();
        advance(iter, stack.size() - 1);

        record[x].push_back(iter);
    }

    int pop() {

        int ret = stack.back();
        stack.pop_back();

        record[ret].pop_back();
        if(record[ret].size() == 0)
            record.erase(ret);

        return ret;
    }

    int top() {
        assert(stack.size() > 0);
        return stack.back();
    }

    int getMin() {
        assert(stack.size() > 0);
        return record.begin()->first;
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