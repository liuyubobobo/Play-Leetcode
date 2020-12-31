/// Source : https://leetcode.com/problems/design-hashmap/description/
/// Author : liuyubobobo
/// Time   : 2018-06-07

#include <iostream>
#include <map>

using namespace std;

#define N 100000

/// Using map(which is RBTree) to construct HashMap
/// Time Complexity: O(1)
/// Space Complexity: O(n)
class MyHashMap {

private:
    map<int, int> data[N];

public:
    /** Initialize your data structure here. */
    MyHashMap() {

    }

    /** value will always be positive. */
    void put(int key, int value) {
        data[key % N][key] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        map<int, int>::iterator iter = data[key % N].find(key);
        if(iter == data[key % N].end())
            return -1;
        return data[key % N][key];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        data[key % N].erase(key);
    }
};


int main() {

    return 0;
}