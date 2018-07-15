/// Source : https://leetcode.com/problems/prime-palindrome/solution/
/// Author : liuyubobobo
/// Time   : 2018-07-07

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;


/// Generate all prime palindrome number according to "root"
/// We can based on number X = abc,
/// generate odd-digit palindrome P1 = abcba, and even-digit palindrome P1 = abccba,
/// X is the root of P1 and P2
///
/// Since in this process, we generate palindrome number from small to large,
/// We can terminate the process whenever we found the first result >= N :)
///
/// We can ignore all even-digit palindrome number in this problem,
/// Since, interestingly, all even-digit palindrome number is not prime, except 11 :)
/// The proof is in the official solution of this problem:
/// https://leetcode.com/problems/prime-palindrome/solution/
///
/// Time Complexity: O(maxN)
/// Space Complexity: O(N)*
///
/// * It is not even known whether there are infinitely many prime palindromes,
///   Basically, it's an open mathematical problem
///   But we can roughly say the time and space complexity is O(n) :)
class Solution {
public:
    int primePalindrome(int N) {

        vector<int> nums = {2, 3, 5, 7, 11};
        if(N <= 11)
            return *lower_bound(nums.begin(), nums.end(), N);

        int res = 0;
        for(int d = 3; d <= 9 ; d += 2) {
            res = generatePalindromePrimes(d, N);
            if(res)
                return res;
        }
        assert(false);
        return -1;
    }

private:
    int generatePalindromePrimes(int d, int N){

        assert(d % 2 == 1);
        int start = (int)pow(10, d / 2);
        int limit = (int)pow(10, d / 2 + 1);
        for(int root = start; root < limit; root ++){
            int num = generatePalindrome(root);
            if(num >= N && isPrime(num))
                return num;
        }
        return 0;
    }

    int generatePalindrome(int root){

        int num = root;
        vector<int> nums;
        while(num){
            nums.push_back(num % 10);
            num /= 10;
        }

        int res = root;
        for(int i = 1 ; i < nums.size() ; i ++)
            res = res * 10 + nums[i];
        return res;
    }

    bool isPrime(int x){

        if(x % 2 == 0)
            return false;

        for(int i = 3 ; i * i <= x ; i ++)
            if(x % i == 0)
                return false;
        return true;
    }
};

int main() {

    cout << Solution().primePalindrome(6) << endl;
    cout << Solution().primePalindrome(8) << endl;
    cout << Solution().primePalindrome(13) << endl;

    return 0;
}