/// Source : https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/
/// Author : liuyubobobo
/// Time   : 2020-05-16

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Brute Force + HashSet to check subset
/// Time Complexity: O(n^2 * m * |s|)
/// Space Complexity: O(n * m)
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {

        int n = favoriteCompanies.size();

        vector<unordered_set<string>> setv;
        for(const vector<string>& v: favoriteCompanies)
            setv.push_back(unordered_set<string>(v.begin(), v.end()));

        vector<int> res;
        for(int i = 0; i < n; i ++){
            bool is_sub = false;
            for(int j = 0; j < n; j ++)
                if(j != i && setv[i].size() < setv[j].size() && isSub(setv[i], setv[j])){
                    is_sub = true;
                    break;
                }

            if(!is_sub) res.push_back(i);
        }
        return res;
    }

private:
    // see if a is subset of b
    bool isSub(const unordered_set<string>& a, const unordered_set<string>& b){

        for(string e: a)
            if(!b.count(e)) return false;
        return true;
    }
};


int main() {

    return 0;
}
