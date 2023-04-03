/// Source : https://leetcode.com/problems/minimum-reverse-operations/description/
/// Author : liuyubobobo
/// Time   : 2023-04-02

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> minReverseOperations(int n, int p, const vector<int>& banned, int k) {

        vector<bool> ok(n, true);
        for(int ban: banned) ok[ban] = false;

        set<int> available[2];
        for(int i = 0; i < n; ++i) if(ok[i]) available[i & 1].insert(i);
        vector<int> res(n, -1);

        queue<pair<int, int>> q;
        q.push({p, 0});
        res[p] = 0;
        available[p & 1].erase(p);
        while(!q.empty()){
            int pos = q.front().first, step = q.front().second;
            q.pop();

            int start = max(pos - k + 1, k - pos - 1);
            int end = min(pos + k - 1, 2 * n - k -pos - 1);
            set<int>& s = available[start & 1];
            for(auto iter = s.lower_bound(start); iter != s.end() && *iter <= end; iter = s.erase(iter)){
                res[*iter] = step + 1;
                q.push({*iter, step + 1});
            }
        }

        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' ';
    cout << '\n';
}

int main() {

    vector<int> banned1 = {};
    print_vec(Solution().minReverseOperations(4, 2, banned1, 4));
    // -1 1 0 1

    vector<int> banned2 = {};
    print_vec(Solution().minReverseOperations(5, 0, banned2, 4));
    // 0 3 2 1 4

    vector<int> banned3 = {};
    print_vec(Solution().minReverseOperations(3, 2, banned3, 1));
    // -1 -1 0

    return 0;
}
