/// Source : https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/description/
/// Author : liuyubobobo
/// Time   : 2022-12-18

#include <iostream>
#include <vector>

using namespace std;


/// Sieve + Simulation
/// Time Complexity: O(MAXN * logMAXN)
/// Space Compelxity: O(MAXN)
class Solution {

private:
    const int MAXN = 1e5;

public:
    int smallestValue(int n) {

        vector<int> sieve_table = sieve(MAXN);
        vector<bool> visited(MAXN + 1, false);
        while(!visited[n]){
            visited[n] = true;
            n = calc(n, sieve_table);
        }

        for(int i = 0; i <= MAXN; i ++)
            if(visited[i]) return i;
        return -1;
    }

private:
    int calc(int x, const vector<int>& sieve_table){

        int res = 0;
        while(x != 1){
            int p = sieve_table[x];
            res += p;
            x /= p;
        }
        return res;
    }

    vector<int> sieve(int n){

        vector<int> table(n + 1, 0);
        vector<int> primes;
        table[0] = table[1] = 1;
        for(int i = 2; i <= n; i ++){
            if(table[i] == 0) {
                primes.push_back(i);
                table[i] = i;
            }
            for(int j = 0; j < primes.size() && primes[j] <= table[i] && i * primes[j] <= n; j ++)
                table[i * primes[j]] = primes[j];
        }
        return table;
    }
};


int main() {

    cout << Solution().smallestValue(64) << '\n';

    return 0;
}
