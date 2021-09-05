/// Source : https://leetcode.com/problems/operations-on-tree/
/// Author : liuyubobobo
/// Time   : 2021-09-05

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: init: O(n)
///                  lock: O(1)
///                  unlock: O(1)
///                  upgrade: O(n)
/// Space Complexity: O(n)
class LockingTree {

private:
    int n;
    vector<int> parent;
    vector<vector<int>> tree;
    vector<int> locked;

public:
    LockingTree(vector<int>& parent) : n(parent.size()), parent(parent), tree(n), locked(n, 0) {

        for(int i = 1; i < n; i ++)
            tree[parent[i]].push_back(i);
    }

    bool lock(int num, int user) {

        if(locked[num]) return false;

        locked[num] = user;
        return true;
    }

    bool unlock(int num, int user) {

        if(locked[num] != user) return false;

        locked[num] = 0;
        return true;
    }

    bool upgrade(int num, int user) {

        if(locked[num]) return false;

        int locked_descendants = get_locked_descendants(num, parent[num]);
        if(locked_descendants == 0) return false;

        int locked_ancestors = get_locked_ancestors(num);
        if(locked_ancestors) return false;

        unlock_descendants(num, parent[num]);
        locked[num] = user;
        return true;
    }

private:
    void unlock_descendants(int u, int p){

        if(locked[u]) locked[u] = 0;
        for(int v: tree[u])
            if(v != p) unlock_descendants(v, u);
    }

    int get_locked_descendants(int u, int p){

        int res = 0;
        if(locked[u]) res ++;
        for(int v: tree[u])
            if(v != p) res += get_locked_descendants(v, u);
        return res;
    }

    int get_locked_ancestors(int u){

        int res = 0;
        while(u != -1){
            res += !!locked[u];
            u = parent[u];
        }
        return res;
    }
};


int main() {

    return 0;
}
