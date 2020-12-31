/// Source : https://leetcode.com/problems/design-file-system/
/// Author : liuyubobobo
/// Time   : 2019-08-24

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;


/// Using HashMap
/// Time Complexity: create: O(|path|)
///                  get: O(1)
/// Space Complexity: O(|query| * |path|)
class FileSystem {

private:
    unordered_map<string, int> map;

public:
    FileSystem() {
        map[""] = -1;
    }

    bool create(string path, int value) {

        int last = path.rfind('/');
        if(!map.count(path.substr(0, last))) return false;

        map[path] = value;
        return true;
    }

    int get(string path) {
        return map.count(path) ? map[path] : -1;
    }
};


int main() {

    FileSystem fs;
    cout << fs.create("/leet", 1) << endl;
    cout << fs.create("/leet/code", 2) << endl;
    cout << fs.get("/leet/code") << endl;
    cout << fs.create("/c/d", 1) << endl; // false
    cout << fs.get("/c") << endl; // -1

    return 0;
}