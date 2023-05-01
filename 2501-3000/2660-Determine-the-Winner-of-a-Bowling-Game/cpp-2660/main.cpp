/// Source : https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/description/
/// Author : liuyubobobo
/// Time   : 2023-04-30

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {

        int a = get_score(player1), b = get_score(player2);
        return (a == b ? 0 : (a > b ? 1 : 2));
    }

private:
    int get_score(const vector<int>& v){
        int res = 0;
        for(int i = 0; i < v.size(); i ++){
            bool double_score = false;
            if(i - 1 >= 0 && v[i - 1] == 10) double_score = true;
            if(i - 2 >= 0 && v[i - 2] == 10) double_score = true;
            res += (double_score ? 2 : 1) * v[i];
        }
        return res;
    }
};


int main() {

    return 0;
}
