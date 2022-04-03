/// Source : https://leetcode.com/problems/find-players-with-zero-or-one-losses/
/// Author : liuyubobobo
/// Time   : 2022-04-02

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


/// Simulation, using map and set
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {

        set<int> all_players;

        map<int, int> losers;
        for(const vector<int>& match: matches){
            losers[match[1]] ++;

            all_players.insert(match[0]);
            all_players.insert(match[1]);
        }

        vector<vector<int>> res(2);
        for(int player: all_players)
            if(!losers.count(player)) res[0].push_back(player);

        for(const pair<int, int>& p: losers)
            if(p.second == 1) res[1].push_back(p.first);

        return res;
    }
};


int main() {

    return 0;
}
