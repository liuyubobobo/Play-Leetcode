/// Source : https://leetcode.com/problems/count-vowel-strings-in-ranges/description/
/// Author : liuyubobobo
/// Time   : 2023-02-05

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n + q)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        int n = words.size();
        vector<int> v(n, 0);
        for(int i = 0; i < n; i ++)
            v[i] = is_vowel(words[i][0]) && is_vowel(words[i].back());

        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++)
            presum[i + 1] = presum[i] + v[i];

        vector<int> res(queries.size());
        for(int i = 0; i < queries.size(); i ++){
            int l = queries[i][0], r = queries[i][1];
            res[i] = presum[r + 1] - presum[l];
        }
        return res;
    }

private:
    bool is_vowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};


int main() {

    return 0;
}
