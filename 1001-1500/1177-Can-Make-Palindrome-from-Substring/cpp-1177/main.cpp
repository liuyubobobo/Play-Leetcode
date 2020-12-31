/// Source : https://leetcode.com/problems/can-make-palindrome-from-substring/
/// Author : liuyubobobo
/// Time   : 2019-08-31

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> presum(s.size() + 1, vector<int>(26, 0));
        for(int i = 0; i < s.size(); i ++){
            presum[i + 1] = presum[i];
            presum[i + 1][s[i] - 'a'] ++;
        }

        vector<bool> res;
        for(const vector<int>& q: queries)
            res.push_back(query(presum, q[0], q[1], q[2]));
        return res;
    }

private:
    bool query(const vector<vector<int>>& presum, int left, int right, int k){

        vector<int> freq(26, 0);
        for(int i = 0; i < 26; i ++)
            freq[i] = presum[right + 1][i] - presum[left][i];
//        for(int f: freq) cout << f << " "; cout << endl;

        int len = accumulate(freq.begin(), freq.end(), 0);
        int res = 0;
        for(int f: freq)
            res += f % 2;
        return (len % 2 ? res - 1 : res) / 2 <= k;
    }
};


void print_vec(const vector<bool>& vec){
    for(bool e: vec) cout << e << " "; cout << endl;
}

int main() {

    string s = "abcda";
    vector<vector<int>> queries = {{3,3,0},{1,2,0},{0,3,1},{0,3,2},{0,4,1}};
    print_vec(Solution().canMakePaliQueries(s, queries));
    // 1 0 0 1 1

    return 0;
}