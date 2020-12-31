/// Source : https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/
/// Author : liuyubobobo
/// Time   : 2020-05-16

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;


/// Brute Force + Using String to Int Set to check subset
/// Time Complexity: O(n * m * |s| + n^2 * m)
/// Space Complexity: O(n * m)
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {

        int n = favoriteCompanies.size();

        unordered_map<string, int> map;
        int index = 0;

        vector<unordered_set<int>> mapv;
        for(const vector<string>& v: favoriteCompanies){
            unordered_set<int> tv;
            for(const string& s: v){
                if(!map.count(s)) map[s] = index ++;
                tv.insert(map[s]);
            }
            mapv.push_back(tv);
        }

        vector<int> res;
        for(int i = 0; i < n; i ++){
            bool is_sub = false;
            for(int j = 0; j < n; j ++)
                if(j != i && mapv[i].size() <= mapv[j].size() && isSub(mapv[i], mapv[j])){
                    is_sub = true;
                    break;
                }

            if(!is_sub) res.push_back(i);
        }
        return res;
    }

private:
    // see if a is subset of b
    bool isSub(const unordered_set<int>& a, const unordered_set<int>& b){

        for(int e: a)
            if(!b.count(e)) return false;
        return true;
    }
};


int main() {

    return 0;
}
