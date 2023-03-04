/// Source : https://leetcode.com/problems/maximum-profit-of-operating-a-centennial-wheel/
/// Author : liuyubobobo
/// Time   : 2020-09-26

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(sum(customers))
/// Space Complexity: O(1)
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {

        int k = 0, kres = -1, cp = 0, maxres = 0, curres = 0, waiting = 0;
        while(cp < customers.size() || waiting){
            if(cp < customers.size()) waiting += customers[cp];
            cp ++;

            int num = min(4, waiting);
            curres += boardingCost * num - runningCost;
            waiting -= num;

            k ++;
            if(curres > maxres){
                maxres = curres;
                kres = k;
            }
        }
        return kres;
    }
};


int main() {

    vector<int> customers1 = {8, 3};
    cout << Solution().minOperationsMaxProfit(customers1, 5, 6) << endl;
    // 3

    vector<int> customers2 = {10, 9, 6};
    cout << Solution().minOperationsMaxProfit(customers2, 6, 4) << endl;
    // 7

    vector<int> customers3 = {3,4,0,5,1};
    cout << Solution().minOperationsMaxProfit(customers3, 1, 92) << endl;
    // -1

    vector<int> customers4 = {10,10,6,4,7};
    cout << Solution().minOperationsMaxProfit(customers4, 3, 8) << endl;
    // 9

    return 0;
}
