/// Source : https://leetcode.com/problems/letter-tile-possibilities/
/// Author : liuyubobobo
/// Time   : 2019-06-08

#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;


/// Backtracking and Permutation, Storing by Hash Set
/// Time Complexity: O(n! * n!)
/// Space Complexity: O(n)
class Solution {
public:
    int numTilePossibilities(string tiles) {

        sort(tiles.begin(), tiles.end());
        unordered_set<string> set;
        dfs(tiles, 0, "", set);
        return set.size();
    }

private:
    void dfs(const string& tiles, int index, const string& cur_res, unordered_set<string>& set){

        if(index == tiles.size()){
            if(cur_res != ""){
                string t = cur_res;
                sort(t.begin(), t.end());
                do{
                    set.insert(t);
                }while(next_permutation(t.begin(), t.end()));
            }
            return;
        }

        dfs(tiles, index + 1, cur_res + tiles[index], set);
        dfs(tiles, index + 1, cur_res, set);
    }
};


int main() {

    return 0;
}