/// Source : https://leetcode.com/problems/the-skyline-problem/description/
/// Author : liuyubobobo
/// Time   : 2017-10-28

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <cassert>

using namespace std;

class SegmentTree{

private:
    int n;
    vector<int> tree;
    vector<int> lazy;

public:
    SegmentTree(int n){

        this->n = n;

        int size = 4*n;
        for(int i = 0 ; i < size ; i ++){
            tree.push_back(0);
            lazy.push_back(0);
        }
    }

    void add(int l, int r, int h){
        update(0, 0, n-1, l, r, h);
    }

    int query(int index){
        return query(0, 0, n-1, index);
    }

private:
    void update(int treeID, int treeL, int treeR, int l, int r, int h){

        if(lazy[treeID] != 0){
            tree[treeID] = max(tree[treeID], lazy[treeID]);
            if(treeL != treeR){
                lazy[2 * treeID + 1] = max(lazy[treeID], lazy[2 * treeID + 1]);
                lazy[2 * treeID + 2] = max(lazy[treeID], lazy[2 * treeID + 2]);
            }
            lazy[treeID] = 0;
        }

        if(treeL == l && treeR == r){
            tree[treeID] = max(tree[treeID], h);
            if(treeL != treeR){
                lazy[2 * treeID + 1] = max(h, lazy[2 * treeID + 1]);
                lazy[2 * treeID + 2] = max(h, lazy[2 * treeID + 2]);
            }
            return;
        }

        int mid = (treeL + treeR) / 2;

        if(r <= mid)
            update(2 * treeID + 1, treeL, mid, l, r, h);
        else if(l >= mid + 1)
            update(2 * treeID + 2, mid + 1, treeR, l, r, h);
        else{
            update(2 * treeID + 1, treeL, mid, l, mid, h);
            update(2 * treeID + 2, mid + 1, treeR, mid + 1, r, h);
        }

        return;
    }

    int query(int treeID, int treeL, int treeR, int index){

        if(lazy[treeID] != 0){
            tree[treeID] = max(tree[treeID], lazy[treeID]);
            if(treeL != treeR){
                lazy[2 * treeID + 1] = max(lazy[treeID], lazy[2 * treeID + 1]);
                lazy[2 * treeID + 2] = max(lazy[treeID], lazy[2 * treeID + 2]);
            }
            lazy[treeID] = 0;
        }

        if(treeL == treeR){
            assert(treeL == index);
            return tree[treeID];
        }

        int mid = (treeL + treeR) / 2;

        if(index <= mid)
            return query(2 * treeID + 1, treeL, mid, index);

        return query(2 * treeID + 2, mid + 1, treeR, index);
    }
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {

        // Coordinate compression
        set<int> unique_points;
        for(vector<int> info: buildings){
            unique_points.insert(info[0]);
            unique_points.insert(info[1]-1);
            unique_points.insert(info[1]);
        }

        unordered_map<int, int> indexes;
        vector<int> pos;
        for(int p: unique_points){
            indexes[p] = pos.size();
            pos.push_back(p);
        }

        // segment tree
        SegmentTree stree(pos.size());
        for(vector<int> info: buildings)
            stree.add(indexes[info[0]], indexes[info[1]-1], info[2]);

        // get results
        vector<pair<int, int>> res;
        unique_points.clear();
        for(vector<int> info: buildings){
            unique_points.insert(info[0]);
            unique_points.insert(info[1]);
        }

        int last = 0;
        for(int p: unique_points){
            int h = stree.query(indexes[p]);
            if(h != last)
                res.push_back(make_pair(p, h));
            last = h;
        }

        return res;
    }
};

int main() {

    int n = 5;
    int buildings[5][3] = {
            {2, 9, 10},
            {3, 7, 15},
            {5, 12, 12},
            {15, 20, 10},
            {19, 24, 8}
    };
    vector<vector<int>> vec;
    for(int i = 0 ; i < n ; i ++)
        vec.push_back(vector<int>(buildings[i], buildings[i] + 3));

    vector<pair<int, int>> res = Solution().getSkyline(vec);
    for(pair<int, int> p: res)
        cout << p.first << " " << p.second << endl;

    return 0;
}