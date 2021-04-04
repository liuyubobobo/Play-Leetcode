/// Source : https://leetcode.com/problems/sentence-similarity-iii/
/// Author : liuyubobobo
/// Time   : 2021-04-04

#include <iostream>
#include <vector>

using namespace std;


/// Two Pointers
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {

        if(s1 == s2) return true;

        vector<string> v1 = get_vector(s1), v2 = get_vector(s2);

        if(v1.size() < v2.size()) swap(v1, v2);

        int l1 = 0, r1 = v1.size() - 1, l2 = 0, r2 = v2.size() - 1;
        while(l2 < v2.size() && l1 < v1.size() && v1[l1] == v2[l2]) l1 ++, l2 ++;
        while(r2 >= 0 && r1 >= 0 && v1[r1] == v2[r2]) r1 --, r2 --;
        return l2 > r2;
    }

private:
    vector<string> get_vector(const string& s){

        vector<string> v;
        for(int start = 0, i = start + 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] == ' '){
                v.push_back(s.substr(start, i - start));
                start = i + 1;
                i = start;
            }
        return v;
    }
};


int main() {

    cout << Solution().areSentencesSimilar("CwFfRo regR", "CwFfRo H regR") << endl;
    // 1

    cout << Solution().areSentencesSimilar("Eating right now", "Eating") << endl;
    // 1

    return 0;
}
