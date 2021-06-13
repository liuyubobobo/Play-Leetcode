/// Source : https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/
/// Author : liuyubobobo
/// Time   : 2021-06-12

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Monte Carlo
/// Time Complexity: O(T*nlogn)
/// Space Complexity: O(n)
class Solution {

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {

        srand(time(NULL));

        int N = 3000, minv = INT_MAX, maxv = INT_MIN;
        while(N --){
            int res = play(n, firstPlayer - 1, secondPlayer - 1);
            minv = min(minv, res);
            maxv = max(maxv, res);
        }

        return {minv, maxv};
    }

private:
    int play(int n, int player1, int player2){

        vector<int> players(n);
        for(int i = 0; i < n; i ++)
            players[i] = i;

        for(int t = 1;;t ++){
            vector<int> temp;
            for(int i = 0; i <= (players.size() - 1) / 2; i ++){
                int x = players[i], y = players[players.size() - 1 - i];
                if(x == player1 && y == player2) return t;

                if(x == player1 || x == player2)
                    temp.push_back(x);
                else if(y == player1 || y == player2)
                    temp.push_back(y);
                else
                    temp.push_back(rand() % 2 ? x : y);
            }
            sort(temp.begin(), temp.end());
            players = temp;
        }
        return -1;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    print_vec(Solution().earliestAndLatest(11, 2, 4));
    // {3, 4}

    print_vec(Solution().earliestAndLatest(5, 1, 5));
    // {1, 1}

    return 0;
}
