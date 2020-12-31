/// Source : https://leetcode.com/problems/find-common-characters/
/// Author : liuyubobobo
/// Time   : 2019-03-03

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


/// Using MultiSet to get the intersection of every two strings
/// Time Complexity: O(n * ave_len_of_strings * log(ave_len_of_strings))
/// Space Complexity: O(n * ave_len_of_strings)
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {

        vector<multiset<char>> sets(A.size());
        for(int i = 0; i < A.size(); i ++)
            for(char c: A[i])
                sets[i].insert(c);

        multiset<char> res = sets[0];
        for(int i = 1; i < sets.size(); i ++)
            res = intersection(res, sets[i]);

        vector<string> ret;
        for(char c: res)
            ret.push_back(string(1, c));
        return ret;
    }

private:
    multiset<char> intersection(multiset<char>& set1, multiset<char>& set2){

        multiset<char> res;
        for(char c: set1){
            multiset<char>::iterator iter = set2.find(c);
            if(iter != set2.end())
                res.insert(c), set2.erase(iter);
        }
        return res;
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