/// Source : https://leetcode.com/problems/design-file-system/
/// Author : liuyubobobo
/// Time   : 2019-08-24
/// Updated: 2022-04-21

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;


/// Using HashMap
/// Time Complexity: createPath: O(|path|)
///                  get: O(|path|)
/// Space Complexity: O(|query| * |path|)
class FileSystem {

private:
    unordered_map<string, int> map;

public:
    FileSystem() {
        map[""] = -1;
    }

    bool createPath(string path, int value) {

        if(map.count(path)) return false;

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
    cout << fs.createPath("/leet", 1) << endl;
    cout << fs.createPath("/leet/code", 2) << endl;
    cout << fs.get("/leet/code") << endl;
    cout << fs.createPath("/c/d", 1) << endl; // false
    cout << fs.get("/c") << endl; // -1

    return 0;
}