/// Source : https://leetcode.com/problems/closest-room/
/// Author : liuyubobobo
/// Time   : 2021-05-01

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Offline Algorithm
/// Time Complexity: O(qlogq + nlogn + qlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {

        for(int i = 0; i < queries.size(); i ++)
            queries[i].push_back(i);

        sort(rooms.begin(), rooms.end(),
             [](const vector<int>& a, const vector<int>& b){
            return a[1] > b[1];
        });

        sort(queries.begin(), queries.end(),
             [](const vector<int>& q1, const vector<int>& q2){
            return q1[1] > q2[1];
        });

        vector<int> res(queries.size(), -1);
        set<int> ids;
        for(int ri = 0, qi = 0; qi < queries.size(); qi ++){
            while(ri < rooms.size() && rooms[ri][1] >= queries[qi][1])
                ids.insert(rooms[ri ++][0]);

            int pref = queries[qi][0];
            set<int>::iterator iter = ids.lower_bound(pref);

            int minv = INT_MAX, curres = -1;
            if(iter != ids.end())
                if(abs(*iter - pref) <= minv)
                    minv = abs(*iter - pref), curres = *iter;

            if(iter != ids.begin()){
                iter --;
                if(abs(*iter - pref) <= minv)
                    curres = *iter;
            }

            res[queries[qi][2]] = curres;
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> rooms2 = {{1, 4}, {2, 3}, {3, 5}, {4, 1}, {5, 2}};
    vector<vector<int>> queries2 = {{2, 3}, {2, 4}, {2, 5}};
    print_vec(Solution().closestRoom(rooms2, queries2));
    // 2 1 3

    return 0;
}
