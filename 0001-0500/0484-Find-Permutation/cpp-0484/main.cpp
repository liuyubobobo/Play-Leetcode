/// Source : https://leetcode.com/problems/find-permutation/
/// Author : liuyubobobo
/// Time   : 2022-05-30

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> findPermutation(string s) {

        s += "I";
        int n = s.size();

        vector<int> res(n);
        for(int i = 1; i <= n; i ++) res[i - 1] = i;

        for(int start = 0, i = 0; i < n; i ++)
            if(i == n || s[i] != s[start]){
                if(s[start] == 'D')
                    reverse(res.begin() + start, res.begin() + i + 1);
                start = i;
                i = start;
            }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    print_vec(Solution().findPermutation("DI"));
    // 2 1 3

    return 0;
}
