/// Source : https://leetcode.com/problems/closest-prime-numbers-in-range/description/
/// Author : liuyubobobo
/// Time   : 2022-12-31

#include <iostream>
#include <vector>

using namespace std;


/// Sieve
/// Time Compelxity: O(right * log(right) + (right - left)
/// Space Compelxity: O(right)
class Solution {

public:
    vector<int> closestPrimes(int left, int right) {

        vector<int> sieve_table = sieve(right);
        vector<int> v;
        for(int i = left; i <= right; i ++)
            if(sieve_table[i] == i && i != 1) v.push_back(i);

        if(v.size() <= 1) return {-1, -1};

        int min_interval = v[1] - v[0], l = v[0];
        for(int i = 2; i < (int)v.size(); i ++)
            if(v[i] - v[i - 1] < min_interval)
                min_interval = v[i] - v[i - 1], l = v[i - 1];
        return {l, l + min_interval};
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
