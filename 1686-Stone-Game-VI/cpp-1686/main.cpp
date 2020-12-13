/// Source : https://leetcode.com/problems/stone-game-vi/
/// Author : liuyubobobo
/// Time   : 2020-12-13

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {

        int n = aliceValues.size();

        vector<vector<int>> data(n);
        for(int i = 0; i < n; i ++)
            data[i] = {aliceValues[i] + bobValues[i], aliceValues[i], bobValues[i]};

        sort(data.begin(), data.end(), greater<vector<int>>());

        int ascore = 0, bscore = 0;
        for(int i = 0; i < n; i ++)
            if(i % 2 == 0) ascore += data[i][1];
            else bscore += data[i][2];

        return ascore == bscore ? 0 : ascore > bscore ? 1 : -1;
    }
};


int main() {

    vector<int> alice1 = {1, 3}, bob1 = {2, 1};
    cout << Solution().stoneGameVI(alice1, bob1) << endl;
    // 1

    vector<int> alice2 = {1, 2}, bob2 = {3, 1};
    cout << Solution().stoneGameVI(alice2, bob2) << endl;
    // 0

    return 0;
}
