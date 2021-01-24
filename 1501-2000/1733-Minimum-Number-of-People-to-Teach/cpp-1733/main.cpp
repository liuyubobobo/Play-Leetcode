/// Source : https://leetcode.com/problems/minimum-number-of-people-to-teach/
/// Author : liuyubobobo
/// Time   : 2021-01-23

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Brute Force
/// Time Complexity: O(n * m)
/// Space Complexity: O(n * m)
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {

        int m = languages.size();

        vector<unordered_set<int>> language_set(m);
        for(int i = 0; i < m; i ++)
            language_set[i] = unordered_set<int>(languages[i].begin(), languages[i].end());

        vector<vector<int>> need_teach;
        for(vector<int>& v: friendships){
            int a = v[0] - 1, b = v[1] - 1;
            bool ok = false;
            for(int l: language_set[a])
                if(language_set[b].count(l)){
                    ok = true;
                    break;
                }

            if(!ok) need_teach.push_back({a, b});
        }

        if(need_teach.empty()) return 0;

        int res = INT_MAX;
        for(int i = 1; i <= n; i ++){

            unordered_set<int> teach;
            for(const vector<int>& f: need_teach){
                if(!language_set[f[0]].count(i)) teach.insert(f[0]);
                if(!language_set[f[1]].count(i)) teach.insert(f[1]);
            }
            res = min(res, (int)teach.size());
        }
        return res;
    }
};


int main() {

    vector<vector<int>> language1 = {{1}, {2}, {1, 2}};
    vector<vector<int>> friendships1 = {{1, 2}, {1, 3}, {2, 3}};
    cout << Solution().minimumTeachings(2, language1, friendships1) << endl;
    // 1

    return 0;
}
