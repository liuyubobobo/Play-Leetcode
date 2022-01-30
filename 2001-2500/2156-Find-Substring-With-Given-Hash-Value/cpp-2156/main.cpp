/// Source : https://leetcode.com/problems/find-substring-with-given-hash-value/
/// Author : liuyubobobo
/// Time   : 2022-01-29

#include <iostream>
#include <vector>

using namespace std;


/// String Hash
/// Time Complexity: O(n)
/// Space Comlexity: O(n)
template<typename T>
class StringHash{

private:
    int n;
    T B, MOD;
    vector<T> h, p;

public:
    StringHash(const string& s, T B = 128, T MOD = 1e9+ 7) :
            n(s.size()), h(n + 1, 0), p(n + 1, 1), B(B), MOD(MOD){

        for(int i = 0; i < n; i ++){
            h[i + 1] = (h[i] * B + (s[i] - 'a' + 1)) % MOD;
            p[i + 1] = p[i] * B % MOD;
        }
    }

    T get_hash(int l, int r){
//        assert(l >= 0 && l < n);
//        assert(r >= 0 && r < n);

        T res = (h[r + 1] - h[l] * p[r - l + 1]) % MOD;
        return res < 0 ? res + MOD : res;
    }
};

class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {

        reverse(s.begin(), s.end());
        StringHash<long long> hash(s, power, modulo);

        string res = "";
        for(int i = 0; i + k - 1 < s.size(); i ++)
            if(hash.get_hash(i, i + k - 1) == hashValue)
                res = s.substr(i, k);
        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {

    cout << Solution().subStrHash("leetcode", 7, 20, 2, 0) << endl;
    // ee

    cout << Solution().subStrHash("fbxzaad", 31, 100, 3, 32) << endl;
    // fbx

    return 0;
}
