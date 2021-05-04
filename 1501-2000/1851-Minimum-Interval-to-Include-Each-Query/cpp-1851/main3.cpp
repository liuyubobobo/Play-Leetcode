/// Source : https://leetcode.com/problems/minimum-interval-to-include-each-query/
/// Author : liuyubobobo
/// Time   : 2021-05-03

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// UF to deal with Segment Problem
/// See here: https://leetcode.com/problems/minimum-interval-to-include-each-query/discuss/1186840/Python-union-find
/// Time Complexity: O(nlogn + qlogq + nlogq)
/// Space Complexity: O(q)
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

    bool isConnected(int p, int q){
        return find(p) == find(q);
    }

    void unionElements(int p, int q){

        int pRoot = find(p), qRoot = find(q);

        if(pRoot == qRoot) return;

        parent[pRoot] = qRoot;
    }
};

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b){

            if(a[1] - a[0] + 1 != b[1] - b[0] + 1)
                return a[1] - a[0] + 1 < b[1] - b[0] + 1;
            return a[0] < b[0];
        });

        vector<pair<int, int>> qv(queries.size());
        for(int i = 0; i < queries.size(); i ++)
            qv[i] = {queries[i], i};
        sort(qv.begin(), qv.end());

        UF uf(qv.size());
        vector<int> res(queries.size(), -1);
        for(const vector<int>& interval: intervals){
            int l = interval[0], r = interval[1];

            vector<pair<int, int>>::iterator iter1 = lower_bound(qv.begin(), qv.end(), make_pair(l, INT_MIN));
            if(iter1 == qv.end()) continue;

            vector<pair<int, int>>::iterator iter2 = upper_bound(qv.begin(), qv.end(), make_pair(r, INT_MAX));
            if(iter2 == qv.begin()) continue;
            iter2 --;

            int ql = iter1 - qv.begin(), qr = iter2 - qv.begin();
            if(ql > qr) continue;

            while(true){
                int v = uf.find(ql);
                if(qv[v].first > r) break;

                if(res[qv[v].second] == -1)
                    res[qv[v].second] = r - l + 1;

                if(v + 1 < qv.size())
                    uf.unionElements(v, v + 1);
                else
                    break;
            }
        }

        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> intervals1 = {{1, 4}, {2, 4}, {3, 6}, {4, 4}};
    vector<int> queries1 = {2, 3, 4, 5};
    print_vec(Solution().minInterval(intervals1, queries1));
    // 3 3 1 4

    vector<vector<int>> intervals2 = {{2, 3}, {2, 5}, {1, 8}, {20, 25}};
    vector<int> queries2 = {2, 19, 5, 22};
    print_vec(Solution().minInterval(intervals2, queries2));
    // 2,-1,4,6

    vector<vector<int>> intervals3 = {{9, 9}, {9, 10}};
    vector<int> queries3 = {9};
    print_vec(Solution().minInterval(intervals3, queries3));
    // 1

    vector<vector<int>> intervals4 = {{5, 10}, {7, 7}};
    vector<int> queries4 = {6, 6};
    print_vec(Solution().minInterval(intervals4, queries4));
    // 6 6

    return 0;
}
