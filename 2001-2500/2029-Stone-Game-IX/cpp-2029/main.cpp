/// Source : https://leetcode.com/problems/stone-game-ix/
/// Author : liuyubobobo
/// Time   : 2021-10-03

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Game Theory - Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {

        vector<int> f(3, 0);
        for(int e: stones) f[e % 3] ++;

        // 112121212...
        int start_one_len = 0;
        if(f[1]){
            start_one_len += 1;
            int one_left = f[1] - 1, two_left = f[2];
            start_one_len += min(one_left, two_left) * 2;
            if(one_left > two_left) start_one_len += 1;

            start_one_len += f[0];
            if(start_one_len < stones.size() && start_one_len % 2) return true;
        }

        // 22121212121...
        int start_two_len = 0;
        if(f[2]){
            start_two_len += 1;
            int one_left = f[1], two_left = f[2] - 1;
            start_two_len += min(one_left, two_left) * 2;
            if(two_left > one_left) start_two_len += 1;

            start_two_len += f[0];
            if(start_two_len < stones.size() && start_two_len % 2) return true;
        }

        return false;
    }
};


int main() {

    return 0;
}
