/// Source : https://leetcode.com/problems/find-all-people-with-secret/
/// Author : liuyubobobo
/// Time   : 2021-11-27

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;


/// UF + BFS
/// Time Complexity: O(n + m)
/// Space Complexity: O(n)
class UF{

private:
    vector<int> parent;

public:
    UF(int n) : parent(n){
        for(int i = 0 ; i < n ; i ++)
            parent[i] = i;
    }

    int find(int p){
        if(p != parent[p])
            parent[p] = find(parent[p]);
        return parent[p];
    }

    bool is_connected(int p, int q){
        return find(p) == find(q);
    }

    void union_elements(int p, int q){

        int p_root = find(p), q_root = find(q);

        if(p_root == q_root) return;

        parent[p_root] = q_root;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        UF uf(n);
        uf.union_elements(0, firstPerson);

        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& v1, const vector<int>& v2){
           return v1[2] < v2[2];
        });

        for(int start = 0, i = 1; i <= meetings.size(); i ++)
            if(i == meetings.size() || meetings[i][2] != meetings[start][2]){

                set<int> visited;
                map<int, set<int>> g;
                for(int j = start; j < i; j ++){
                    int u = meetings[j][0], v = meetings[j][1];
                    g[u].insert(v), g[v].insert(u);
                    if(uf.is_connected(0, u)) visited.insert(u);
                    if(uf.is_connected(0, v)) visited.insert(v);
                }

                queue<int> q;
                for(int u: visited) q.push(u);
                while(!q.empty()){
                    int u = q.front(); q.pop();
                    for(int v: g[u])
                        if(!visited.count(v)){
                            q.push(v);
                            visited.insert(v);
                        }
                }

                for(int u: visited) uf.union_elements(0, u);

                start = i;
            }

        vector<int> res;
        for(int i = 0; i < n; i ++)
            if(uf.is_connected(0, i)) res.push_back(i);
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<vector<int>> meetings1 = {{1, 2, 5}, {2, 3, 8}, {1, 5, 10}};
    print_vec(Solution().findAllPeople(6, meetings1, 1) );
    // 0 1 2 3 5

    vector<vector<int>> meetings2 = {{3, 1, 3}, {1, 2, 2}, {0, 3, 3}};
    print_vec(Solution().findAllPeople(4, meetings2, 3) );
    // 0 1 3

    vector<vector<int>> meetings3 = {{3, 4, 2}, {1, 2, 1}, {2, 3, 1}};
    print_vec(Solution().findAllPeople(5, meetings3, 1) );
    // 0 1 2 3 4

    vector<vector<int>> meetings4 = {{0, 2, 1}, {1, 3, 1}, {4, 5, 1}};
    print_vec(Solution().findAllPeople(6, meetings4, 1) );
    // 0 1 2 3

    return 0;
}
