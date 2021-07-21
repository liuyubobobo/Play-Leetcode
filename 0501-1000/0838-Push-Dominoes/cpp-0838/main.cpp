/// Source : https://leetcode.com/problems/push-dominoes/
/// Author : liuyubobobo
/// Time   : 2021-07-21

#include <iostream>
#include <vector>

using namespace std;


/// String split
/// Time Complexity: O(n)
/// Space Complexity O(1)
class Solution {
public:
    string pushDominoes(string dominoes) {

        int n = dominoes.size();
        for(int start = -1, i = 0; i <= n; i ++){
            if(i == n || dominoes[i] != '.'){
                if(start != -1) {
                    process(dominoes, start, i - 1);
                    start = -1;
                }
            }
            else if(start == -1) start = i;
        }
        return dominoes;
    }

private:
    void process(string& s, int l, int r){

        if(l == 0){
            if(r + 1 < s.size() && s[r + 1] == 'L')
                for(int i = l; i <= r; i ++) s[i] = 'L';
            return;
        }

        if(r == (int)s.size() - 1){
            if(l - 1 >= 0 && s[l - 1] == 'R')
                for(int i = l; i <= r; i ++) s[i] = 'R';
            return;
        }

        if(s[l - 1] == s[r + 1])
            for(int i = l; i <= r; i ++) s[i] = s[l - 1];
        else if(s[l - 1] == 'R' && s[r + 1] == 'L'){
            int d = (r - l + 1) / 2;
            for(int i = l; i < l + d; i ++) s[i] = 'R';
            for(int i = r; i > r - d; i --) s[i] = 'L';
        }
        return;
    }
};


int main() {

    cout << Solution().pushDominoes("RR.L") << endl;
    // RR.L

    cout << Solution().pushDominoes(".L.R...LR..L..") << endl;
    // LL.RR.LLRRLL..

    cout << Solution().pushDominoes("R.R.L") << endl;
    // RRR.L

    return 0;
}
