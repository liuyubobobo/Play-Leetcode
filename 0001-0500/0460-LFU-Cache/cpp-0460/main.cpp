/// Source : https://leetcode.com/problems/lfu-cache/description/
/// Author : liuyubobobo
/// Time   : 2023-01-28

#include <iostream>
#include <map>
#include <cassert>

using namespace std;


/// Using Map
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class LFUCache {

private:
    map<int, int> cache; // key->value
    map<int, pair<int, int>> f;  // key->{f, timer}
    map<pair<int, int>, int> f2; // {f, timer}->key
    int capacity, timer;

public:
    LFUCache(int capacity) : capacity(capacity), timer(0) {}

    int get(int key) {
        auto iter = cache.find(key);
        if(iter == cache.end()) return -1;

        assert(f.count(key));
        pair<int, int> old_f = f[key];
        pair<int, int> new_f = {old_f.first + 1, timer ++};
        f[key] = new_f;

        assert(f2.count(old_f));
        f2.erase(old_f);
        f2[new_f] = key;

        return iter->second;
    }

    void put(int key, int value) {

        auto iter = cache.find(key);
        if(iter != cache.end()){
            update(key, value);
            return;
        }

        if(cache.size() == capacity){
            pair<int, int> del_f = f2.begin()->first;
            int key = f2[del_f];

            cache.erase(key);
            f.erase(key);
            f2.erase(f2.begin());
        }

        if(cache.size() < capacity){
            cache[key] = value;
            pair<int, int> new_f = {1, timer ++};
            f[key] = new_f;
            f2[new_f] = key;
        }
    }

private:
    void update(int key, int value){

        auto iter = cache.find(key);
        assert(iter != cache.end());

        assert(f.count(key));
        pair<int, int> old_f = f[key];
        pair<int, int> new_f = {old_f.first + 1, timer ++};
        f[key] = new_f;

        assert(f2.count(old_f));
        f2.erase(old_f);
        f2[new_f] = key;

        cache[key] = value;
    }
};


int main() {

    return 0;
}
