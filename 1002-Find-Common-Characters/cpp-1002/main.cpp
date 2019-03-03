/// Source : https://leetcode.com/problems/find-common-characters/
/// Author : liuyubobobo
/// Time   : 2019-03-02

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Sorting every string
/// Using two pointers technique to get the intersection of every two strings
/// Time Complexity: O(n * ave_len_of_strings)
/// Space Complexity: O(ave_len_of_strings)
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {

        for(string& s: A) sort(s.begin(), s.end());

        string res = A[0];
        for(int i = 1; i < A.size(); i ++)
            res = intersection(res, A[i]);

        vector<string> ret;
        for(char c: res)
            ret.push_back(string(1, c));
        return ret;
    }

private:
    string intersection(const string& s1, const string& s2){

        int i1 = 0, i2 = 0;
        string res = "";
        while(i1 < s1.size() && i2 < s2.size())
            if(s1[i1] == s2[i2])
                res += s1[i1], i1 ++, i2 ++;
            else if(s1[i1] < s2[i2])
                i1 ++;
            else
                i2 ++;
        return res;
    }
};


int main() {

    return 0;
}