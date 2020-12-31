/// Source : https://leetcode.com/problems/find-common-characters/
/// Author : liuyubobobo
/// Time   : 2019-03-03

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Sorting and using C++ STL set_intersection :-)
/// Time Complexity: O(n * ave_len_of_strings)
/// Space Complexity: O(ave_len_of_strings)
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {

        for(string& s: A) sort(s.begin(), s.end());

        string res = A[0];
        for(int i = 1; i < A.size(); i ++){
            string cur(max(res.size(), A[i].size()), ' ');
            string::iterator iter = set_intersection(res.begin(), res.end(), A[i].begin(), A[i].end(), cur.begin());
            while(cur.size() && cur.back() == ' ') cur.pop_back();
            res = cur;
        }

        vector<string> ret;
        for(char c: res)
            ret.push_back(string(1, c));
        return ret;
    }
};


void print_vec(const vector<string>& vec){
    for(const string& s: vec) cout << s << " ";
    cout << endl;
}

int main() {

    vector<string> A1 = {"bella","label","roller"};
    print_vec(Solution().commonChars(A1));

    return 0;
}