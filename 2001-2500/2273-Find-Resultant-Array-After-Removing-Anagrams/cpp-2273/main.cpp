/// Source : https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
/// Author : liuyubobobo
/// Time   : 2022-05-15

#include <iostream>
#include <vector>

using namespace std;


/// Stack
/// Time Complexity: O(n * |word|)
/// Space Complexity: O(1)
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {

        vector<string> res;
        for(const string& word: words)
            if(res.empty() || !same(word, res.back())) res.push_back(word);
        return res;
    }

private:
    bool same(string a, string b){
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }
};


int main() {

    return 0;
}
