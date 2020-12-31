/// Source : https://leetcode.com/problems/snapshot-array/
/// Author : liuyubobobo
/// Time   : 2019-08-03

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Binary Search
/// Time Comnplexity: init: O(n)
///                   set: O(1)
///                   snap: O(1)
///                   get: O(log(calls))
class SnapshotArray {

private:
    vector<vector<pair<int, int>>> data;
    int id = 0;

public:
    SnapshotArray(int length) {

        data.resize(length);
        for(int i = 0; i < length; i ++)
            data[i].push_back(make_pair(-1, 0));
    }

    void set(int index, int val) {
        data[index].push_back(make_pair(id, val));
    }

    int snap() {
        return id ++;
    }

    int get(int index, int snap_id) {

        if(!data[index].size()) return 0;
        auto iter = lower_bound(data[index].begin(), data[index].end(), make_pair(snap_id + 1, INT_MIN));
        iter --;
        return iter->second;
    }
};


int main() {

    SnapshotArray o1(4);
    cout << o1.snap() << endl; // 0
    cout << o1.snap() << endl; // 1
    cout << o1.get(3, 1) << endl; // 0
    o1.set(2, 4);
    cout << o1.snap() << endl; // 2
    o1.set(1, 4);

    SnapshotArray o2(1);
    o2.set(0, 15);
    cout << o2.snap() << endl; // 0
    cout << o2.snap() << endl; // 1
    cout << o2.snap() << endl; // 2
    cout << o2.get(0, 2) << endl; // 15
    cout << o2.snap() << endl; // 3
    cout << o2.snap() << endl; // 4
    cout << o2.get(0, 0) << endl; // 15

    return 0;
}