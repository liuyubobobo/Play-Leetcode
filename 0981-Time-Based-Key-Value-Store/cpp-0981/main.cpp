/// Source : https://leetcode.com/problems/time-based-key-value-store/
/// Author : liuyubobobo
/// Time   : 2019-01-26

#include <iostream>
#include <unordered_map>
#include <set>


/// Using TreeSet to store (time, value) pair information for each key
/// Time Complexity: init: O(1)
///                  set: O(logn)
///                  get: O(logn)
/// Space Complexity: O(n)
class TimeMap {

private:
    std::unordered_map<std::string, std::set<std::pair<int, std::string>>> map; // key -> (time, value)

public:
    /** Initialize your data structure here. */
    TimeMap() {}

    void set(std::string key, std::string value, int timestamp) {
        map[key].insert(make_pair(timestamp, value));
    }

    std::string get(std::string key, int timestamp) {

        std::set<std::pair<int, std::string>>::iterator iter =
                map[key].lower_bound(std::make_pair(timestamp, ""));
        if(iter == map[key].end() || iter->first > timestamp){
            if(iter == map[key].begin()) return "";
            iter --;
        }
        return iter->second;
    }
};


int main() {

    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);
    std::cout << timeMap.get("foo", 1) << std::endl;
    // bar

    std::cout << timeMap.get("foo", 3) << std::endl;
    // bar

    timeMap.set("foo", "bar2", 4);
    std::cout << timeMap.get("foo", 4) << std::endl;
    // bar2

    std::cout << timeMap.get("foo", 5) << std::endl;
    // bar2

    std::cout << timeMap.get("foo", 1) << std::endl;
    // bar

    return 0;
}