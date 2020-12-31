/// Source : https://leetcode.com/problems/time-based-key-value-store/
/// Author : liuyubobobo
/// Time   : 2019-01-28

#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;


/// Using TreeMap to store (time, value) pair information for each key
/// Time Complexity: init: O(1)
///                  set: O(logn)
///                  get: O(logn)
/// Space Complexity: O(n)
class TimeMap {

private:
    unordered_map<string, map<int, string>> timeMap; // key -> (time, value)

public:
    /** Initialize your data structure here. */
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        timeMap[key][timestamp] = value;
    }

    string get(string key, int timestamp) {

        map<int, string>::iterator iter =
                timeMap[key].lower_bound(timestamp);
        if(iter == timeMap[key].end() || iter->first > timestamp){
            if(iter == timeMap[key].begin()) return "";
            iter --;
        }
        return iter->second;
    }
};


int main() {

    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);
    cout << timeMap.get("foo", 1) << endl;
    // bar

    cout << timeMap.get("foo", 3) << endl;
    // bar

    timeMap.set("foo", "bar2", 4);
    cout << timeMap.get("foo", 4) << endl;
    // bar2

    cout << timeMap.get("foo", 5) << endl;
    // bar2

    cout << timeMap.get("foo", 1) << endl;
    // bar

    return 0;
}