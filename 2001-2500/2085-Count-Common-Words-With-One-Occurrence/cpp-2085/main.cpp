/// Source : https://leetcode.com/problems/count-common-words-with-one-occurrence/
/// Author : liuyubobobo
/// Time   : 2021-11-27

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map
/// Time Complexity: O(n + m)
/// Space Complexity: O(n + m)
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {

        map<string, int> map1, map2;
        for(const string& s: words1) map1[s] ++;
        for(const string& s: words2) map2[s] ++;

        int res = 0;
        for(const pair<string, int>& p: map1)
            if(p.second == 1 && map2.count(p.first) && map2[p.first] == 1) res ++;
        return res;
    }
};


int main() {

    return 0;
}
