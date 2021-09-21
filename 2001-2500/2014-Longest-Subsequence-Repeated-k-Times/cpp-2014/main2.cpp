/// Source : https://leetcode.com/problems/longest-subsequence-repeated-k-times/
/// Author : liuyubobobo
/// Time   : 2021-09-20

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {

        int maxlen = s.size() / k;

        queue<string> q;
        q.push("");
        string res = "";
        while(!q.empty()){
            string cur = q.front(); q.pop();
            if(cur.size() == maxlen) continue;

            for(char c = 'a'; c <= 'z'; c ++){
                string p = cur + c;
                if(ok(s, p, k)){
                    if(p.size() > res.size()) res = p;
                    else if(p.size() == res.size()) res = max(res, p);
                    q.push(p);
                }
            }
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
