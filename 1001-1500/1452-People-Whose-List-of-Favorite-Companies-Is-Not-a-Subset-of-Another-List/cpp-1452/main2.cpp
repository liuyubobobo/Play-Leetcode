/// Source : https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/
/// Author : liuyubobobo
/// Time   : 2020-05-16

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Brute Force + Binary Search to check subset
/// Time Complexity: O(n^2 * m * logm * |s|)
/// Space Complexity: O(n * m)
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {

        int n = favoriteCompanies.size();
        for(int i = 0; i < n; i ++)
            sort(favoriteCompanies[i].begin(), favoriteCompanies[i].end());

        vector<int> res;
        for(int i = 0; i < n; i ++){
            bool is_sub = false;
            for(int j = 0; j < n; j ++)
                if(j != i && favoriteCompanies[i].size() < favoriteCompanies[j].size() &&
                   isSub(favoriteCompanies[i], favoriteCompanies[j])){
                    is_sub = true;
                    break;
                }

            if(!is_sub) res.push_back(i);
        }
        return res;
    }

private:
    // see if a is subset of b
    bool isSub(const vector<string>& a, const vector<string>& b){

        for(string e: a){
            vector<string>::const_iterator iter = lower_bound(b.begin(), b.end(), e);
            if(iter == b.end() || *iter != e) return false;
        }
        return true;
    }
};


int main() {

    return 0;
}
