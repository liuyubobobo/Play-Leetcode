/// Source : https://leetcode.com/problems/tweet-counts-per-frequency/
/// Author : liuyubobobo
/// Time   : 2019-02-10

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using TreeMap
/// Time Complexity: init: O(1)
///                  recordTweet: O(1)
///                  getTweetCountsPerFrequency: O(logn + n)
/// Space Complexity: O(n)
class TweetCounts {

private:
    map<string, map<int, int>> record;

public:
    TweetCounts() {}

    void recordTweet(string tweetName, int time) {
        record[tweetName][time] ++;
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {

        int interval = freq == "minute" ? 60 : (freq == "hour" ? 60 * 60 : 24 * 60 * 60);
        map<int, int>::iterator iter = record[tweetName].lower_bound(startTime);

        vector<int> res((endTime - startTime + 1)/ interval + !!((endTime - startTime + 1) % interval));
        while(iter != record[tweetName].end() && iter->first <= endTime){
            res[(iter->first - startTime) / interval] += iter->second;
            iter ++;
        }
        return res;
    }
};


int main() {

    return 0;
}
