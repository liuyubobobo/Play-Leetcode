/// Source : https://leetcode.com/problems/min-stack/description/
/// Author : liuyubobobo
/// Time   : 2017-11-16

#include <iostream>
#include <set>
#include <cassert>

using namespace std;

/// Using two sets
/// Time Complexity: push: O(nlogn)
///                  pop:  O(nlogn)
///                  top:  O(nlogn)
///                  getMin: O(nlogn)
/// Space Complexity: O(n)
class MinStack {

private:
    int index = 0;
    set<pair<int, int>> vi;   // value - index
    set<pair<int, int>> iv;   // index - value

public:
    /** initialize your data structure here. */
    MinStack() {
        vi.clear();
        iv.clear();
        index = 0;
    }

    void push(int x) {
        vi.insert(make_pair(x, index));
        iv.insert(make_pair(index, x));
        index ++;
    }

    int pop() {

        assert(iv.size() > 0);

        pair<int, int> e_iv = *iv.rbegin();
        iv.erase(e_iv);

        pair<int, int> e_vi = make_pair(e_iv.second, e_iv.first);
        vi.erase(e_vi);

        return e_iv.second;
    }

    int top() {
        assert(iv.size() > 0);
        return iv.rbegin()->second;
    }

    int getMin() {
        assert(vi.size() > 0);
        return vi.begin()->first;
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