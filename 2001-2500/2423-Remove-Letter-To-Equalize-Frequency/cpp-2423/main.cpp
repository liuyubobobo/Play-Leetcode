/// Source : https://leetcode.com/problems/remove-letter-to-equalize-frequency/
/// Author : liuyubobobo
/// Time   : 2022-10-02

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Brute Force
/// Time Compelxity: O(|word| + 26^2)
/// Space Complexity: O(26)
class Solution {
public:
    bool equalFrequency(string word) {

        vector<int> f(26, 0);
        for(char c: word) f[c - 'a'] ++;

        for(int i = 0; i < 26; i ++)
            if(f[i]){
                f[i] --;
                if(ok(f)) return true;
                f[i] ++;
            }
        return false;
    }

private:
    bool ok(const vector<int>& f){

        int t = -1;
        for(int i = 0; i < 26 && t == -1; i ++)
            if(f[i]) t = f[i];

        for(int i = 0; i < 26; i ++)
            if(f[i] && f[i] != t) return false;
        return true;
    }
};


int main() {

    return 0;
}
