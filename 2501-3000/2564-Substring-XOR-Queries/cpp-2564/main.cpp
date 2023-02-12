/// Source : https://leetcode.com/problems/substring-xor-queries/description/
/// Author : liuyubobobo
/// Time   : 2023-02-11

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {

        int n = s.size(), q = queries.size();
        vector<vector<int>> res(q, {-1, -1});
        map<int, list<int>> res2index;
        for(int i = 0; i < q; i ++){
            int first = queries[i][0], second = queries[i][1];
            int val = second ^ first;

            res2index[val].push_back(i);
        }

        for(int len = 1; len <= min(31, n); len ++){
            long long cur = 0;
            for(int i = 0; i < len - 1; i ++) cur = cur * 2 + (s[i] - '0');
            for(int i = len - 1; i < n; i ++){
                cur = cur * 2 + (s[i] - '0');
                auto iter = res2index.find(cur);
                if(iter != res2index.end()){
                    for(int index: iter->second) res[index] = {i - (len - 1), i};
                    res2index.erase(iter);
                }

                if(s[i - (len - 1)] == '1') cur -= (1ll << (len - 1));
            }
        }
        return res;
    }
};

int main() {

    string s1 = "101101";
    vector<vector<int>> queries1 = {{0, 5}, {1, 2}};
    Solution().substringXorQueries(s1, queries1);

    return 0;
}
