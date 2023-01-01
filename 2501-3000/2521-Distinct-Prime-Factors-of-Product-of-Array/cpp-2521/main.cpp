/// Source : https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/description/
/// Author : liuyubobobo
/// Time   : 2022-12-31

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Sieve
/// Time Complexity: O(MAX_NUM*log(MAX_NUM) + nlog(MAX_NUM))
/// Space Compelxity: O(MAX_NUM)
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {

        vector<int> sieve_table = sieve(1000);
        set<int> res;
        for(int num: nums){

            while(num != 1){
                res.insert(sieve_table[num]);
                num /= sieve_table[num];
            }
        }
        return res.size();
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
