/// Source : https://leetcode.com/problems/count-zero-request-servers/description/
/// Author : liuyubobobo
/// Time   : 2023-06-25

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


/// Sliding Window
/// Time Complexity: O(nlogn + qlogq)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<pair<int, int>> queries_pair;
        for(int i = 0; i < queries.size(); i ++) queries_pair.push_back({queries[i], i});
        sort(queries_pair.begin(), queries_pair.end());

        map<int, int> f;
        int l = 0, r = -1, index = 0;
        vector<int> res(queries.size(), n);
        while(l < logs.size() && index < queries_pair.size()){
            if(r + 1 < logs.size() && queries_pair[index].first - x <= logs[r + 1][1] && logs[r + 1][1] <= queries_pair[index].first){
                r ++, f[logs[r][0]] ++;
            }
            else{
                if(queries_pair[index].first - x <= logs[l][1] && (l == 0 || queries_pair[index].first - x > logs[l - 1][1])){
                    res[queries_pair[index].second] -= f.size();
                    index ++;
                    continue;
                }

                if(l <= r){
                    f[logs[l][0]] --;
                    if(f[logs[l][0]] == 0) f.erase(logs[l][0]);
                }

                l ++;
                r = max(r, l - 1);
            }
        }

        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<vector<int>> logs1 = {{2,30},{2,5},{3,9},{4,21}};
    vector<int> queries1 = {11, 28, 16, 18};
    print_vec(Solution().countServers(4, logs1, 9, queries1));
    // 2 3 3 3

    return 0;
}
