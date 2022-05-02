/// Source : https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/
/// Author : liuyubobobo
/// Time   : 2022-04-30

#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;


/// Using Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {

        map<int, int> pos;
        int res = INT_MAX;
        for(int i = 0; i < cards.size(); i ++){
            if(pos.count(cards[i])){
                res = min(res, i - pos[cards[i]] + 1);
            }
            pos[cards[i]] = i;
        }
        return res == INT_MAX ? -1 : res;
    }
};


int main() {

    vector<int> cards1 = {3,4,2,3,4,7};
    cout << Solution().minimumCardPickup(cards1) << '\n';
    // 4

    vector<int> cards2 = {1,0,5,3};
    cout << Solution().minimumCardPickup(cards2) << '\n';
    // -1

    vector<int> cards3 = {95,11,8,65,5,86,30,27,30,73,15,91,30,7,37,26,55,76,60,43,36,85,47,96,6};
    cout << Solution().minimumCardPickup(cards3) << '\n';
    // 3

    vector<int> cards4 = {77,10,11,51,69,83,33,94,0,42,86,41,65,40,72,8,53,31,43,22,9,94,45,80,40,0,84,34,76,28,7,79,80,93,20,82,36,74,82,89,74,77,27,54,44,93,98,44,39,74,36,9,22,57,70,98,19,68,33,68,49,86,20,50,43};
    cout << Solution().minimumCardPickup(cards4) << '\n';
    // 3

    return 0;
}
