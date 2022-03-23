/// Source : https://leetcode.com/problems/partition-labels/
/// Author : liuyubobobo
/// Time   : 2022-03-20

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> partitionLabels(string s) {

        vector<int> f(26, 0);
        for(char c: s) f[c - 'a'] ++;

        vector<int> res;
        vector<int> curf(26, 0);
        int l = 0;
        for(int i = 0; i < s.size(); i ++){
            curf[s[i] - 'a'] ++;
            if(ok(curf, f)){
                res.push_back(i - l + 1);
                l = i + 1;
                fill(curf.begin(), curf.end(), 0);
            }
        }
        return res;
    }

private:
    bool ok(const vector<int>& curf, const vector<int>& f){

        for(int i = 0; i < 26; i ++)
            if(curf[i] && curf[i] != f[i]) return false;
        return true;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    print_vec(Solution().partitionLabels("ababcbacadefegdehijhklij"));
    // 9 7 8

    return 0;
}
