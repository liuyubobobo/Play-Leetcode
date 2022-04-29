/// Source : https://leetcode.com/problems/design-video-sharing-platform/
/// Author : liuyubobobo
/// Time   : 2022-04-29

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;


/// Using Priority Queue to maintain available ids
/// Time Complexity: init: O(1)
///                  others: O(logn)
/// Space Complexity: O(n)
class VideoSharingPlatform {

private:
    int MAX_ID = 128;
    const int D = 128;
    priority_queue<int, vector<int>, greater<int>> available_ids;

    map<int, tuple<string, int, int, int>> videos; // video, watched, like, dislike

public:
    VideoSharingPlatform() {
        for(int i = 0; i < MAX_ID; i ++) available_ids.push(i);
    }

    int upload(const string& video) {

        if(available_ids.empty()){
            int start = MAX_ID;
            MAX_ID += D;
            for(int i = start; i < MAX_ID; i ++) available_ids.push(i);
        }

        int new_id = available_ids.top();
        available_ids.pop();

        videos[new_id] = {video, 0, 0, 0};
        return new_id;
    }

    void remove(int videoId) {
        if(videos.count(videoId)){
            videos.erase(videoId);
            available_ids.push(videoId);
        }
    }

    string watch(int videoId, int startMinute, int endMinute) {
        auto iter = videos.find(videoId);
        if(iter != videos.end()){
            get<1>(iter->second) ++;
            return get<0>(iter->second).substr(startMinute, endMinute - startMinute + 1);
        }
        return "-1";
    }

    void like(int videoId) {
        auto iter = videos.find(videoId);
        if(iter != videos.end()){
            get<2>(iter->second) ++;
        }
    }

    void dislike(int videoId) {
        auto iter = videos.find(videoId);
        if(iter != videos.end()){
            get<3>(iter->second) ++;
        }
    }

    vector<int> getLikesAndDislikes(int videoId) {
        auto iter = videos.find(videoId);
        if(iter != videos.end()){
            return {get<2>(iter->second), get<3>(iter->second)};
        }
        return {-1};
    }

    int getViews(int videoId) {
        auto iter = videos.find(videoId);
        if(iter != videos.end()) return get<1>(iter->second);
        return -1;
    }
};


int main() {

    return 0;
}
