/// Source : https://leetcode-cn.com/problems/ju-qing-hong-fa-shi-jian/
/// Author : liuyubobobo
/// Time   : 2020-04-17

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace  std;


/// Using tree structure
/// Time Complexity: O(|inc| * |r|)
/// Space Complexity: O(|r|)
class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& inc, vector<vector<int>>& r) {

        map<int, map<pair<int, int>, set<int>>> tree;

        vector<int> res(r.size(), -1);
        for(int i = 0; i < r.size(); i ++)
            if(!r[i][0] && !r[i][1] && !r[i][2]) res[i] = 0;
            else tree[r[i][0]][make_pair(r[i][1],r[i][2])].insert(i);

        int a = 0, b = 0, c = 0;
        for(int i = 0; i < inc.size(); i ++){
            a += inc[i][0], b += inc[i][1], c += inc[i][2];

            vector<int> delv1;
            for(const pair<int, map<pair<int, int>, set<int>>>& p: tree){
                if(p.first > a) break;

                vector<pair<int, int>> delv2;
                for(const pair<pair<int, int>, set<int>>& p2: p.second){
                    if(p2.first.first <= b && p2.first.second <= c){
                        for(int index: p2.second) res[index] = i + 1;
                        delv2.push_back(p2.first);
                    }
                    else if(p2.first.first > b) break;
                }

                for(const pair<int, int>& delp: delv2)
                    tree[p.first].erase(delp);
                if(tree[p.first].size() == 0) delv1.push_back(p.first);
            }

            for(int delkey: delv1) tree.erase(delkey);
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> inc1 = {{2,8,4},{2,5,0},{10,9,8}};
    vector<vector<int>> r1 = {{2,11,3},{15,10,7},{9,17,12},{8,1,14}};
    print_vec(Solution().getTriggerTime(inc1, r1));
    // 2,-1,3,-1

    vector<vector<int>> inc2 = {{0,4,5}, {4,8,8},{8,6,1},{10,10,0}};
    vector<vector<int>> r2 = {{12,11,16},{20,2,6},{9,2,6},{10,18,3},{8,14,9}};
    print_vec(Solution().getTriggerTime(inc2, r2));
    // -1 4 3 3 3

    vector<vector<int>> inc3 = {{1,1,1}};
    vector<vector<int>> r3 = {{0,0,0}};
    print_vec(Solution().getTriggerTime(inc3, r3));
    // 0

    return 0;
}
