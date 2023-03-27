/// Source : https://leetcode.com/problems/prime-subtraction-operation/
/// Author : liuyubobobo
/// Time   : 2023-03-26

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Greedy
/// Time Complexity: O(max_num * log(max_num) + n * log(max_num))
/// Space Complexity: O(max_num)
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {

        vector<int> primes = sieve(*max_element(nums.begin(), nums.end()));
        sort(primes.begin(), primes.end(), greater<int>());
        for(int prime: primes){
            if(prime < nums[0]){
                nums[0] -= prime;
                break;
            }
        }

        for(int i = 1; i < nums.size(); i ++){
            for(int prime: primes){
                if(prime < nums[i] && nums[i] - prime > nums[i - 1]){
                    nums[i] -= prime;
                    break;
                }
            }
            if(nums[i] <= nums[i - 1]) return false;
        }
        return true;
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
        return primes;
    }
};


int main() {

    vector<int> nums1 = {998, 2};
    cout << Solution().primeSubOperation(nums1) << '\n';
    // 1

    return 0;
}
