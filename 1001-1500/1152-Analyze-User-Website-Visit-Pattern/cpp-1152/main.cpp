/// Source : https://leetcode.com/problems/analyse-user-website-visit-pattern/
/// Author : liuyubobobo
/// Time   : 2019-08-10

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;


/// State Memory
/// for every 3-sequence, record its user
///
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^3)
class Solution {

public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {

        set<string> website_set(website.begin(), website.end());

        unordered_map<string, set<pair<int, string>>> history;
        for(int i = 0; i < username.size(); i ++)
            history[username[i]].insert(make_pair(timestamp[i], website[i]));

        unordered_map<string, unordered_map<string, unordered_map<string, unordered_set<string>>>> count;
        for(const pair<string, set<pair<int, string>>>& p: history){
            vector<string> v;
            for(const pair<int, string>& e: p.second)
                v.push_back(e.second);
            for(int i = 0; i < v.size(); i ++)
                for(int j = i + 1; j < v.size(); j ++)
                    for(int k = j + 1; k < v.size(); k ++)
                        count[v[i]][v[j]][v[k]].insert(p.first);
        }

        int best = -1;
        vector<string> res;
        for(const string& a: website_set)
            for(const string& b: website_set)
                for(const string& c: website_set)
                    if((int)count[a][b][c].size() > best){
                        best = count[a][b][c].size();
                        res = {a, b, c};
                    }

        return res;
    }
};


void print_vec(const vector<string>& vec){

    for(const string& e: vec) cout << e << " "; cout << endl;
}

int main() {

    vector<string> username1 = {"joe","joe","joe","james","james","james","james","mary","mary","mary"};
    vector<int> timestamp1 = {1,2,3,4,5,6,7,8,9,10};
    vector<string> website1 = {"home","about","career","home","cart","maps","home","home","about","career"};
    print_vec(Solution().mostVisitedPattern(username1, timestamp1, website1));
    // home about career

    vector<string> username2 = {"h","eiy","cq","h","cq","txldsscx","cq","txldsscx","h","cq","cq"};
    vector<int> timestamp2 = {527896567,334462937,517687281,134127993,859112386,159548699,51100299,444082139,926837079,317455832,411747930};
    vector<string> website2 = {"hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","yljmntrclw","hibympufi","yljmntrclw"};
    print_vec(Solution().mostVisitedPattern(username2, timestamp2, website2));
    // "hibympufi","hibympufi","yljmntrclw"

    return 0;
}