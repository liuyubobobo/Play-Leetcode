/// Source : https://leetcode.com/problems/design-authentication-manager/
/// Author : liuyubobobo
/// Time   : 2021-03-21

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class AuthenticationManager {

private:
    int t;
    unordered_map<string, int> expire;

public:
    AuthenticationManager(int timeToLive) : t(timeToLive) {}

    void generate(string tokenId, int currentTime) {
        expire[tokenId] = currentTime + t;
    }

    void renew(string tokenId, int currentTime) {

        if(expire.count(tokenId) && currentTime >= expire[tokenId])
            expire.erase(tokenId);

        if(expire.count(tokenId))
            expire[tokenId] = currentTime + t;
    }

    int countUnexpiredTokens(int currentTime) {

        vector<string> del;
        for(const pair<string, int>& p: expire)
            if(currentTime >= p.second) del.push_back(p.first);

        for(const string& s: del)
            expire.erase(s);
        return expire.size();
    }
};


int main() {

    return 0;
}
