/// Source : https://leetcode.com/problems/string-matching-in-an-array/
/// Author : liuyubobobo
/// Time   : 2020-04-11

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2 * |word|)
/// Space Complexity: O(1)
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {

        vector<string> res;
        for(int i = 0; i < words.size(); i ++){

            for(int j = 0; j < words.size(); j ++)
                if(i != j){
                    if(words[i].size() <= words[j].size() && words[j].find(words[i]) != string::npos){
                        res.push_back(words[i]);
                        break;
                    }
                }
        }
        return res;
    }
};


void print_vec(const vector<string>& vec){
    for(const string& e: vec) cout << e << " "; cout << endl;
}

int main() {

    vector<string> words1 = {"mass","as","hero","superhero"};
    print_vec(Solution().stringMatching(words1));

    return 0;
}