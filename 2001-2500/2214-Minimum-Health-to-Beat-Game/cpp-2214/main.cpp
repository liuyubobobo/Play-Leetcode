/// Source : https://leetcode.com/problems/minimum-health-to-beat-game/
/// Author : liuyubobobo
/// Time   : 2022-03-24

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {

        int max_damage = *max_element(damage.begin(), damage.end());
        long long sum = accumulate(damage.begin(), damage.end(), 0ll);

        if(max_damage >= armor) sum -= armor;
        else sum -= max_damage;

        return sum + 1;
    }
};


int main() {

    vector<int> damage1 = {2, 7, 4, 3};
    cout << Solution().minimumHealth(damage1, 4) << '\n';
    // 13

    return 0;
}
