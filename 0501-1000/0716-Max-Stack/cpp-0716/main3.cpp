/// Source : https://leetcode.com/problems/max-stack/description/
/// Author : liuyubobobo
/// Time   : 2017-11-27

#include <iostream>
#include <map>
#include <cassert>
#include <list>
#include <vector>

using namespace std;

/// Using a list to simulate th stack
/// Using a TreeMap to record every node in the list
/// So we can get the max value in the list quickly and erase it easily
///
/// Time Complexity: push: O(1)
///                  pop:  O(1)
///                  top:  O(1)
///                  peekMax: O(1)
///                  popMax:  O(logn)
/// Space Complexity: O(n)
class MaxStack {

private:
    list<int> stack;
    map<int, vector<list<int>::iterator>> record;

public:
    /** initialize your data structure here. */
    MaxStack() {
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

    int peekMax() {
        assert(stack.size() > 0);
        return record.rbegin()->first;
    }

    int popMax() {
        assert(stack.size() > 0);
        int ret = record.rbegin()->first;

        stack.erase((record.rbegin()->second).back());
        (record.rbegin()->second).pop_back();
        if((record.rbegin()->second).size() == 0)
            record.erase(ret);
        return ret;
    }
};


int main() {

    MaxStack stack1;
    stack1.push(5);
    stack1.push(1);
    stack1.push(5);
    cout << stack1.top() << endl;     // -> 5
    cout << stack1.popMax() << endl;  // -> 5
    cout << stack1.top() << endl;     // -> 1
    cout << stack1.peekMax() << endl; // -> 5
    cout << stack1.pop() << endl;     // -> 1
    cout << stack1.top() << endl;     // -> 5
    cout << endl;

    // ---

    MaxStack stack2;
    stack2.push(-83);
    stack2.push(-1);
    stack2.push(98);
    stack2.push(38);
    stack2.push(-99);
    cout << stack2.top() << endl;     // -> -99
    cout << stack2.popMax() << endl;  // -> 98
    cout << stack2.popMax() << endl;  // -> 38
    stack2.push(-92);
    stack2.push(-17);
    stack2.push(-1);
    stack2.push(-74);
    cout << stack2.popMax() << endl;  // -> -1
    cout << stack2.pop() << endl;     // -> -74
    cout << stack2.popMax() << endl;  // -> -1
    stack2.push(-80);
    stack2.push(-13);
    cout << stack2.top() << endl;     // -13
    stack2.push(-25);
    cout << endl;

    // ---

    MaxStack stack3;
    stack3.push(74);
    cout << stack3.popMax() << endl;  // -> 74
    stack3.push(89);
    stack3.push(67);
    cout << stack3.popMax() << endl;  // -> 89
    cout << stack3.pop() << endl;     // -> 67
    stack3.push(61);
    stack3.push(-77);
    cout << stack3.peekMax() << endl; // 61
    cout << stack3.popMax() << endl;  // 61
    stack3.push(81);
    cout << stack3.pop() << endl;     // 81
    stack3.push(-71);
    stack3.push(32);

    return 0;
}