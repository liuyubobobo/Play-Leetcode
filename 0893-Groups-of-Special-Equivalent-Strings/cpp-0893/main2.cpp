/// Source : https://leetcode.com/problems/groups-of-special-equivalent-strings/solution/
/// Author : liuyubobobo
/// Time   : 2018-08-26

#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;


/// Using HashCode
/// Only one vector is used in getHashCode function
///
/// Time Complexity: O(n * len(s)), where len(s) is the average length of string in A
/// Space Complexity: O(n * len(s))
class Solution {

public:
    int numSpecialEquivGroups(vector<string>& A) {

        unordered_set<string> groups;
        for(const string& s: A)
            groups.insert(getHashCode(s));
        return groups.size();
    }

private:
    string getHashCode(const string& s){
        vector<int> freq(52, 0);
        for(int i = 0; i < s.size(); i ++)
            freq[(i % 2) * 26 + (s[i] - 'a')] ++;

        return getFreqString(freq);
    }

    string getFreqString(const vector<int>& freq){

        string res = "";
        for(int e: freq)
            res += to_string(e) + " ";
        return res;
    }
};


int main() {

    vector<string> A1 = {"a","b","c","a","c","c"};
    cout << Solution().numSpecialEquivGroups(A1) << endl;
    // 3

    vector<string> A2 = {"aa","bb","ab","ba"};
    cout << Solution().numSpecialEquivGroups(A2) << endl;
    // 4

    vector<string> A3 = {"abc","acb","bac","bca","cab","cba"};
    cout << Solution().numSpecialEquivGroups(A3) << endl;
    // 3

    vector<string> A4 = {"abcd","cdab","adcb","cbad"};
    cout << Solution().numSpecialEquivGroups(A4) << endl;
    // 1

    return 0;
}