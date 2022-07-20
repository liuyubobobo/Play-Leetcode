/// Source : https://leetcode.cn/contest/zj-future2022/problems/NBCXIp/
/// Author : liuyubobobo
/// Time   : 2022-07-19

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// Backtrack
/// Time Complexity: O(12!)
/// Space Complexity: O(12)
class Solution {
public:
    int minTransfers(vector<vector<int>>& distributions) {

        int max_id = -1;
        for(const vector<int>& v: distributions)
            max_id = max(max_id, max(v[0], v[1]));

        vector<int> cnt(max_id + 1, 0);
        for(const vector<int>& v: distributions){
            int from_id = v[0], to_id = v[1], e = v[2];
            cnt[from_id] -= e;
            cnt[to_id] += e;
        }

        vector<int> pos, neg;
        for(int i = 0; i < cnt.size(); i ++) {
            if (cnt[i] > 0) pos.push_back(cnt[i]);
            else if (cnt[i] < 0) neg.push_back(-cnt[i]);
        }

        sort(pos.begin(), pos.end(), greater<int>());
        sort(neg.begin(), neg.end(), greater<int>());

        return dfs(pos, 0, neg);
    }

private:
    int dfs(vector<int>& pos, int index, vector<int>& neg){

        if(index == pos.size()) return 0;

        int res = INT_MAX;
        for(int& e: neg){
            if(e){
                int t = min(pos[index], e);
                pos[index] -= t;
                e -= t;
                res = min(res, 1 + dfs(pos, index + (pos[index] == 0), neg));
                pos[index] += t;
                e += t;
            }
        }
        return res;
    }
};


int main() {

    vector<vector<int>> distrubution1 = {
            {0,1,5},{2,3,1},{2,0,1},{4,0,2}
    };
    cout << Solution().minTransfers(distrubution1) << '\n';
    // 4

    vector<vector<int>> distrubution2 = {
            {1,5,8},{8,9,8},{2,3,9},{4,3,1}
    };
    cout << Solution().minTransfers(distrubution2) << '\n';
    // 4

    vector<vector<int>> distrubution3 = {
            {0,2,4},{1,2,4},{3,4,5}
    };
    cout << Solution().minTransfers(distrubution3) << '\n';
    // 3

    return 0;
}
