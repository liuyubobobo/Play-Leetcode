/// Source : https://leetcode.com/problems/accounts-merge/description/
/// Author : liuyubobobo
/// Time   : 2017-11-25

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Using DFS
/// Time Complexity: O(len(emails)^2)
/// Space Complexity: O(len(emails))
class Solution {

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        map<string, string> emailToName;
        for(const vector<string>& account: accounts)
            for(int i = 1 ; i < account.size() ; i ++)
                emailToName[account[i]] = account[0];

        unordered_map<string, int> emailIndex;
        int index = 0;
        for(const pair<string, string>& p: emailToName)
            emailIndex.insert(make_pair(p.first, index ++));

        vector<string> intToEmail(emailIndex.size(), "");
        for(const pair<string, int>& p: emailIndex)
            intToEmail[p.second] = p.first;

        vector<unordered_set<int>> g(emailIndex.size(), unordered_set<int>());
        for(const vector<string>& account: accounts){
            for(int i = 1 ; i < account.size() ; i ++)
                for(int j = i + 1; j < account.size() ; j ++){
                    int index1 = emailIndex[account[i]];
                    int index2 = emailIndex[account[j]];
                    g[index1].insert(index2);
                    g[index2].insert(index1);
                }
        }

        vector<vector<string>> res;
        vector<bool> flag(emailIndex.size(), false);
        for(const pair<string, string>& p: emailToName){
            int index = emailIndex[p.first];
            if(!flag[index]){
                vector<string> emails;
                dfs(g, index, flag, emails, intToEmail);
                sort(emails.begin(), emails.end());
                string name = emailToName[emails[0]];

                vector<string> tres;
                tres.push_back(name);
                for(const string& email: emails)
                    tres.push_back(email);

                res.push_back(tres);
            }
        }

        return res;
    }

private:
    void dfs(const vector<unordered_set<int>>& g, int v, vector<bool>& flag,
             vector<string>& res, const vector<string>& intToEmail){

        res.push_back(intToEmail[v]);
        flag[v] = true;
        for(int next: g[v])
            if(!flag[next])
                dfs(g, next, flag, res, intToEmail);
    }
};


void printRes(const vector<vector<string>> res){
    for(const vector<string>& row: res){
        for(const string& e: row)
            cout << e << " ";
        cout << endl;
    }
}

int main() {

    vector<vector<string>> accounts = {
            {"John", "johnsmith@mail.com", "john00@mail.com"},
            {"John", "johnnybravo@mail.com"},
            {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
            {"Mary", "mary@mail.com"}
    };
    printRes(Solution().accountsMerge(accounts));

    return 0;
}