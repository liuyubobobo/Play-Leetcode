/// Source : https://leetcode.com/problems/web-crawler/description/
/// Author : liuyubobobo
/// Time   : 2023-03-24

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;


// This is the HtmlParser's API interface.
// You should not implement it, or speculate about its implementation
class HtmlParser {
  public:
    vector<string> getUrls(string url);
};


/// BFS
/// Time Complexity: O(V + E)
/// Space Complexity: O(V)
class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {

        string hostname = startUrl.substr(7);
        int pos = hostname.find("/");
        if(pos != string::npos)
            hostname = hostname.substr(0, pos);

        set<string> visited;
        queue<string> q;
        q.push(startUrl);
        visited.insert(startUrl);
        while(!q.empty()){
            string url = q.front();
            q.pop();
            vector<string> urls = htmlParser.getUrls(url);
            for(auto u : urls){
                if(visited.find(u) == visited.end() && u.find(hostname) != string::npos){
                    visited.insert(u);
                    q.push(u);
                }
            }
        }
        return vector<string>(visited.begin(), visited.end());
    }
};

int main() {

    return 0;
}
