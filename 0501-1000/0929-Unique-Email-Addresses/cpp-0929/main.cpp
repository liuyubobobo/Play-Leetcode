/// Source : https://leetcode.com/problems/unique-email-addresses/
/// Author : liuyubobobo
/// Time   : 2018-10-27

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;


/// Using HashSet
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {

        unordered_set<string> set;
        for(const string& email: emails)
            set.insert(process(email));
        return set.size();
    }

private:
    string process(const string& email){

        int at = email.find('@');
        string s = email.substr(0, at);

        int plus = s.find('+');
        if(plus != string::npos)
            s = s.substr(0, plus);

        string res = "";
        for(char c: s)
            if(c != '.')
                res += c;
        return res + email.substr(at);
    }
};


int main() {

    return 0;
}