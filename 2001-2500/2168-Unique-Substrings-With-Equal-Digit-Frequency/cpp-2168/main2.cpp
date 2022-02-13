/// Source : https://leetcode.com/problems/unique-substrings-with-equal-digit-frequency/
/// Author : liuyubobobo
/// Time   : 2022-02-13

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Presum + HashSet + Rolling Hash
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class StringHashU{

private:
    int n;
    unsigned long long B;
    vector<unsigned long long> h, p;

public:
    StringHashU(const string& s, unsigned long long B = 131) :
            n(s.size()), h(n + 1, 0), p(n + 1, 1), B(B){

        for(int i = 0; i < n; i ++){
            h[i + 1] = h[i] * B + s[i];
            p[i + 1] = p[i] * B;
        }
    }

    unsigned long long get_hash(int l, int r){
        assert(l >= 0 && l < n);
        assert(r >= 0 && r < n);
        return h[r + 1] - h[l] * p[r - l + 1];
    }
};

class Solution {
public:
    int equalDigitFrequency(string s) {

        int n = s.size();

        vector<vector<int>> presum(n + 1, vector<int>(10, 0));
        for(int i = 0; i < s.size(); i ++){
            presum[i + 1][s[i] - '0'] ++;
            for(int j = 0; j < 10; j ++)
                presum[i + 1][j] += presum[i][j];
        }

        StringHashU stringHash(s);

        unordered_set<unsigned long long> set;
        for(int r = 0; r < n; r ++){
            for(int l = 0; l <= r; l ++){
                int f = 0;
                bool ok = true;
                for(int k = 0; k < 10 && ok; k ++)
                    if(presum[r + 1][k] - presum[l][k]){
                        if(f && presum[r + 1][k] - presum[l][k] != f)
                            ok = false;
                        else f = presum[r + 1][k] - presum[l][k];
                    }
                if(ok) set.insert(stringHash.get_hash(l, r));
            }
        }
        return set.size();
    }
};


int main() {

    return 0;
}
