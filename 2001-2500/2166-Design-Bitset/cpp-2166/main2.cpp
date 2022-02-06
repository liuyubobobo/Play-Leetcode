/// Source : https://leetcode.com/problems/design-bitset/
/// Author : liuyubobobo
/// Time   : 2021-02-06

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;


/// Using C++ STL Bitset
/// Time Complexity: init: O(sz)
///                  fix: O(1)
///                  unfix: O(1)
///                  flip: O(MAXN)
///                  all: O(MAXN)
///                  one: O(MAXN)
///                  count: O(MAXN)
///                  toString: O(sz)
/// Space Complexity: O(MAXN)
class Bitset {

private:
    int sz;
    bitset<100000> o, mask;

public:
    Bitset(int size) : sz(size), mask(0) {
        for(int i = 0; i < size; i ++)
            mask.set(i);
    }

    void fix(int idx) {
        o.set(sz - 1- idx);
    }

    void unfix(int idx) {
        o.reset(sz - 1- idx);
    }

    void flip() {
        o.flip();
        o &= mask;
    }

    bool all() {
        return (o & mask).count() == sz;
    }

    bool one() {
        return (o & mask).any();
    }

    int count() {
        return (o & mask).count();
    }

    string toString() {
        return o.to_string().substr(100000 - sz);
    }
};


int main() {

    return 0;
}
