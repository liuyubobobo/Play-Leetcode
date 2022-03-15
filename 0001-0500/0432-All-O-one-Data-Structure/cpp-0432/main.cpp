/// Source : https://leetcode.com/problems/all-oone-data-structure/
/// Author : liuyubobobo
/// Time   : 2022-03-15

#include <iostream>
#include <map>
#include <set>

using namespace std;


/// Map + Set
/// Time Complexity: O(logn) for all operations
/// Space Complexity: O(n)
class AllOne {

private:
    map<string, int> f;
    set<pair<int, string>> fs_set;

public:
    AllOne() {}

    void inc(string key) {
        int old_f = f[key];
        f[key] ++;

        if(old_f) fs_set.erase({old_f, key});
        fs_set.insert({old_f + 1, key});
    }

    void dec(string key) {
        int old_f = f[key];
        f[key] --;
        if(old_f - 1 == 0) f.erase(key);

        fs_set.erase({old_f, key});
        if(old_f - 1) fs_set.insert({old_f - 1, key});
    }

    string getMaxKey() {
        if(fs_set.empty()) return "";
        return fs_set.rbegin()->second;
    }

    string getMinKey() {
        if(fs_set.empty()) return "";
        return fs_set.begin()->second;
    }
};


int main() {

    AllOne obj;
    obj.inc("hello");
    obj.inc("hello");
    cout << obj.getMaxKey() << '\n';
    cout << obj.getMinKey() << '\n';

    obj.inc("leet");
    cout << obj.getMaxKey() << '\n';
    cout << obj.getMinKey() << '\n';

    return 0;
}
