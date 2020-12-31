/// Source : https://leetcode.com/problems/sell-diminishing-valued-colored-balls/
/// Author : liuyubobobo
/// Time   : 2020-11-07

#include <iostream>
#include <vector>

using namespace std;


/// Sortiing + Greedy
/// Time Complexity: O(nlogn + n)
/// Space Complexity: O(1)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int maxProfit(vector<int>& inventory, int orders) {

        sort(inventory.begin(), inventory.end(), greater<int>());
        inventory.push_back(0);

        int w = 0;
        long long res = 0;
        while(orders > 0){
            int maxv = inventory[w];
            while(inventory[w] == maxv) w ++;

            int h = maxv - inventory[w];
            if((long long)w * h <= (long long)orders) {
                res += (long long)(maxv + inventory[w] + 1) * h / 2 * w;
                res %= MOD;
                orders -= w * h;
            }
            else{
                int hh = orders / w, m = orders % w;
                res += (long long)(maxv + maxv - hh + 1) * hh / 2 * w;
                res %= MOD;

                res += (long long)m * (maxv - hh);
                res %= MOD;

                orders = 0;
            }
        }
        return res;
    }
};


int main() {

    vector<int> inventory1 = {2,5};
    cout << Solution().maxProfit(inventory1, 4) << endl;
    // 14

    vector<int> inventory2 = {3,5};
    cout << Solution().maxProfit(inventory2, 6) << endl;
    // 19

    vector<int> inventory3 = {2,8,4,10,6};
    cout << Solution().maxProfit(inventory3, 20) << endl;
    // 110

    vector<int> inventory4 = {1000000000};
    cout << Solution().maxProfit(inventory4, 1000000000) << endl;
    // 21

    return 0;
}
