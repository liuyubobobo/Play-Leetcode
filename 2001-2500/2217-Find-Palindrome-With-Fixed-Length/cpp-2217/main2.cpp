/// Source : https://leetcode.com/problems/find-palindrome-with-fixed-length/
/// Author : liuyubobobo
/// Time   : 2022-03-26

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(intLength) for each query
/// Space Complexity: O(intLength)
class Solution {

private:
    vector<long long> pow10;

public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {

        pow10 = {1ll};
        for(int i = 1; i <= 18; i ++)
            pow10.push_back(pow10[i - 1] * 10ll);

        long long base = pow10[(intLength + 1) / 2 - 1];
        long long top = base * 10ll;

        vector<long long> res(queries.size(), -1);
        for(int i = 0; i < queries.size(); i ++){
            int q = queries[i] - 1;
            if(base + q >= top) continue;

            res[i] = get_palindrome(base + q, intLength);
        }
        return res;
    }

private:
    long long get_palindrome(long long cur, int len){

        if(len == 1) return cur;

        string s = to_string(cur);
        if(len & 1) s.pop_back();
        reverse(s.begin(), s.end());
        long long second = atoll(s.c_str());
        return cur * pow10[s.size()] + second;
    }
};


void print_vec(const vector<long long>& v){
    for(long long e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<int> queries1 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,9,8};
    print_vec(Solution().kthPalindrome(queries1, 1));

    vector<int> queries2 = {97,902143467,332084633,15,139128663,347073005,167961442,32,15};
    print_vec(Solution().kthPalindrome(queries2, 11));

    return 0;
}
