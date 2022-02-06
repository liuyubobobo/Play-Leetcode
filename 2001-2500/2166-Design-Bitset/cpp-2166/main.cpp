/// Source : https://leetcode.com/problems/design-bitset/
/// Author : liuyubobobo
/// Time   : 2021-02-06

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;


/// Using Array
/// Time Complexity: init: O(1)
///                  fix: O(1)
///                  unfix: O(1)
///                  flip: O(1)
///                  all: O(1)
///                  one: O(1)
///                  count: O(1)
///                  toString: O(sz)
/// Space Complexity: O(sz)
class Bitset {

private:
    int sz;
    vector<int> v;
    int ones, flipped;

public:
    Bitset(int size) : sz(size), v(sz, 0), ones(0), flipped(0) {
    }

    void fix(int idx) {
        if(!flipped){
            if(v[idx] == 0) v[idx] = 1, ones ++;
        }
        else{
            if(v[idx] == 1) v[idx] = 0, ones ++;
        }
    }

    void unfix(int idx) {
        if(!flipped){
            if(v[idx] == 1) v[idx] = 0, ones --;
        }
        else{
            if(v[idx] == 0) v[idx] = 1, ones --;
        }
    }

    void flip() {
        flipped ^= 1;
        ones = sz - ones;
    }

    bool all() {
        return ones == sz;
    }

    bool one() {
        return ones;
    }

    int count() {
        return ones;
    }

    string toString() {
        string res = "";
        for(int e: v) res += (char)('0' + (flipped ? 1 - e : e));
        return res;
    }
};


int main() {

    return 0;
}
