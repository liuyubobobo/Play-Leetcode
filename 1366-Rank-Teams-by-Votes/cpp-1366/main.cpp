/// Source : https://leetcode.com/problems/rank-teams-by-votes/
/// Author : liuyubobobo
/// Time   : 2020-02-29

#include <iostream>
#include <map>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(26log26 * n)
/// Space Complexity: O(26^2)
class Solution {
public:
    string rankTeams(vector<string>& votes) {

        vector<vector<int>> freq(26, vector<int>(26, 0));
        for(const string& s: votes)
            for(int i = 0; i < s.size(); i ++)
                freq[s[i] - 'A'][i] ++;

        vector<char> vec;
        for(char c: votes[0]) vec.push_back(c);
        sort(vec.begin(), vec.end(), [freq](char a, char b){
            for(int i = 0; i < 26; i ++)
                if(freq[a - 'A'][i] != freq[b - 'A'][i])
                    return freq[a - 'A'][i] > freq[b - 'A'][i];
            return a < b;
        });

        string res = "";
        for(char c: vec) res += c;
        return res;
    }
};


int main() {

    vector<string> votes = {"ABC","ACB","ABC","ACB","ACB"};
    cout << Solution().rankTeams(votes) << endl;

    return 0;
}
