#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


/// Binary Search + Rolling Hash + Dealing with collision
/// Time Complexity: O(|s| * log|s|)
/// Space Complexity: O(|s|^2)
class Solution {
public:
    int longestRepeatingSubstring(string s) {

        int l = 0, r = s.size() - 1;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(ok(s, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }

private:
    bool ok(const string& s, int len){

        unordered_map<int, vector<string>> hashtable;
        int b = 26, MOD = 82595483, al = 1;
        for(int i = 1; i < len; i ++) al = (al * b) % MOD;

        int hash = 0;
        for(int i = 0; i + 1 < len; i ++) hash = (hash * b + (s[i] - 'a')) % MOD;

        for(int i = len - 1; i < s.size(); i ++){
            string t = s.substr(i - (len - 1), len);
            hash = (hash * b + (s[i] - 'a')) % MOD;

            if(hashtable.count(hash)){
                for(const string& e : hashtable[hash])
                    if(e == t) return true;
            }
            hashtable[hash].push_back(t);

            hash -= (s[i - (len - 1)] - 'a') * al;
            while(hash < 0) hash += MOD;
        }
        return false;
    }
};


int main() {

    cout << Solution().longestRepeatingSubstring("abbaba") << endl;
    // 2

    return 0;
}
