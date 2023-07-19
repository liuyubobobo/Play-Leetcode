/// Source : https://leetcode.com/problems/prime-pairs-with-target-sum/description/
/// Author : liuyubobobo
/// Time   : 2023-07-10

#include <iostream>
#include <vector>

using namespace std;


/// Sieve
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {

        vector<int> sieve_table = sieve(n);

        vector<vector<int>> res;
        for(int x = 2; x + x <= n; x ++)
            if(sieve_table[x] == x && sieve_table[n - x] == n - x)
                res.push_back({x, n - x});
        return res;
    }

private:
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

    return 0;
}
