/// Source : https://leetcode.com/problems/time-needed-to-buy-tickets/
/// Author : liuyubobobo
/// Time   : 2021-11-13

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(sum(tickets))
/// Space Complexity: O(1)
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        int res = 0;
        while(tickets[k] > 1){
            for(int& e: tickets)
                if(e) res ++, e --;
        }

        for(int i = 0; i <= k; i ++)
            if(tickets[i] > 0) res ++;
        return res;
    }
};


int main() {

    vector<int> t1 = {84,49,5,24,70,77,87,8};
    cout << Solution().timeRequiredToBuy(t1, 3) << endl;
    // 154

    return 0;
}
