/// Source : https://leetcode.com/problems/count-unhappy-friends/
/// Author : liuyubobobo
/// Time   : 2020-09-12

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {

        vector<vector<int>> pref(n, vector<int>(n, -1));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < preferences[i].size(); j ++)
                pref[i][preferences[i][j]] = j;

        unordered_set<int> res;
        for(int i = 0; i < pairs.size(); i ++)
            for(int j = i + 1; j < pairs.size(); j ++){

                int x = pairs[i][0], y = pairs[i][1], u = pairs[j][0], v = pairs[j][1];
                if(ok(pref, x, y, u, v)) res.insert(x);
                if(ok(pref, x, y, v, u)) res.insert(x);
                if(ok(pref, y, x, u, v)) res.insert(y);
                if(ok(pref, y, x, v, u)) res.insert(y);
                if(ok(pref, u, v, x, y)) res.insert(u);
                if(ok(pref, u, v, y, x)) res.insert(u);
                if(ok(pref, v, u, x, y)) res.insert(v);
                if(ok(pref, v, u, y, x)) res.insert(v);
            }

        return res.size();
    }

private:
    bool ok(const vector<vector<int>>& pref, int x, int y, int u, int v){
        return pref[x][u] < pref[x][y] && pref[u][x] < pref[u][v];
    }
};


int main() {

    vector<vector<int>> preferences1 = {
            {1, 2, 3}, {3, 2, 0}, {3, 1, 0}, {1, 2, 0}
    };
    vector<vector<int>> pairs1 = {{0, 1}, {2, 3}};
    cout << Solution().unhappyFriends(4, preferences1, pairs1) << endl;
    // 2

    vector<vector<int>> preferences2 = {
            {1}, {0}
    };
    vector<vector<int>> pairs2 = {{1, 0}};
    cout << Solution().unhappyFriends(2, preferences2, pairs2) << endl;
    // 0

    vector<vector<int>> preferences3 = {
            {1, 3, 2}, {2, 3, 0}, {1, 3, 0}, {0, 2, 1}
    };
    vector<vector<int>> pairs3 = {{1, 3}, {0, 2}};
    cout << Solution().unhappyFriends(4, preferences3, pairs3) << endl;
    // 4

    return 0;
}