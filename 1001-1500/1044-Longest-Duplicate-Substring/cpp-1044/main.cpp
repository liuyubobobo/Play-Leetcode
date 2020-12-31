/// Source : https://leetcode.com/problems/longest-duplicate-substring/
/// Author : liuyubobobo
/// Time   : 2019-05-19

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Binary Search + Rolling Hash
/// Time Complexity: O(|S| * log(|S|))
/// Space Complexity: O(|S|)
class Solution {

private:
    long long MOD = 9223372036854775807ll / 26ll;
    vector<long long> power;

public:
    string longestDupSubstring(string S) {

        power.push_back(1ll);
        for(int i = 1; i < S.size(); i ++)
            power.push_back(power.back() * 26 % MOD);

        int l = 0, h = S.size() - 1;
        string res = "";
        while(l < h){

            int mid = (l + h + 1) / 2;
            string tres = ok(S, mid);
            if(tres != "")
                l = mid, res = tres;
            else
                h = mid - 1;
        }
        return res;
    }

private:
    string ok(const string& s, int len){

        long long base = power[len - 1];
        long long hash = 0;
        for(int i = 0; i < len; i ++)
            hash = (hash * 26ll + (s[i] - 'a')) % MOD;

        unordered_set<long long> seen;
        seen.insert(hash);
        for(int i = len; i < s.size(); i ++){
            hash = (hash - (s[i - len] - 'a') * base % MOD + MOD) % MOD;
            hash = (hash * 26ll + (s[i] - 'a')) % MOD;
            if(seen.count(hash)) return s.substr(i - len + 1, len);
            seen.insert(hash);
        }
        return "";
    }
};


int main() {

    cout << Solution().longestDupSubstring("banana") << endl;
    // ana

    cout << Solution().longestDupSubstring("abcd") << endl;
    // ""

    return 0;
}