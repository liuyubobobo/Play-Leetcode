/// Source : https://leetcode.com/problems/maximum-matching-of-players-with-trainers/
/// Author : liuyubobobo
/// Time   : 2022-09-17

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

        sort(players.begin(), players.end(), greater<int>());
        sort(trainers.begin(), trainers.end(), greater<int>());

        int res = 0, i = 0, j = 0;
        for(i = 0; i < players.size() && j < trainers.size(); i ++)
            if(players[i] <= trainers[j]) res ++, j ++;
        return res;
    }
};


int main() {

    return 0;
}
