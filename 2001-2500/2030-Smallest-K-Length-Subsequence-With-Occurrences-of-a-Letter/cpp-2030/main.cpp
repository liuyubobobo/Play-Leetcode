/// Source : https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/
/// Author : liuyubobobo
/// Time   : 2021-10-02

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Greedy with ST Range Query (Segment Tree got TLE)
/// Time Complexity: O(nlogn)
/// Space Complexity: O(nlogn)
class SparseTable{

private:
    int n;
    vector<int> data;
    vector<vector<int>> table;
    vector<int> log2;

public:
    SparseTable(const vector<int>& data): n(data.size()), data(data), log2(n + 1, 1){

        int len = 2, k = 1;
        for(int i = 1; i <= n; i ++){
            if(i >= len) len <<= 1, k ++;
            log2[i] = k;
        }

        int K = log2[n];
        table = vector<vector<int>>(K, vector<int>(n));

        for(int i = 0; i < n; i ++)
            table[0][i] = i;

        for(int k = 1; k < K; k ++)
            for(int i = 0; i + (1 << (k - 1)) < n; i ++)
                table[k][i] = data[table[k - 1][i]] <= data[table[k - 1][i + (1 << (k - 1))]] ?
                              table[k - 1][i] : table[k - 1][i + (1 << (k - 1))];
    }

    int query(int l, int r){

        int k = log2[r - l + 1];
        return data[table[k - 1][l]] <= data[table[k - 1][r + 1 - (1 << (k - 1))]] ?
               table[k - 1][l] : table[k - 1][r + 1 - (1 << (k - 1))];
    }
};

class Solution {

private:
    SparseTable *st;
    string res = "";

public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {

        int n = s.size();

        vector<int> v(n, 0);
        for(int i = 0; i < n; i ++) v[i] = s[i] - 'a';

        st = new SparseTable(v);

        map<int, int> letter_pos;
        letter_pos[0] = n - 1;
        int cur = 0;
        for(int i = n - 1; i >= 0; i --)
            if(s[i] == letter){
                cur ++;
                letter_pos[cur] = i;
            }

        res = "";
        dfs(n, s, letter, 0, k, repetition, letter_pos);
        return res;
    }

private:
    void dfs(int n, const string& s, char letter,
             int l, int len, int rep, map<int, int>& letter_pos){

        if(len == 0) return;
        if(len == n - l){res += s.substr(l); return;}
        if(len == rep){res += string(rep, letter); return;}

//        assert(n - l >= len && l <= r);

        int p = letter_pos[rep];
//        assert(l <= p);
        int min_index = st->query(l, min(p, n - len));

        res += s[min_index];
        dfs(n, s, letter, min_index + 1, len - 1, max(rep - (s[min_index] == letter), 0), letter_pos);
    }
};


int main() {

    cout << Solution().smallestSubsequence("leet", 3, 'e', 1) << endl;
    // eet

    cout << Solution().smallestSubsequence("leetcode", 4, 'e', 2) << endl;
    // ecde

    cout << Solution().smallestSubsequence("bb", 2, 'b', 2) << endl;
    // bb

    cout << Solution().smallestSubsequence("aaabbbcccddd", 3, 'b', 2) << endl;
    // abb

    cout << Solution().smallestSubsequence("eeeexeeeyexyyeyxeyexyxeyexeexyexxxxyxeye", 7, 'e', 2) << endl;
    // abb

    return 0;
}
