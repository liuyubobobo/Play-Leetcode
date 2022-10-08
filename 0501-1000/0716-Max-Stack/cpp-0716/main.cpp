/// Source : https://leetcode.com/problems/max-stack/description/
/// Author : liuyubobobo
/// Time   : 2017-11-16

#include <iostream>
#include <set>
#include <cassert>

using namespace std;


/// Using two sets
/// Time Complexity: push: O(logn)
///                  pop:  O(logn)
///                  top:  O(logn)
///                  peekMax: O(logn)
///                  popMax:  O(logn)
/// Space Complexity: O(n)
class MaxStack {

private:
    int index = 0;
    set<pair<int, int>> vi;   // value - index
    set<pair<int, int>> iv;   // index - value

public:
    /** initialize your data structure here. */
    MaxStack() {
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

    int peekMax() {
        assert(vi.size() > 0);
        return vi.rbegin()->first;
    }

    int popMax() {

        assert(vi.size() > 0);

        pair<int, int> e_vi = *vi.rbegin();
        vi.erase(e_vi);

        pair<int, int> e_iv = make_pair(e_vi.second, e_vi.first);
        iv.erase(e_iv);

        return e_vi.first;
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