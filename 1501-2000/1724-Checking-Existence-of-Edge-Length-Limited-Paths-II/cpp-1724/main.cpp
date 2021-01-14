/// Source : https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths-ii/
/// Author : liuyubobobo
/// Time   : 2021-01-14

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// MST and Keep all the UF status
/// Time Complexity: init: O(EVlogE)
///                  query: O(log(LIMIT))
/// Space Comoplexity: O(EV)
class UF{

public:
    vector<int> parent;

    UF(int n) : parent(n){
        for(int i = 0 ; i < n ; i ++)
            parent[i] = i;
    }

    int find(int p, vector<int>* data = nullptr){

        if(data == nullptr) data = &parent;
        while(p != (*data)[p])
            p = (*data)[p];
        return p;
    }

    bool isConnected(int p, int q, vector<int>* data = nullptr){
        return find(p, data) == find(q, data);
    }

    void unionElements(int p, int q){

        int pRoot = find(p), qRoot = find(q);

        if(pRoot == qRoot) return;

        parent[pRoot] = qRoot;
    }
};


class DistanceLimitedPathsExist {

private:
    map<int, vector<int>> table;
    UF uf;

public:
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edges) : uf(n){

        sort(edges.begin(), edges.end(), [](const vector<int>& e1, const vector<int>& e2){
            return e1[2] < e2[2];
        });

        for(const vector<int>& e: edges)
            if(!uf.isConnected(e[0], e[1])){
                uf.unionElements(e[0], e[1]);
                table[e[2]] = uf.parent;
            }
    }

    bool query(int p, int q, int limit) {

        map<int, vector<int>>::iterator iter = table.lower_bound(limit);
        if(iter == table.begin() && iter->first >= limit) return false;

        iter --;
        return uf.isConnected(p, q, &iter->second);
    }
};


int main() {

    vector<vector<int>> edges1 = {{0, 2, 4}, {0, 3, 2}, {1, 2, 3}, {2, 3, 1}, {4, 5, 5}};
    DistanceLimitedPathsExist obj1(6, edges1);
    cout << obj1.query(2, 3, 2) << endl; // 1
    cout << obj1.query(1, 3, 3) << endl; // 0
    cout << obj1.query(2, 0, 3) << endl; // 1
    cout << obj1.query(0, 5, 6) << endl; // 0

    cout << endl;

    vector<vector<int>> edges2 = {{1, 0, 3}, {1, 0, 5}, {1, 2, 1}, {1, 0, 2}, {2, 0, 1}, {0, 1, 3}};
    DistanceLimitedPathsExist obj2(3, edges2);
    cout << obj2.query(2, 1, 5) << endl; // 1
    cout << obj2.query(1, 0, 5) << endl; // 1
    cout << obj2.query(2, 1, 3) << endl; // 1

    return 0;
}
