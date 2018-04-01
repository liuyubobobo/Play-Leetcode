/// Source : https://leetcode.com/problems/subdomain-visit-count/description/
/// Author : liuyubobobo
/// Time   : 2018-03-31

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

/// Using Hash Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {

        unordered_map<string, int> cpdomains_map;
        for(const string& cpdomain: cpdomains){
            stringstream ss(cpdomain);
            int count;
            string domain;
            ss >> count >> domain;

            while(true){
                cpdomains_map[domain] += count;

                int dot_index = domain.find('.');
                if(dot_index == string::npos)
                    break;
                else
                    domain = domain.substr(dot_index + 1);
            }
        }

        vector<string> res;
        for(const pair<string, int>& p: cpdomains_map)
            res.push_back(to_string(p.second) + " " + p.first);
        return res;
    }
};

void print_vec(const vector<string>& vec){
    for(const string& s: vec)
        cout << s << endl;
    cout << endl;
}

int main() {

    vector<string> cpdomains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    print_vec(Solution().subdomainVisits(cpdomains));

    return 0;
}