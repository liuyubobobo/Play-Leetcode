#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int equalCountSubstrings(string s, int count) {

        int n = s.size();
        vector<vector<int>> f(26, vector<int>(n + 1, 0));
        for(int i = 0; i < n; i ++)
            for(char c = 'a'; c <= 'z'; c ++)
                f[c - 'a'][i + 1] = f[c - 'a'][i] + (s[i] == c);

        int res = 0;
        for(int i = 0; i < n; i ++)
            if(f[s[i] - 'a'][i + 1] >= count){
                int start = *lower_bound(f[s[i] - 'a'].begin(), f[s[i] - 'a'].begin() + (i + 1), f[s[i] - 'a'][i + 1] - count);
                int end = *upper_bound(f[s[i] - 'a'].begin(), f[s[i] - 'a'].begin() + (i + 1), f[s[i] - 'a'][i + 1] - count) - 1;
                vector<pair<int, int>> intervals = {{start, end}};
                for(char c = 'a'; c <= 'z'; c ++){
                    if(c == s[i]) continue;
                    if(f[c - 'a'][i + 1] == 0) continue;

                    start = *lower_bound(f[c - 'a'].begin(), f[s[i] - 'a'].begin() + (i + 1), f[s[i] - 'a'][i + 1] - count);
                    vector<pair<int, int>> intervals2 = {{0, *upper_bound(f[c - 'a'].begin(), f[c - 'a'].begin() + (i + 1), 1) - 1}};
                    if(f[c - 'a'][i + 1] >= count){
                        intervals.push_back({ *lower_bound(f[s[i] - 'a'].begin(), f[s[i] - 'a'].begin() + (i + 1), f[s[i] - 'a'][i + 1] - count), i})
                    }
                }
            }

    }
};


int main() {

    return 0;
}
