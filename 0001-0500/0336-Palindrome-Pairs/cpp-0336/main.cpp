/// Source : https://leetcode.com/problems/palindrome-pairs/
/// Author : liuyubobobo
/// Time   : 2022-09-17

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;


/// String Hash
/// Time Complexity: O(n^2 * k) where k is the average length pf each words
/// Space Complexity: O(n * k)
class Solution {

private:
    const unsigned long long B = 13331;

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {

        int n = words.size();
        vector<vector<unsigned long long>> hash(n), rhash(n);

        int maxlen = 0;
        for(int i = 0; i < n; i ++){
            int len = words[i].size();
            maxlen = max(maxlen, len);

            hash[i].resize(len + 1, 0);
            for(int j = 0; j < len; j ++)
                hash[i][j + 1] = hash[i][j] * B + words[i][j];

            rhash[i].resize(len + 1, 0);
            for(int j = len - 1; j >= 0; j --)
                rhash[i][j] = rhash[i][j + 1] * B + words[i][j];
        }

        vector<unsigned long long> powB(maxlen + 1, 1);
        for(int i = 1; i <= maxlen; i ++) powB[i] = powB[i - 1] * B;

        vector<vector<int>> res;
        for(int i = 0; i < n; i ++){
            int len1 = words[i].size();
            for(int j = 0; j < n; j ++){

                if(j == i) continue;

                int len2 = words[j].size();

                if(len1 <= len2){
                    if(hash[i].back() != rhash[j][len2 - len1]) continue;
                    if(hash[j][len2 - len1] != rhash[j][0] - rhash[j][len2 - len1] * powB[len2 - len1]) continue;
                    res.push_back({i, j});
                }
                else{ // len1 > len2
                    if(hash[i][len2] != rhash[j][0]) continue;
                    if(hash[i].back() - hash[i][len2] * powB[len1 - len2] != rhash[i][len2]) continue;
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};


void print_res(const vector<vector<int>>& v){
    for(const vector<int>& e: v)
        cout << "(" << e[0] << "," << e[1] << ")";
    cout << '\n';
}

int main() {

    vector<string> words1 = {"a","ab"};
    print_res(Solution().palindromePairs(words1));

    vector<string> words2 = {"abcd","dcba","lls","s","sssll"};
    print_res(Solution().palindromePairs(words2));
    // [[0,1],[1,0],[3,2],[2,4]]

    return 0;
}
