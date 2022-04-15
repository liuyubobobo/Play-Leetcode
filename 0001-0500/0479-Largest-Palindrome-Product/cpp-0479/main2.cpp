/// Source : https://leetcode.com/problems/largest-palindrome-product/
/// Author : liuyubobobo
/// Time   : 2022-04-15

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;


/// Iterate Two numbers int length n
/// Time Complexity: O(10^(2n)) in theory but in fact it is very fast
/// Space Complexity: O(10^(2n)) in theory but in fact it is very small
class Solution {
public:
    int largestPalindrome(int n) {

        priority_queue<pair<long long, pair<long long, long long>>> pq;
        set<pair<long long, long long>> visited;

        long long base = pow(10, n) - 1;

        pq.push({(base - 9 + 9) * (base - 9 + 1), {base - 9 + 9, base - 9 + 1}});
        visited.insert({base - 9 + 9, base - 9 + 1});

        pq.push({(base - 9 + 3) * (base - 9 + 3), {base - 9 + 3, base - 9 + 3}});
        visited.insert({base - 9 + 3, base - 9 + 3});

        pq.push({(base - 9 + 7) * (base - 9 + 7), {base - 9 + 7, base - 9 + 7}});
        visited.insert({base - 9 + 7, base - 9 + 7});

        while(!pq.empty()){
            long long num = pq.top().first;
            long long a = pq.top().second.first, b = pq.top().second.second;
            pq.pop();

            if(is_palindrome(num)) return num % 1337;

            pair<long long, long long> next1 = {max(a - 10, b), min(a - 10, b)};
            if(!visited.count(next1)){
                visited.insert(next1);
                pq.push({next1.first * next1.second, next1});
            }

            pair<long long, long long> next2 = {max(a, b - 10), min(a, b - 10)};
            if(!visited.count(next2)){
                visited.insert(next2);
                pq.push({next2.first * next2.second, next2});
            }
        }
        return 9;
    }

private:
    bool is_palindrome(long long num){

        string s = to_string(num);
        for(int i = 0, j = s.size() - 1; i < j; i ++, j --)
            if(s[i] != s[j]) return false;
        return true;
    }
};


int main() {

    cout << Solution().largestPalindrome(2) << '\n';
    // 987

    return 0;
}
