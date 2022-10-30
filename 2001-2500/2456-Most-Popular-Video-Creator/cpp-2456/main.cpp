/// Source : https://leetcode.com/problems/most-popular-video-creator/
/// Author : liuyubobobo
/// Time   : 2022-10-29

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {

        int n = creators.size();

        map<string, pair<long long, string>> best_video;
        map<string, long long> total_views;
        long long most_view = 0ll;
        for(int i = 0; i < n; i ++){
            string creator = creators[i], id = ids[i];
            long long view = views[i];

            total_views[creator] += view;
            most_view = max(most_view, total_views[creator]);

            auto iter = best_video.find(creator);
            if(iter == best_video.end()){
                best_video[creator] = {view, id};
                continue;
            }

            if(view > iter->second.first || (view == iter->second.first && id < iter->second.second))
                best_video[creator] = {view, id};
        }

        vector<vector<string>> res;
        for(const pair<string, long long>& p: total_views)
            if(p.second == most_view){
                string creater = p.first;
                res.push_back({creater, best_video[creater].second});
            }
        return res;
    }
};


int main() {

    return 0;
}
