/// Source : https://leetcode.com/problems/number-of-orders-in-the-backlog/
/// Author : liuyubobobo
/// Time   : 2021-03-20

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Using Prioriity Queue to simulate
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {

        priority_queue<pair<int, long long>> buyq;
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> sellq;

        for(const vector<int>& order: orders){
            int price = order[0], type = order[2];
            long long amount = (long long)order[1];

            if(type){ // sell
                while(amount != 0ll && !buyq.empty() && buyq.top().first >= price){
                    long long t = min(amount, buyq.top().second);

                    pair<int, long long> top_e = buyq.top();
                    buyq.pop();
                    top_e.second -= t;
                    amount -= t;

                    if(top_e.second != 0ll) buyq.push(top_e);
                }

                if(amount != 0ll) sellq.push({price, amount});
            }
            else{ // buy

                while(amount != 0ll && !sellq.empty() && sellq.top().first <= price){
                    long long t = min(amount, sellq.top().second);

                    pair<int, long long> top_e = sellq.top();
                    sellq.pop();
                    top_e.second -= t;
                    amount -= t;

                    if(top_e.second != 0ll) sellq.push(top_e);
                }

                if(amount != 0ll) buyq.push({price, amount});
            }
        }

        long long MOD = 1e9 + 7;

        long long sum = 0ll;
        while(!sellq.empty()) sum += sellq.top().second, sellq.pop();
        while(!buyq.empty()) sum += buyq.top().second, buyq.pop();
        return sum % MOD;
    }
};


int main() {

    vector<vector<int>> orders1 = {
            {10,5,0},{15,2,1},{25,1,1},{30,4,0}
    };
    cout << Solution().getNumberOfBacklogOrders(orders1) << endl;
    // 6

    vector<vector<int>> orders2 = {
            {7,1000000000,1},{15,3,0},{5,999999995,0},{5,1,1}
    };
    cout << Solution().getNumberOfBacklogOrders(orders2) << endl;
    // 999999984

    return 0;
}
