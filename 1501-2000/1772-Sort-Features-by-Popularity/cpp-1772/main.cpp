/// Source : https://leetcode.com/problems/sort-features-by-popularity/
/// Author : liuyubobobo
/// Time   : 2021-02-26

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/// Using HashSet and Stable Sort
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {

        unordered_set<string> features_set(features.begin(), features.end());

        unordered_map<string, int> f;
        for(const string& s: responses){
            unordered_set<string> set = get_set(s);
            for(const string& e: set)
                if(features_set.count(e)) f[e] ++;
        }

        stable_sort(features.begin(), features.end(),
                    [&](const string& s1, const string& s2){
           return f[s1] > f[s2];
        });
        return features;
    }

private:
    unordered_set<string> get_set(const string& s){

        unordered_set<string> set;
        for(int start = 0, i = 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] == ' '){
                set.insert(s.substr(start, i - start));
                start = i + 1;
                i = start;
            }
        return set;
    }
};


int main() {

    return 0;
}
