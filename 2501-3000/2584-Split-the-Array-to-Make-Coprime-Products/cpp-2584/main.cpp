/// Source : https://leetcode.com/problems/split-the-array-to-make-coprime-products/description/
/// Author : liuyubobobo
/// Time   : 2023-03-13

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


/// Sieve + Map
/// Time Complexity: O(max_num * log(max_num) + n * log(max_num))
/// Space Complexity: O(max_num)
class Solution {
public:
    int findValidSplit(vector<int>& nums) {

        int n = nums.size();
        int max_num = *max_element(nums.begin(), nums.end());

        vector<int> sieve_table = sieve(max_num);

        vector<int> f1(max_num + 1, 0), f2(max_num + 1, 0);
        for(int i = 0; i < n; i ++){
            int x = nums[i];
            while(x > 1){
                int p = sieve_table[x];
                f2[p] ++;
                while(x % p == 0) x /= p;
            }
        }

        int both = 0;
        for(int i = 0; i < n; i ++){
            int x = nums[i];
            while(x > 1){
                int p = sieve_table[x];
                both -= (f1[p] && f2[p]);

                f2[p] --;
                f1[p] ++;
                while(x % p == 0) x /= p;

                both += (f1[p] && f2[p]);
            }
            if(both == 0 && i < n - 1) return i;
        }

        return -1;
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
