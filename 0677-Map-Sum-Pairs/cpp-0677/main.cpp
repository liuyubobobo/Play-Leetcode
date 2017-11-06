/// Source : https://leetcode.com/problems/map-sum-pairs/description/
/// Author : liuyubobobo
/// Time   : 2017-11-05

#include <iostream>
#include <unordered_map>

using namespace std;

/// HashMap + Brute Force
/// Time Complexity: insert: O(1)
///                  sum: O(n * len(prefix))
/// Space Complexity: O(sum(len(wi))) where wi is the length of the ith word.
class MapSum {

private:
    unordered_map<string, int> mapsum;

public:
    /** Initialize your data structure here. */
    MapSum() {
        mapsum.clear();
    }

    void insert(string key, int val) {
        mapsum[key] = val;
    }

    int sum(string prefix) {
        int ret = 0;
        for(pair<string, int> e: mapsum)
            if(e.first.substr(0, prefix.size()) == prefix)
                ret += e.second;
        return ret;
    }
};

int main() {

    MapSum obj;
    obj.insert("apple", 3);
    cout << obj.sum("ap") << endl; // 3
    obj.insert("app", 2);
    cout << obj.sum("ap") << endl; // 5

    return 0;
}