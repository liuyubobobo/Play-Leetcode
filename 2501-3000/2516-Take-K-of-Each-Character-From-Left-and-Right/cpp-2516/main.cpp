/// Source : https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/
/// Author : liuyubobobo
/// Time   : 2022-12-26

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

public:
    int takeCharacters(string s, int k) {

        int n = s.size();

        vector<int> prea(n + 1, 0), preb(n + 1, 0), prec(n + 1, 0);
        for(int i = 0; i < n; i ++){
            prea[i + 1] = prea[i] + (s[i] == 'a');
            preb[i + 1] = preb[i] + (s[i] == 'b');
            prec[i + 1] = prec[i] + (s[i] == 'c');
        }

        if(prea.back() < k || preb.back() < k || prec.back() < k) return -1;

        int res = max3(get(prea, k), get(preb, k), get(prec, k));

        int a = 0, b = 0, c = 0;
        for(int i = n - 1; i >= 0; i --){
            a += s[i] == 'a';
            b += s[i] == 'b';
            c += s[i] == 'c';

            int t = max3(get(prea, max(k - a, 0)), get(preb, max(k - b, 0)), get(prec, max(k - c, 0)));
            res = min(res, t + n - i);
        }
        return res;
    }

private:
    int max3(int a, int b, int c){
        return max(a, max(b, c));
    }

    int get(const vector<int>& v, int k){
        auto iter = lower_bound(v.begin(), v.end(), k);
        assert(iter != v.end());
        return iter - v.begin();
    }
};


int main() {

    string s = "aabaaaacaabc";
    cout << Solution().takeCharacters(s, 2) << '\n';
    // 8

    return 0;
}
