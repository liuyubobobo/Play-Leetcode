/// Source : https://leetcode.com/problems/prime-palindrome/solution/
/// Author : liuyubobobo
/// Time   : 2018-07-07

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Recursively generate all prime palindrome number
/// Time Complexity: O(maxN)
/// Space Complexity: O(?)*
///
/// * It is not even known whether there are infinitely many prime palindromes,
///   Basically, it's an open mathematical problem
///   But we can roughly say the time and space complexity is O(n) :)
class Solution {
public:
    int primePalindrome(int N) {

        vector<int> nums = {2, 3, 5, 7};
        for(int d = 2; d <= 8 ; d ++)
            generatePalindromePrimes(d, nums);
        nums.push_back(100030001);
        sort(nums.begin(), nums.end());

        return *lower_bound(nums.begin(), nums.end(), N);
    }

private:
    void generatePalindromePrimes(int d, vector<int>& nums){

        string s(d, '-');
        generatePalindromePrimes(0, s, nums);
    }

    void generatePalindromePrimes(int index, string& s, vector<int>& nums){

        if(s[index] != '-'){
            int num = atoi(s.c_str());
            if(isPrime(num))
                nums.push_back(num);
            return;
        }

        int start = 0;
        if(index == 0)
            start = 1;
        for(int d = start ; d <= 9 ; d ++){
            s[index] = s[s.size() - 1 - index] = ('0' + d);
            generatePalindromePrimes(index + 1, s, nums);
            s[index] = s[s.size() - 1 - index] = '-';
        }
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