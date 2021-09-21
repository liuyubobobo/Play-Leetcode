/// Source : https://leetcode.com/problems/longest-subsequence-repeated-k-times/
/// Author : liuyubobobo
/// Time   : 2021-09-20

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {

        vector<int> f(26, 0);
        for(char c: s) f[c - 'a'] ++;

        string p = "";
        for(int i = 0; i < 26;){
            if(f[i] >= k) p += ('a' + i), f[i] -= k;
            else i ++;
        }
        if(p == "") return "";

        int maxlen = s.size() / k;
        string res = "";
        for(int l = maxlen; l >= 1; l --){
            sort(p.begin(), p.end());
            do{
                string t = p.substr(0, l);
                if(ok(s, t, k)){
                    if(res == "") res = t;
                    else res = max(res, t);
                }
            }while(next_permutation(p.begin(), p.end()));

            if(res != "") break;
        }
        return res;
    }

private:
    bool ok(const string& s, const string& p, int k){

        int j = 0;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == p[j]) j ++;
            if(j == p.size()) j = 0, k --;
        }
        return k <= 0;
    }
};


int main() {

    cout << Solution().longestSubsequenceRepeatedK("ab", 2) << endl;
    // ""

    cout << Solution().longestSubsequenceRepeatedK("memzememeflmemrfemekxzmemememwememefmqemxememzedmoememnrcmekmeemejhsuamelcmermemdjemezwmkemememxgyemenwhmemxaebmememeimeemienmemtnetmftemememeooimememememezmecmemqemeewnimyhlemiuemkhwnstbiiemedmemizememeemememrlemememebmemyenafmemehmemvweumhiemewmemetmemtetcmedwbpmeylwomegjmzfeetmuemzemuwemeymsncemmememememeewyumqenmemetyqmebmemmemeofjmehmteamegmbihememnemneegppm", 108) << endl;
    // me

    return 0;
}
