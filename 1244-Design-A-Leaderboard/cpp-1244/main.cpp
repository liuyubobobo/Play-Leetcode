/// Source : https://leetcode.com/problems/design-a-leaderboard/
/// Author : liuyubobobo
/// Time   : 2020-05-07

#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;


/// Using Map
/// Time Complexity: addScore: O(logn)
///                  top: O(K)
///                  reset: O(logn)
/// Space Complexity: O(n)
class Leaderboard {

private:
    unordered_map<int, int> scores;    // id -> score
    map<int, int> rscores;   // score -> freq

public:
    Leaderboard() {}

    void addScore(int playerId, int score) {

        if(scores.count(playerId)) score += scores[playerId];
        reset(playerId);

        scores[playerId] = score;
        rscores[-score] ++;
    }

    int top(int K) {
        int res = 0, k = 0;
        for(const pair<int, int>& p: rscores){
            for(int i = 0; i < p.second; i ++){
                res += -p.first;
                k ++;
                if(k == K) return res;
            }
        }
        assert(false);
        return -1;
    }

    void reset(int playerId) {

        if(scores.count(playerId)){
            int score = scores[playerId];
            rscores[-score] --;
            if(rscores[-score] == 0) rscores.erase(-score);

            scores.erase(playerId);
        }
    }
};


int main() {

    return 0;
}