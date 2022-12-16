/// Source : https://leetcode.com/problems/design-memory-allocator/description/
/// Author : liuyubobobo
/// Time   : 2022-12-15

#include <iostream>
#include <list>
#include <vector>

using namespace std;


/// Using LinkedList
/// Time Complexity: init: O(1)
///                  allocate: O(n)
///                  free: O(n)
/// Space Complexity: O(n)
class Allocator {

private:
    list<pair<int, int>> available; // start, end
    vector<list<pair<int, int>>> id2mem;

public:
    Allocator(int n) : id2mem(1001){
        available.push_back({0, n - 1});
    }

    int allocate(int size, int mID) {

        list<pair<int, int>>::iterator alloc_iter = available.end();
        for(auto iter = available.begin(); iter != available.end(); iter ++){
            int l = iter->first, r = iter->second, len = r - l + 1;
            if(len >= size){
                alloc_iter = iter;
                break;
            }
        }

        if(alloc_iter == available.end()) return -1;

        add(id2mem[mID], {alloc_iter->first, alloc_iter->first + size - 1});
        int ret = alloc_iter->first;
        alloc_iter->first += size;
        if(alloc_iter->first > alloc_iter->second) available.erase(alloc_iter);
        return ret;
    }

    int free(int mID) {

        int ret = 0;
        for(const pair<int, int>& p: id2mem[mID]) {
            ret += p.second - p.first + 1;
            add(available, p);
        }
        id2mem[mID].clear();
        return ret;
    }

private:
    void add(list<pair<int, int>>& l, const pair<int, int>& p){

        auto insert_pos_iter = l.end();
        for(auto iter = l.begin(); iter != l.end(); iter ++){
            if(iter->second + 1 == p.first){
                iter->second = p.second;
                insert_pos_iter = iter;
                break;
            }
            else if(iter->first > p.second){
                insert_pos_iter = iter;
//                insert_pos_iter --;
                insert_pos_iter = l.insert(insert_pos_iter, p);
                break;
            }
        }

        if(insert_pos_iter == l.end()){
            l.push_back(p);
            return;
        }

        auto next_iter = insert_pos_iter;
        next_iter ++;
        if(next_iter == l.end() || next_iter->first != insert_pos_iter->second + 1) return;

        insert_pos_iter->second = next_iter->second;
        l.erase(next_iter);
        return;
    }
};


int main() {

    Allocator allocator(10);
    cout << allocator.allocate(1, 1) << '\n'; // 0
    cout << allocator.allocate(1, 2) << '\n'; // 1
    cout << allocator.allocate(1, 3) << '\n'; // 2
    cout << allocator.free(2) << '\n'; // 1
    cout << allocator.allocate(3, 4) << '\n'; // 3
    cout << allocator.allocate(1, 3) << '\n'; // 1

    return 0;
}
