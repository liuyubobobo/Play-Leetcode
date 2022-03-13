/// Source : https://leetcode-cn.com/contest/cnunionpay-2022spring/problems/I4mOGz/
/// Author : liuyubobobo
/// Time   : 2022-03-13

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cassert>

using namespace std;


/// Using PQ
/// Again, in Leetcode, unordered_map is faster than map
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int maxInvestment(vector<int>& product, int limit) {

        unordered_map<int, int> f;
        for(int e: product) f[e] ++;

        priority_queue<pair<long long, int>> pq;
        for(const pair<int, int>& p: f)
            pq.push({p.first, p.second});
        pq.push({0, 0});

        long long res = 0ll;
        while(limit && !pq.empty()){

            long long price = pq.top().first;
            int cnt = pq.top().second;
            pq.pop();

            if(price == 0) break;
            assert(!pq.empty());

            long long next_price = pq.top().first;
            assert(next_price < price);

            if(limit >= (price - next_price) * cnt){
                limit -= (price - next_price) * cnt;
                res += (next_price + 1ll + price) * (price - next_price) / 2 % MOD * cnt % MOD;
                res %= MOD;

                pair<long long, int> next = pq.top();
                pq.pop();
                next.second += cnt;
                pq.push(next);

                continue;
            }
            else{
                if(limit / cnt){
                    int next_price = price - limit / cnt + 1;
                    res += (next_price + price) * (price - next_price + 1) / 2 % MOD * cnt % MOD;
                    res %= MOD;

                    price = next_price - 1;
                }
                if(limit % cnt){
                    res += price * (limit % cnt) % MOD;
                    res %= MOD;
                }
                break;
            }
        }
        return res % MOD;
    }
};


int main() {

    vector<int> product1 = {4, 5, 3};
    cout << Solution().maxInvestment(product1, 8) << '\n';
    // 26

    vector<int> product2 = {2, 1, 3};
    cout << Solution().maxInvestment(product2, 20) << '\n';
    // 10

    return 0;
}
