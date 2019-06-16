/// Source : https://leetcode.com/problems/letter-tile-possibilities/
/// Author : liuyubobobo
/// Time   : 2019-06-15

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;


/// Counting on the fly, based on frequency of characters
/// Time Complexity: O(n!)
/// Space Complexity: O(n)
class Solution {

public:
    int numTilePossibilities(string tiles) {

        unordered_map<char, int> freq;
        for(char c: tiles)
            freq[c] ++;

        return dfs(freq);
    }

private:
    int dfs(unordered_map<char, int>& freq){

        int res = 0;
        for(char e = 'A'; e <= 'Z'; e ++)
            if(freq[e]){
                res ++;
                freq[e] --;
                res += dfs(freq);
                freq[e] ++;
            }
        return res;
    }
};


int main() {

    cout << Solution().numTilePossibilities("AAB") << endl;
    // 8

    cout << Solution().numTilePossibilities("AAABBC") << endl;
    // 188

    return 0;
}