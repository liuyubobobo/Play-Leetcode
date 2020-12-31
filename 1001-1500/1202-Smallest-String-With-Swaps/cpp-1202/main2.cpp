/// Source : https://leetcode.com/problems/smallest-string-with-swaps/
/// Author : liuyubobobo
/// Time   : 2019-09-21

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// UF CC + Greedy
/// Time Complexity: O(|s| + |pairs| + |s|log|s|)
/// Space Complexity: O(|s| + |pairs|)
class Solution {

private:
    class UF{

    private:
        vector<int> parent;

    public:
        UF(int n){
            for(int i = 0 ; i < n ; i ++)
                parent.push_back(i);
        }

        int find(int p){
            if( p != parent[p] )
                parent[p] = find( parent[p] );
            return parent[p];
        }

        bool isConnected(int p , int q){
            return find(p) == find(q);
        }

        void unionElements(int p, int q){

            int pRoot = find(p);
            int qRoot = find(q);

            if( pRoot == qRoot )
                return;

            parent[pRoot] = qRoot;
        }
    };

public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

        UF uf(s.size());
        for(const vector<int>& p: pairs)
            uf.unionElements(p[0], p[1]);

        unordered_map<int, vector<int>> poses;
        unordered_map<int, string> order;
        for(int i = 0; i < s.size(); i ++)
            poses[uf.find(i)].push_back(i), order[uf.find(i)] += s[i];

        for(const pair<int, string>& p: order)
            sort(order[p.first].begin(), order[p.first].end());

        for(const pair<int, string>& p: order){
            int index = 0;
            for(int pos: poses[p.first]) s[pos] = p.second[index ++];
        }
        return s;
    }
};


int main() {

    return 0;
}