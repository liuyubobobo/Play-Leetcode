/// Source : https://leetcode.com/problems/design-memory-allocator/description/
/// Author : liuyubobobo
/// Time   : 2022-12-10

#include <iostream>
#include <set>
#include <vector>

using namespace std;


/// Using TreeSet
/// Time Complexity: init: O(1)
///                  allocate: O(n)
///                  free: O(n)
/// Space Complexity: O(n)
class Allocator {

private:
    set<pair<int, int>> mem;
    vector<vector<pair<int, int>>> id2mem;

public:
    Allocator(int n) : id2mem(1001){
        mem.insert({0, n - 1});
    }

    int allocate(int size, int mID) {

        pair<int, int> target = {-1, -1};
        for(const pair<int, int>& block: mem){
            int l = block.first, r = block.second, len = r - l + 1;
            if(len >= size){
                target = block;
                break;
            }
        }

        if(target.first == -1) return -1;

        id2mem[mID].push_back({target.first, target.first + size - 1});
        mem.erase(target);
        if(target.first + size <= target.second)
            mem.insert({target.first + size, target.second});
        return target.first;
    }

    int free(int mID) {

        int ret = 0;
        for(const pair<int, int>& p: id2mem[mID]) {
            pair<int, int> target = p;
            ret += target.second - target.first + 1;

            auto iter = mem.upper_bound(target);
            if (iter != mem.end() && iter->first == target.second + 1) {
                target.second = iter->second;
                mem.erase(iter);
            }

            iter = mem.upper_bound(target);
            if (iter != mem.begin()) {
                iter--;
                if (iter->second + 1 == target.first) {
                    target.first = iter->first;
                    mem.erase(iter);
                }
            }

            mem.insert(target);
        }
        id2mem[mID].clear();
        return ret;
    }
};


int main() {

    Allocator allocator(10);
    cout << allocator.allocate(1, 1) << '\n'; // 0
    cout << allocator.allocate(1, 2) << '\n'; // 1
    cout << allocator.allocate(1, 3) << '\n'; // 2
    cout << allocator.free(2) << '\n'; // 1
    cout << allocator.allocate(3, 4) << '\n'; // 3
    cout << allocator.allocate(1, 3) << '\n'; // 2

    return 0;
}
