/// Source : https://leetcode.com/problems/strong-password-checker/
/// Author : liuyubobobo
/// Time   : 2022-04-30

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <algorithm>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(|s|)
/// Space Compelxity: O(|s|)
class Solution {
public:
    int strongPasswordChecker(string s) {

        int lower = 0, upper = 0, digit = 0, other = 0;
        for(char c: s){
            if(islower(c)) lower ++;
            else if(isupper(c)) upper ++;
            else if(isdigit(c)) digit ++;
            else other ++;
        }

        priority_queue<int> pq;
        for(int start = 0, i = 1; i <= s.size(); i ++)
            if(i == s.size() || s[start] != s[i]){
                if(i - start >= 3) pq.push(i - start);
                start = i;
            }

        int need_change = !lower + !upper + !digit;
        int len = s.size();
        if(len < 6){
            int res = 0;
            while(!pq.empty() && need_change){
                assert(pq.top() / 3 == 1);
                res ++;
                pq.pop(); need_change --;
                len ++;
            }

            res += pq.size(); len += pq.size();
            res += need_change; len += need_change;
            res += max(6 - len, 0);
            return res;
        }

        if(len <= 20){
            return for20(pq, need_change);
        }

        // len > 20
        vector<int> v;
        while(!pq.empty()) v.push_back(pq.top()), pq.pop();
        sort(v.begin(), v.end(), [](int a, int b){
            return a % 3 < b % 3;
        });

        int res = 0;
        for(int i = 0; i < v.size() && len > 20; i ++){
            if(v[i] % 3 == 0){
                len --; v[i] --; res ++;
            }
            else if(v[i] % 3 == 1){
                len --; v[i] --; res ++;
                if(len <= 20) break;
                len --; v[i] --; res ++;
            }
        }

        for(int i = 0; i < v.size() && len > 20; i ++){
            while(v[i] > 5 && len > 20){
                int t = min(len - 20, 3);
                v[i] -= t; len -= t; res += t;
            }
        }

        if(len == 20){
            for(int e: v) pq.push(e);
            return res + for20(pq, need_change);
        }

        for(int i = 0; i < v.size() && len > 20; i ++){
            int t = min(len - 20, v[i] - 2);
            v[i] -= t; len -= t; res += t;
        }

        if(len == 20){
            for(int e: v) pq.push(e);
            return res + for20(pq, need_change);
        }

        return max(len - 20, 0) + res + need_change;
    }

private:
    int for20(priority_queue<int>& pq, int need_change){
        int res = 0;
        while(!pq.empty() && need_change){
            int cur = pq.top(); pq.pop();
            res ++, need_change --;
            cur -= 3;
            if(cur >= 3) pq.push(cur);
        }

        if(need_change) res += need_change;
        else{
            while(!pq.empty()){
                int cur = pq.top(); pq.pop();
                res += cur / 3;
            }
        }
        return res;
    }
};


int main() {

    cout << Solution().strongPasswordChecker("a") << '\n';
    // 5

    cout << Solution().strongPasswordChecker("aA1") << '\n';
    // 3

    cout << Solution().strongPasswordChecker("1337C0d3") << '\n';
    // 0

    cout << Solution().strongPasswordChecker("ABABABABABABABABABAB1") << '\n';
    // 2

    return 0;
}
