/// Source : https://leetcode.com/problems/bag-of-tokens/
/// Author : liuyubobobo
/// Time   : 2018-11-25

#include <iostream>
#include <vector>

using namespace std;


/// Greedy Simulation
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {

public:
    int bagOfTokensScore(vector<int>& tokens, int P) {

        if(tokens.size() == 0)
            return 0;

        sort(tokens.begin(), tokens.end());
        int res = 0, l = 0, r = tokens.size() - 1;
        while(true){
            if(P >= tokens[l]){
                P -= tokens[l++];
                res ++;
            }
            else {
                if (l < r && res) {
                    P += tokens[r--];
                    res--;
                }
                else if (l == r || !res)
                    break;
            }

            if(l > r)
                break;
        }
        return res;
    }
};


int main() {

    vector<int> tokens1 = {100};
    cout << Solution().bagOfTokensScore(tokens1, 50) << endl;
    // 0

    vector<int> tokens2 = {100, 200};
    cout << Solution().bagOfTokensScore(tokens2, 150) << endl;
    // 1

    vector<int> tokens3 = {100, 200, 300, 400};
    cout << Solution().bagOfTokensScore(tokens3, 200) << endl;
    // 2

    vector<int> tokens4 = {71, 55, 82};
    cout << Solution().bagOfTokensScore(tokens4, 54) << endl;
    // 0

    return 0;
}