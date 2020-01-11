/// Source : https://leetcode.com/problems/get-watched-videos-by-your-friends/
/// Author : liuyubobobo
/// Time   : 2020-01-04

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;


/// BFS
/// Time Complexity: O(V + E + vlogv)
/// Space Complexity: O(V + v)
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {

        vector<set<int>> g(friends.size());
        for(int i = 0; i < friends.size(); i ++)
            for(int k: friends[i])
                g[i].insert(k), g[k].insert(i);

        set<int> level_friends = bfs(g, id, level);
        map<string, int> freq;
        for(int f: level_friends)
            for(string video: watchedVideos[f])
                freq[video] ++;

        vector<pair<int, string>> tres;
        for(const pair<string, int>& p: freq)
            tres.push_back(make_pair(p.second, p.first));
        sort(tres.begin(), tres.end());

        vector<string> res;
        for(const pair<int, string>& p: tres)
            res.push_back(p.second);
        return res;
    }

private:
    set<int> bfs(const vector<set<int>>& g, int s, int k){

        queue<int> q;
        vector<bool> visited(g.size(), false);
        vector<int> step(g.size(), 0);
        set<int> res;

        q.push(s);
        visited[s] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int next: g[cur])
                if(!visited[next]){
                    step[next] = step[cur] + 1;
                    visited[next] = true;
                    if(step[next] == k) res.insert(next);
                    q.push(next);
                }
        }
        return res;
    }
};


void print_vec(const vector<string>& v){
    for(const string& e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<string>> watchedVideos = {{"A","B"},{"C"},{"B","C"},{"D"}};
    vector<vector<int>> friends = {{1,2},{0,3},{0,3},{1,2}};
    vector<string> res = Solution().watchedVideosByFriends(watchedVideos, friends, 0, 2);
    print_vec(res);
    // D

    return 0;
}
